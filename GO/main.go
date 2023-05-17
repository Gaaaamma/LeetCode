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
	input := []Input{{[]int{1, 3, 4, 10}}, {[]int{1, 5, 7, 10}}, {[]int{1, 3, 4, 8, 8, 4, 3, 1}}}
	for _, item := range input {
		root := list.CreateList(item.nums)
		fmt.Printf("List: ")
		list.Traverse(root)
		fmt.Printf("Max pair sum: %d\n", medium.PairSum(root))
		fmt.Println()
	}
}
