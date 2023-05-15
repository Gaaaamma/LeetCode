package main

import (
	"fmt"
	"gaaaamma/list"
	"gaaaamma/medium"
)

type Input struct {
	nums []int
	k    int
}

func main() {
	input := []Input{{[]int{1, 2, 3, 4, 5}, 2}, {[]int{1}, 1}, {[]int{1, 2, 3}, 1}, {[]int{1, 2, 3}, 2}, {[]int{1, 2, 3}, 3}}
	for _, item := range input {
		fmt.Printf("Init:  ")
		root := list.CreateList(item.nums)
		list.Traverse(root)

		fmt.Printf("After: ")
		medium.SwapNodes(root, item.k)
		list.Traverse(root)
		fmt.Println()
	}
}
