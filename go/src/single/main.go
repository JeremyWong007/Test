package main

import "fmt"

type Books struct {
	title   string
	author  string
	subject string
	book_id int
}

func main() {
	//fmt.Print("Hello go!")
	// a := 12
	// b := 13
	str := "Hello go2\n"
	fmt.Print(str)
	fmt.Printf(str)

	b := Books{"Go 语言", "www.runoob.com", "Go 语言教程", 6495407}
	fmt.Println(b)
	SayHello()
}
