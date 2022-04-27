#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "thread_utils.hpp"

using namespace std;

void test_thread_pool(){
    std::cout<<"Main thread is "<<std::this_thread::get_id()<<std::endl;
    named_thread_pool pool("prefix",5);
    boost::asio::post(pool.get_executor(), [](){
        std::cout<<"Thread in "<<std::this_thread::get_id()<<std::endl;
    });
    boost::asio::post(pool.get_executor(), [](){
        while(1){
        std::cout<<"Thread in "<<std::this_thread::get_id()<<std::endl;
        }
    });
    while (1);    
}

#if 0
boost::asio::io_service ios3;
//boost::asio::io_service::work work3(ios3);
boost::asio::ip::tcp::endpoint endpoint3(boost::asio::ip::tcp::v4(), 8090); 
boost::asio::ip::tcp::acceptor acceptor3(ios3, endpoint3);
boost::asio::ip::tcp::socket sock3(ios3);
extern void accept_handler(const boost::system::error_code &ec);
string data3="HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
void write_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) 
{
    if(!ec){
        cout<<"write end."<<endl;
    }
} 
void accept_handler(const boost::system::error_code &ec){
    if(!ec){
        cout<<"accept handler in"<<endl;
        boost::asio::async_write(sock3, boost::asio::buffer(data3),write_handler);
    }
}
void test_asio_webserver(){
    acceptor3.listen();
    acceptor3.async_accept(sock3,accept_handler);
    ios3.run();
}
#endif

#if 0
boost::asio::io_service ios2;
boost::asio::ip::tcp::resolver resolver2(ios2);
boost::asio::ip::tcp::socket socket2(ios2);
boost::array<char, 4096> buff2;
void read_handler(const boost::system::error_code &ec, std::size_t bytes_transfer){
    if(!ec){
        cout<<"read ok"<<endl;
        cout<<string(buff2.data(),bytes_transfer)<<endl;
    }
}
void connect_handler(const boost::system::error_code &ec){
    if(!ec){
        cout<<"connect ok"<<endl;
        //boost::asio::write(socket2, boost::asio::buffer("GET / HTTP/1.1\r\nHost: highscore.de\r\n\r\n"));
        boost::asio::write(socket2, boost::asio::buffer("GET / HTTP/1.1\r\nHost: baidu.com\r\n\r\n"));
        //boost::asio::write(socket2, boost::asio::buffer("GET http://www.baidu.com/index.html HTTP/1.1\n"));
        socket2.async_read_some(boost::asio::buffer(buff2), read_handler);
    }
}
void resolverHandler2(const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator it){
    if(!ec){
        cout<<"resolverHandler2 ok"<<endl;
        socket2.async_connect(*it, connect_handler);
    }
}
void test_asio_query(void){
    //boost::asio::ip::tcp::resolver::query query("www.highscore.de", "80");
    boost::asio::ip::tcp::resolver::query query("www.baidu.com", "80");
    resolver2.async_resolve(query,resolverHandler2);
    ios2.run();
}
#endif

//server sync
void test_server_sync(){
    try{
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),3200));
        while(1){
            boost::asio::ip::tcp::socket socket(io_service);
            acceptor.accept(socket);
            time_t now=time(0);
            string message=ctime(&now);
            boost::system::error_code ignore_error;
            socket.write_some(boost::asio::buffer(message),ignore_error);
        }
    }
    catch(std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }
}

//server async
void process_client(shared_ptr<boost::asio::ip::tcp::socket> client){
    time_t now=time(0);
    shared_ptr<string> message(new string(ctime(&now)));
    auto callback = [=](const boost::system::error_code &err, size_t size){
        if((uint)size == message->length()){
            cout<<"write completed"<<endl;
        }
    };
    client->async_send(boost::asio::buffer(*message),callback);
}
typedef function<void (const boost::system::error_code&)> accept_callback;
void start_accept(boost::asio::ip::tcp::acceptor &acceptor){
    //注意：1.66的版本不支持，会报错
    // shared_ptr<boost::asio::ip::tcp::socket> client(new boost::asio::ip::tcp::socket(acceptor.get_executor()));
    // accept_callback callback=[&acceptor,client](const boost::system::error_code &error){
    //     if(!error){
    //         std::cout<<"callback in"<<std::endl;
    //         process_client(client);
    //     }
    //     start_accept(acceptor);
    // };
    // acceptor.async_accept(*client,callback);
}
void test_server_async(){
    try{
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),3200));
        start_accept(acceptor);
        io_service.run();
    }
    catch(std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }
}

//clent
void test_client(){
    try{
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::endpoint end_point(boost::asio::ip::address::from_string("127.0.0.1"), 3200);
        boost::asio::ip::tcp::socket socket(io_service);
        socket.connect(end_point);
        while(1){
            boost::array<char,128>buf;
            boost::system::error_code error;
            size_t len=socket.read_some(boost::asio::buffer(buf),error);
            if(error==boost::asio::error::eof){
                cout<<"Connection closed cleanly by peer";
                break;
            }
            else if(error){
                throw boost::system::system_error(error);
            }
            std::cout.write(buf.data(),len);
        }
    }
    catch(std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }
}

//deadline timer
void Print(const boost::system::error_code &ec)
{
    cout<<"Hello World!"<<endl;
    cout<<boost::this_thread::get_id()<<endl;
}
void test_deadline_timer(){
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    t.async_wait(Print);
    io.run();
}

//deadline timer2
void handler(const boost::system::error_code &ec){
    cout<<"5 s get"<<endl;
}
void handler2(const boost::system::error_code &ec){
    cout<<"10 s get"<<endl;
}
boost::asio::io_service ios1;
void run(void){
    ios1.run();
}
void test_deadline_timer2(){
    boost::asio::deadline_timer timer(ios1, boost::posix_time::seconds(5));
    timer.async_wait(handler);
    boost::asio::deadline_timer timer2(ios1, boost::posix_time::seconds(10));
    timer2.async_wait(handler2);
    boost::thread thread1(run);
    boost::thread thread2(run);
    thread1.join();
    thread2.join();
}

void test_asio()
{
    cout<<"asio test start."<<endl;
    //test_deadline_timer();
    //test_deadline_timer2();
    //test_client();
    //test_server_sync();
    //test_server_async();
    //test_asio_query();
    //test_asio_webserver();
    //test_thread_pool();
}