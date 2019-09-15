/**
 Author      : tejas
 Description : multi threaded file copy; 
               input file into output file

               Basic Testing done
**/

package main

import "fmt"
import "os"
import "io"

const readSize int = 8000
const seekSize int = 8000
const numThreads int = 4

func check(e error) {
    if e != nil {
        panic(e)
    }
}


func main() {

    argsWithProg := os.Args
    if len(argsWithProg) < 3 {
        fmt.Println("Please provide source AND destination")
        return
    }

    done := make(chan bool, numThreads)
    writeFile, err := os.Create(string(argsWithProg[2]))
    check(err)

    for i := 0; i < numThreads ; i+=1 {
        go readfile(i, done, writeFile)
        <- done
    }
}

func readfile(th int, done chan bool, writeFile *os.File) {
    f, err := os.Open(string(os.Args[1]))
    check(err)
   
    atLocation := int64(th*seekSize)
    nextRead := int64(numThreads * readSize)
    b1 := make([]byte, readSize)

    for {
        n1, err := f.ReadAt(b1, atLocation)
        if err == io.EOF {
            if n1 < readSize {
                writeFile.WriteAt(b1[:n1], atLocation)
                //fmt.Printf("%s",b1)
            }
            f.Close()
            done <- true
            return
        }
        check(err)

        //fmt.Printf("TH-%d bytes %d-%s\n", th, n1, b1)
        writeFile.WriteAt(b1, atLocation)
        atLocation += nextRead

    }
    f.Close()
    done <- true
}
