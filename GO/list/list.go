package list

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func CreateList(input []int) *ListNode {
	if len(input) == 0 {
		return nil
	}
	root := &ListNode{input[0], nil}
	traverse := root
	for i := 1; i < len(input); i++ {
		traverse.Next = &ListNode{input[i], nil}
		traverse = traverse.Next
	}
	return root
}

func Traverse(root *ListNode) {
	if root == nil {
		fmt.Println("Empty List")
	}
	traverse := root
	for traverse != nil {
		fmt.Printf("%d ", traverse.Val)
		traverse = traverse.Next
	}
	fmt.Println()
}
