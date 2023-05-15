package main

import (
	"fmt"
	"gaaaamma/tree"
)

func main() {
	testInt := []int{5, 3, 7, 1, tree.Null, tree.Null, 9}
	root := tree.CreateBinaryTree(testInt)
	result := []int{}
	tree.Inorder(root, &result)
	fmt.Println(result)

	result = []int{}
	tree.Preorder(root, &result)
	fmt.Println(result)

	result = []int{}
	tree.Postorder(root, &result)
	fmt.Println(result)

	result = []int{}
	tree.Levelorder(root, &result)
	fmt.Println(result)
}
