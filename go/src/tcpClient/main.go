package main

import (
	"fmt"
	"net"
)

func main() {
	conn, err := net.Dial("tcp", "192.168.11.172:50000")
	if err != nil {
		fmt.Println("Error dialing:", err.Error())
		return
	}
	defer conn.Close()

	_, err = conn.Write([]byte("Hello, server!"))
	if err != nil {
		fmt.Println("Error writing:", err.Error())
		return
	}

	buffer := make([]byte, 51200)
	n, err := conn.Read(buffer)
	if err != nil {
		fmt.Println("Error reading:", err.Error())
		return
	}

	fmt.Println("Client received message:", string(buffer[:n]))
}
