package main

import (
	"fmt"
	"gaaaamma/list"
	"gaaaamma/medium"
)

type Input struct {
	nums []int
}

func main() {
	input := []Input{{[]int{1, 2, 3}}, {[]int{1, 2, 3, 4}}, {[]int{1, 2, 3, 4, 5, 6}}}
	for _, item := range input {
		fmt.Printf("Init: ")
		root := list.CreateList(item.nums)
		list.Traverse(root)

		fmt.Printf("After: ")
		root = medium.SwapPairs(root)
		list.Traverse(root)
		fmt.Println()
	}
}
