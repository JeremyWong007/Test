package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// 创建日志文件并设置日志记录
	logFile, err := os.Create("program.log")
	if err != nil {
		fmt.Printf("Error creating log file: %v\n", err)
		return
	}
	defer logFile.Close()

	// 打开in.txt文件
	inFile, err := os.Open("in.txt")
	if err != nil {
		fmt.Printf("Error opening in.txt: %v\n", err)
		return
	}
	defer inFile.Close()

	// 创建或打开out.txt文件
	outFile, err := os.Create("out.txt")
	if err != nil {
		fmt.Printf("Error creating out.txt: %v\n", err)
		return
	}
	defer outFile.Close()

	// 设置Scanner的最大token大小，增加限制
	scanner := bufio.NewScanner(inFile)
	const maxTokenSize = 10 * 1024 * 1024 // 10MB, 可以根据需要调整
	scanner.Buffer(make([]byte, maxTokenSize), maxTokenSize)

	// 日志记录文件读取的开始
	fmt.Println("Start reading in.txt...")

	// 逐行读取in.txt文件
	lineNumber := 0
	for scanner.Scan() {
		lineNumber++
		// 读取每行数据并以空格为分隔符分割
		line := scanner.Text()
		decimals := strings.Fields(line) // 按空格分割

		// 转换每个十进制数为字符并拼接为字符串
		var result string
		for _, dec := range decimals {
			// 将每个十进制数转换为整数
			num, err := strconv.Atoi(dec)
			if err != nil {
				// 打印转换错误并跳过该数字
				fmt.Printf("Error converting decimal '%s' in line %d: %v\n", dec, lineNumber, err)
				continue
			}

			// 将十进制整数转换为字符
			result += string(rune(num))
		}

		// 将转换后的字符串写入out.txt
		_, err := outFile.WriteString(result + "\n")
		if err != nil {
			fmt.Printf("Error writing to out.txt in line %d: %v\n", lineNumber, err)
			return
		}

		// 每处理完一行记录日志
		fmt.Printf("Processed line %d: %s\n", lineNumber, result)

		// 写入日志文件
		logFile.WriteString(fmt.Sprintf("Processed line %d: %s\n", lineNumber, result))
	}

	// 检查Scanner是否有错误
	if err := scanner.Err(); err != nil {
		fmt.Printf("Error reading in.txt: %v\n", err)
		logFile.WriteString(fmt.Sprintf("Error reading in.txt: %v\n", err))
	}

	// 日志记录程序完成
	fmt.Println("Program finished processing.")
	logFile.WriteString("Program finished processing.\n")
}
