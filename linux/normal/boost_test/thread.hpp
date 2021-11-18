#include <boost/asio/io_context.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>
#include <boost/asio.hpp>
#include <thread>
#include <iostream>
#include <sstream>

class named_thread_pool {
   public:
      // name_prefix is name appended with -## of thread.
      // short name_prefix (6 chars or under) is recommended as console_appender uses 9 chars for thread name
      named_thread_pool( std::string name_prefix, size_t num_threads )
      :_thread_pool(num_threads)
      //, _ioc(num_threads)
      {
         for(int i=0;i<4;i++){
               boost::asio::post( _thread_pool, [](){
                  std::stringstream s;
                  s<<std::string("thread id is ")<<std::this_thread::get_id();
                  std::cout<<s.str()<<std::endl;
                  std::cout<<"std::thread::hardware_concurrency(): "<<std::thread::hardware_concurrency()<<std::endl;
            });
         }
      };

      // calls stop()
      ~named_thread_pool(){
         _thread_pool.join();
         _thread_pool.stop();
         //_ioc.stop();
      };

      //boost::asio::io_context& get_executor() { return _ioc; }

      // destroy work guard, stop io_context, join thread_pool, and stop thread_pool
      void stop();

   private:
      using ioc_work_t = boost::asio::executor_work_guard<boost::asio::io_context::executor_type>;

      boost::asio::thread_pool       _thread_pool;
      //boost::asio::io_context        _ioc;
      //std::optional<ioc_work_t>       _ioc_work;
   };