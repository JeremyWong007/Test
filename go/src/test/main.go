package main

import (
	"encoding/binary"
	"fmt"
	"log"
	"math"
	"os"
	"sa/fetch"
	"time"

	"github.com/wonderivan/logger"
)

func testTime() {
	str := "20240625"
	t, _ := time.Parse("20060102", str)
	GetHistoryTimestamp := t.Unix()
	fmt.Println("GetHistoryTimestamp = ", GetHistoryTimestamp)
}

func convertShortToBytes(a int16) (b []byte) {
	num := int16(a) // 要转换的短整数
	byteArray := make([]byte, 2)
	binary.LittleEndian.PutUint16(byteArray, uint16(num))
	return byteArray
}
func IntToByte(a int32) (b []byte) {
	num := a // 要转换的整数
	byteArray := make([]byte, 4)
	binary.LittleEndian.PutUint32(byteArray, uint32(num))
	//logger.Trace("byteArray: ", byteArray) // 打印字节数组
	return byteArray
}
func stringToByte(str string) (b []byte) {
	// 将字符串转换为字节序列
	bytes := []byte(str)

	// 补齐为32字节
	for len(bytes) < 32 {
		bytes = append(bytes, 0)
	}

	return bytes
}

// 通信协议校验和域计算参考
func getChecksum(data []byte) int {
	var sum int
	for i := 10; i < len(data)-1; i++ { //2字节长度在后面才加入
		if 0xff == data[i] {
			sum += -1
		} else {
			sum += int(data[i])
		}

	}
	sum = sum % 127

	logger.Trace("校验和域：", sum)
	return int(sum)
}

func testMqttXj() {
	var b []byte
	b = append(b, convertShortToBytes(int16(22))...) //起始域
	//b = append(b, convertShortToBytes(int16(158))...) //长度域
	b = append(b, []byte{0x03, 0x01, 0x00, 0x01}...) //版本域
	//序列号域
	var current int32 = 123
	b = append(b, IntToByte(current)...) //序列号域

	b = append(b, convertShortToBytes(int16(21001))...) //命令代码
	t := "14_0000700UQZ24914"
	encoding := "14_00006054ZH97433"
	b = append(b, stringToByte(t)...)        //智能终端编码
	b = append(b, stringToByte(encoding)...) //储能设备编码

	b = append(b, convertShortToBytes(int16(11000))...)
	b = append(b, IntToByte(01)...)

	//校验和域
	// 获取从第13个字节开始到最后一个字节的字节切片
	//slicedData := b[12:]
	checkSum := getChecksum(b)
	b = append(b, convertShortToBytes(int16(checkSum))...)

	Length := len(b) + 2
	newBytes := convertShortToBytes(int16(Length)) //长度域
	resultBytes := append(b, 0, 0)
	copy(resultBytes[4:], resultBytes[2:])
	copy(resultBytes[2:], newBytes)
	//b = append(b, convertShortToBytes(int16(14))...)

	fmt.Println("mqtt:", resultBytes)
	for i := 0; i < len(resultBytes); i++ {
		fmt.Printf("0x%x,", resultBytes[i])
	}
	fmt.Printf("\n")
}

type Test struct {
	A1 float32 `json:"a1"`
}

func ParseFloat(t Test) (string, error) {
	var s string
	// jsonBody, _ := json.Marshal(t)
	// s = string(jsonBody)
	//s = strconv.FormatFloat(float64(t.A1), 'g', 10, 32)

	t.A1 = float32(math.Round(float64(t.A1)*1000) / 1000)
	s = fmt.Sprintf("%v", t.A1)
	return s, nil
}

func testFloat() {
	fmt.Println("testStruct start:")
	var t Test
	t.A1 = 0.000
	jsonBody, _ := ParseFloat(t)
	fmt.Println("test1: ", string(jsonBody))

	t.A1 = 112233445566778899
	jsonBody, _ = ParseFloat(t)
	fmt.Println("test2: ", string(jsonBody))

	t.A1 = 1.123456789
	jsonBody, _ = ParseFloat(t)
	fmt.Println("test3: ", string(jsonBody))

	t.A1 = 123.123
	jsonBody, _ = ParseFloat(t)
	fmt.Println("test4: ", string(jsonBody))

	t.A1 = 112233.123
	jsonBody, _ = ParseFloat(t)
	fmt.Println("test5: ", string(jsonBody))

	t.A1 = 112233.11223344556677
	jsonBody, _ = ParseFloat(t)
	fmt.Println("test6: ", string(jsonBody))

}

func main() {
	fmt.Print("Hello World!\n")
	fetch.Hello()
	//Singing()

	fileName := "./logs/log.txt"
	file, err := os.Create(fileName)
	if err == nil {
		defer file.Close()
		log.SetOutput(file)
	}
	log.Println("Hello log!")

	testTime()
	testMqttXj()
	testFloat()
}
