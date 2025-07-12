package main

import (
	"fmt"
	"os/exec"
	"time"
)

func main() {
	cmd := exec.Command("./piodisp")
	piodispIn, _ := cmd.StdinPipe()
	ticker := time.NewTicker(1 * time.Second)
	defer ticker.Stop()
	for {
		<-ticker.C // Wait for the next tick
		tid := time.Now().Format("15:04:05")
		cmd.Start()
		piodispIn.Write([]byte(tid))

		fmt.Println(tid)

	}
}
