package main

import (
	"fmt"
	"time"
)

func main() {

	ticker := time.NewTicker(1 * time.Second)
	defer ticker.Stop()
	for {
		<-ticker.C // Wait for the next tick
		tid := time.Now().Format("15:04:05")
		fmt.Println(tid)

	}
}
