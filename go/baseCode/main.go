package main

import (
	"encoding/json"
	"fmt"
	"os"
	"os/exec"
	"strings"
	"time"
)

func IsFileExists(filename string) bool {
	_, err := os.Stat(filename)
	if err != nil {
		if os.IsNotExist(err) {
			return false
		}
	}
	return true
}

func Command(cmd string) (string, error) {
	c := exec.Command("bash", "-c", cmd)
	output, err := c.CombinedOutput()
	return string(output), err
}

type AlarmResult_S struct {
	alarm_id    int `json:"alarm_id"`
	standard_id int `json:"standard_id"`
	content     int `json:"content"`
	device      int `json:"device"`
	alarm       int `json:"alarm"` //报警为true,不报警为false
}

func main() {

	loc, _ := time.LoadLocation("Asia/Shanghai")
	startday, err := time.ParseInLocation(time.DateOnly, "2024-11-27", loc)
	if err == nil {
		fmt.Println("time:", startday.Format(time.DateTime), startday.Unix(), startday.Location())
	}

	startday, err = time.Parse(time.DateOnly, "2024-11-27")
	if err == nil {
		fmt.Println("time:", startday.Format(time.DateTime), startday.Unix(), startday.Location())
	}

	platList := strings.Split("DispatchPower_-1_-1_0.json", "_")
	fmt.Println("platList:", len(platList))
	fmt.Println("platList1:", platList[0])
	fmt.Println("platList2:", platList[1])
	fmt.Println("platList2:", platList[2])
	fmt.Println("platList2:", platList[3])

	str, err := Command("dpkg -l | grep yelp-xsl")
	fmt.Println("11:", str, err)
	//str, err = Command("ll")
	//fmt.Println("22:", str, err)

	alarmResult := AlarmResult_S{
		alarm_id:    11,
		standard_id: 22,
		content:     33,
		device:      44,
		alarm:       55,
	}

	// 返回json格式输出
	resultJSON, err := json.Marshal(alarmResult)
	fmt.Printf("resultJSON:%v, alarmResult:%v,err:%v\n", string(resultJSON), alarmResult, err)

}
