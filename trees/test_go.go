package main

import "fmt"

func main() {
    queue := make([]int, 0)
    // Push

    queue = append(queue, 1)
    // Top (just get next element, don't remove it)
    x := queue[0]

    // Discard top element
    fmt.Println(x)

    queue = queue[1:]
    // Is empty ?
    if len(queue) == 0 {
        fmt.Println("Queue is empty !")
    }
}
