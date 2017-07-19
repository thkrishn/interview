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
        fmt.Sprintf("%d \t",t.Value)
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

func Compare (t1, t2 *Tree) bool{
	c1,c2 := Walker(t1),Walker(t2)
	for {
		v1, ok1 := <-c1
		v2, ok2 := <-c2
		if !ok1 || !ok2{
			return ok1 == ok2
		}
		if  v1 != v2  {break}
	}
	return false
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
}
