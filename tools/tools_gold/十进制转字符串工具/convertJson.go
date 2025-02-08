package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {
	// 打开out.txt文件
	inFile, err := os.Open("out.txt")
	if err != nil {
		log.Fatalf("Error opening input file: %v", err)
	}
	defer inFile.Close()

	// 读取文件内容
	fileContent, err := ioutil.ReadAll(inFile)
	if err != nil {
		log.Fatalf("Error reading input file: %v", err)
	}

	// 创建一个空的interface{}类型来存储JSON数据
	var data interface{}

	// 将读取到的内容解析为JSON格式
	err = json.Unmarshal(fileContent, &data)
	if err != nil {
		log.Fatalf("Error unmarshalling JSON: %v", err)
	}

	// 打开或创建outJson.txt文件用于输出
	outFile, err := os.Create("outJson.txt")
	if err != nil {
		log.Fatalf("Error creating output file: %v", err)
	}
	defer outFile.Close()

	// 格式化JSON数据并写入到outJson.txt文件
	prettyJSON, err := json.MarshalIndent(data, "", "  ")
	if err != nil {
		log.Fatalf("Error marshalling JSON: %v", err)
	}

	_, err = outFile.Write(prettyJSON)
	if err != nil {
		log.Fatalf("Error writing to output file: %v", err)
	}

	// 输出成功提示
	fmt.Println("Successfully wrote formatted JSON to outJson.txt")
}
