package main

import (
	"fmt"
	"os"
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
	for {
		// write 4 * 8 bytes to fifo
		//fmt.Println("Writing to FIFO...")
		//token := make([]byte, 32) // 32 bytes = 256 bits
		//rand.Read(token)
		fifo.WriteString("ТУПОСЧЁТ\n") // Write 32 random bytes
		//time.Sleep(100 * time.Millisecond)
	}
}
