package main

import (
	"fmt"
	"net"
)

func main() {
	listener, err := net.Listen("tcp", "192.168.11.172:50000")
	//listener, err := net.Listen("tcp", "10.10.10.101:50000")
	if err != nil {
		fmt.Println("Error listening:", err.Error())
		return
	}
	defer listener.Close()

	fmt.Println("Waiting for connections...")

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Error accepting:", err.Error())
			continue
		}

		go handleConnection(conn)
	}
}

func handleConnection(conn net.Conn) {
	defer conn.Close()

	buffer := make([]byte, 51200)
	n, err := conn.Read(buffer)
	if err != nil {
		fmt.Println("Error reading:", err.Error())
		return
	}
	fmt.Printf("Server received length:%d\n", n)
	fmt.Printf("Server received message:%s\n", buffer[:n])

	_, err = conn.Write(buffer[:n])
	if err != nil {
		fmt.Println("Error writing:", err.Error())
		return
	}
}
