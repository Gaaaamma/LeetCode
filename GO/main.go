package main

import (
	"fmt"
	"gaaaamma/tree"
)

func main() {
	testInt := []int{0, 1, tree.Null, 3, tree.Null, 4, tree.Null, 5, 6}
	root := tree.CreateBinaryTree(testInt)
	tree.GenerateGraph(root)
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
