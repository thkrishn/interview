package main

import (
	"fmt"
)

type Node struct {
	Next * Node
	Value int
}

func Walk (t *Node){
	if t == nil{return}
	temp := t
	for temp != nil{
	fmt.Printf(" %d", temp.Value)
	temp = temp.Next
	}

}
/*
func Printtree (t *Tree){
        if t == nil{return}

        Printtree(t.Left)
        fmt.Sprintf("%d \t",t.Value)
        Printtree(t.Right)
}

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

*/
func insert (t* Node, n int) *Node {

		return &Node{t,n}
}


func insertend (t* Node, n int) {

        if (t == nil){
		t =  &Node{nil,n}
	}
	temp := t
	for temp.Next != nil{
		temp = temp.Next
	}
	temp.Next = &Node{nil,n}
}

func main() {
	t1 := &Node{nil,0}
	t1 = insert(t1,1)
	t1 = insert(t1,2)
	t1 = insert(t1,3)
	t1 = insert(t1,4)
	t1 = insert(t1,5)
	t1 = insert(t1,6)
	t1 = insert(t1,7)
	t1 = insert(t1,9)
	t1 = insert(t1,1)

	t2 := &Node{nil,0}

	insertend(t2,1)
	insertend(t2,2)
	insertend(t2,3)
	insertend(t2,4)
	insertend(t2,5)
	insertend(t2,6)
	insertend(t2,7)
	insertend(t2,7)
	insertend(t2,8)


	Walk(t1)
	fmt.Printf("\n")
	Walk(t2)

	fmt.Printf("\n")


}
