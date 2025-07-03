package main

import (
	"bytes"
	"fmt"
	"log"
	"os/exec"
	"time"
)

func executeShellCommand(command string) (string, string, error) {
	// 使用 exec.Command 创建一个命令
	cmd := exec.Command("bash", "-c", command)

	// 用 bytes.Buffer 捕获标准输出和标准错误
	var stdout, stderr bytes.Buffer
	cmd.Stdout = &stdout
	cmd.Stderr = &stderr

	// 执行命令
	err := cmd.Run()

	// 返回标准输出，标准错误和错误信息
	return stdout.String(), stderr.String(), err
}

func main() {
	// 示例：执行一个命令，例如 "ls -l"
	command := "p=2; if [ \"$p\" -eq 1 ]; then echo \"p 等于 1\"; else echo \"p 不等于 1\"; fi" // 直接使用命令 "ls"，不需要额外参数

	fmt.Printf("time1:%v", time.Now().UnixNano())
	stdout, stderr, err := executeShellCommand(command) // 直接在命令字符串里加入参数
	if err != nil {
		log.Fatalf("命令执行失败：%v\n标准错误输出：%s\n", err, stderr)
	} else {
		fmt.Println("命令执行成功！")
		fmt.Println("标准输出：")
		fmt.Println(stdout)
	}
	fmt.Printf("time2:%v", time.Now().UnixNano())
}
