package main

import (
	"fmt"
	"net"
	"os"
)

func main() {

	if len(os.Args) < 2 {
		fmt.Println("Usage:", os.Args[0], "[arguments]")
		return
	}

	//conn, err := net.Dial("tcp", "192.168.11.172:50000")
	conn, err := net.Dial("tcp", "222.175.39.26:50005")
	if err != nil {
		fmt.Println("Error dialing:", err.Error())
		return
	}
	defer conn.Close()

	fmt.Println("Client send message:", os.Args[1])
	_, err = conn.Write([]byte(os.Args[1]))
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
