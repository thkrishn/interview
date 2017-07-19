package main

import (
	"fmt"
	"math/rand"
)

type Tree struct {
	Left *Tree
	Right * Tree
	Value int
}

func Walk (t *Tree, ch chan int){
	if t == nil{return}

	Walk(t.Left,ch)
	ch<-t.Value
	Walk(t.Right,ch)
}

func Printtree (t *Tree){
        if t == nil{return}

        Printtree(t.Left)
        fmt.Printf("%d \t",t.Value)
        Printtree(t.Right)
}

func Walker(t *Tree) <-chan int{
	ch:= make(chan int)
	go func () {
		Walk(t,ch)
		close(ch)
	}()
	return ch
}

func BFS_print (t2 *Tree) {
	if t2 == nil {return}
	queue := make([]*Tree, 0)
	queue = append(queue,t2)
	queue = append(queue, nil)

	for len(queue) != 0 {
		t1 := queue[0]
		queue = queue[1:]

		if t1 != nil{
			fmt.Printf(" %v ", t1.Value)
			if t1.Left != nil {
				queue = append(queue, t1.Left)
			}

			if t1.Right != nil {
                                queue = append(queue, t1.Right)
                        }
		} else {
			if len(queue) != 0 {
			fmt.Printf("\n")
			queue = append(queue, nil)
			}
		}
	}
}

func New (n,k int) *Tree {
	var t* Tree
	for _,v := range rand.Perm(n){
		t = insert((1+v)*k, t)
	}
	return t
}

func insert (n int, t *Tree) *Tree {
	if t == nil {
		return &Tree{nil,nil,n}
	}

	if n < t.Value {
		t.Left = insert(n,t.Left)
		return t
	}

	t.Right = insert(n, t.Right)
	return t
}

func main() {
	t1 := New(10,1)
	c2 := Walker(t1)
	fmt.Println(len(c2))
	fmt.Println("\n")
	for i := range c2 {
          fmt.Println(i)
	}

	Printtree(t1)
	fmt.Printf("\n \n")
        BFS_print(t1)

	fmt.Println(t1.Value)
	fmt.Println(t1.Left.Value)
	fmt.Println(t1.Right)
}
