package main

import (
	"fmt"

	"fff"
)

func main() {
	var numbers []int
	printSlice(numbers)

	/* 允许追加空切片 */
	numbers = append(numbers, 0)
	printSlice(numbers)
	Show()
	printSlice(numbers)
	fff.Showf()
	fff.Showf()
}

func printSlice(x []int) {
	fmt.Printf("len=%d cap=%d slice=%v\n", len(x), cap(x), x)
}
