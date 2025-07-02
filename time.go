package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	// Open FIFO (named pipe)
	fifoPath := "/tmp/myfifo"
	fifo, err := os.OpenFile(fifoPath, os.O_WRONLY, 0600)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Failed to open FIFO: %v\n", err)
		os.Exit(1)
	}
	defer fifo.Close()
	ticker := time.NewTicker(1 * time.Second)
	defer ticker.Stop()
	for {
		<-ticker.C // Wait for the next tick
		tid := time.Now().Format("15:04:05")
		fifo.WriteString(tid + "\n")
	}
}
