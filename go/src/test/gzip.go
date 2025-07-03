package main

import (
	"bytes"
	"compress/gzip"
	"encoding/hex"
	"fmt"
	"io/ioutil"
)

func main() {
	// 原始数据
	originalData := []byte("Hello, World! This is a gzip compression test. 你好，世界！")
	fmt.Printf("原始数据:\n长度: %d 字节\n内容: %s\n\n", len(originalData), originalData)

	// 压缩数据
	compressed, err := Gzip(originalData)
	if err != nil {
		panic(err)
	}
	fmt.Printf("压缩后数据:\n长度: %d 字节\nHex: %x\n\n", len(compressed), compressed[:8]) // 只显示前8字节的hex

	// 给定的十六进制数据流
	hexData := "1f8b08000000000000ff1cc4410a80500884e1bbfc6b03c79e095e2dba7b309bef255905622f05c56670db63db3e76584dab2b4ff5f7070000fffff660fac33b000000"

	// 将十六进制字符串解码为字节切片
	compressed, err = hex.DecodeString(hexData)
	if err != nil {
		fmt.Println("十六进制解码失败:", err)
		return
	}
	// 解压数据
	decompressed, err := UnGzip(compressed)
	if err != nil {
		panic(err)
	}
	fmt.Printf("解压后数据:\n长度: %d 字节\n内容: %s\n\n", len(decompressed), decompressed)

	// 验证结果
	fmt.Printf("验证结果: %v\n", bytes.Equal(originalData, decompressed))
}

func Gzip(data []byte) ([]byte, error) {
	var buf bytes.Buffer
	w := gzip.NewWriter(&buf)

	_, err := w.Write(data)
	if err != nil {
		return nil, err
	}
	if err := w.Close(); err != nil {
		return nil, err
	}
	return buf.Bytes(), nil
}

func UnGzip(data []byte) ([]byte, error) {
	buf := bytes.NewBuffer(data)
	r, err := gzip.NewReader(buf)
	if err != nil {
		return nil, err
	}
	defer r.Close()

	result, err := ioutil.ReadAll(r)
	if err != nil {
		return nil, err
	}
	return result, nil
}
