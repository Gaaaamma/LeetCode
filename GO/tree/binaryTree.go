package tree

import (
	"fmt"
)

const (
	Null             = -1
	GraphMaximumNode = 31
)

type TreeNode struct {
	val   int
	left  *TreeNode
	right *TreeNode
}

func CreateBinaryTree(input []int) *TreeNode {
	if len(input) == 0 {
		return nil
	}
	root := &TreeNode{input[0], nil, nil}
	treeQue := []*TreeNode{root}
	first := true
	for i := 1; i < len(input); i++ {
		if input[i] == Null {
			if !first {
				treeQue = treeQue[1:]
			}
		} else {
			if first {
				treeQue[0].left = &TreeNode{input[i], nil, nil}
				treeQue = append(treeQue, treeQue[0].left)
			} else {
				treeQue[0].right = &TreeNode{input[i], nil, nil}
				treeQue = append(treeQue, treeQue[0].right)
				treeQue = treeQue[1:]
			}
		}
		first = !first
	}
	return root
}

func Inorder(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	Inorder(root.left, result)
	*result = append(*result, root.val)
	Inorder(root.right, result)
}

func Preorder(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	*result = append(*result, root.val)
	Preorder(root.left, result)
	Preorder(root.right, result)
}

func Postorder(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	Postorder(root.left, result)
	Postorder(root.right, result)
	*result = append(*result, root.val)
}

func Levelorder(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	treeQue := []*TreeNode{root}
	for len(treeQue) > 0 {
		if treeQue[0].left != nil {
			treeQue = append(treeQue, treeQue[0].left)
		}
		if treeQue[0].right != nil {
			treeQue = append(treeQue, treeQue[0].right)
		}
		*result = append(*result, treeQue[0].val)
		treeQue = treeQue[1:]
	}
}

func GenerateGraph(root *TreeNode) {
	fmt.Printf("================= Tree =================(%d)\n", GraphMaximumNode)
	space := gainIndexSpace()
	treeQue := []*TreeNode{root}
	counter := 0
	for len(treeQue) > 0 {
		levelCount := len(treeQue)
		for i := 0; i < levelCount; i++ {
			printSpace(space[counter])
			if treeQue[0] == nil {
				fmt.Printf(" ")
				if counter*2+1 < GraphMaximumNode {
					treeQue = append(treeQue, nil)
					treeQue = append(treeQue, nil)
				}
			} else {
				fmt.Printf("%d", treeQue[0].val)
				if counter*2+1 < GraphMaximumNode {
					treeQue = append(treeQue, treeQue[0].left)
					treeQue = append(treeQue, treeQue[0].right)
				}
			}
			treeQue = treeQue[1:]
			counter++
		}
		fmt.Println("")
	}
	fmt.Printf("========================================(%d)\n", GraphMaximumNode)
}

func gainIndexSpace() map[int]int {
	space := make(map[int]int)
	space[0], space[1], space[2], space[3], space[4],
		space[5], space[6], space[7], space[8], space[9],
		space[10], space[11], space[12], space[13], space[14],
		space[15], space[16], space[17], space[18], space[19],
		space[20], space[21], space[22], space[23], space[24],
		space[25], space[26], space[27], space[28], space[29],
		space[30] = 19, 10, 16, 5, 8, 8, 8, 3, 3, 4, 3, 4, 3, 4, 3, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1
	return space
}

func printSpace(count int) {
	for count > 0 {
		fmt.Printf(" ")
		count--
	}
}

/*
0123456789ABCDEFabcdef0123456789ABCDEFabcdef
                   2
          2                2
     1        2        3        4
   0   0    0   0    0   0    0   0
  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0

  0: 19
  1: 10
  2: 16
  3: 5
  4: 8
  5: 8
  6: 8
  7: 3
  8: 3
  9: 4
  10: 3
  11: 4
  12: 3
  13: 4
  14: 3
  15: 2
  16: 1
  17: 1
  18: 1
  19: 2
  20: 1
  21: 1
  22: 1
  23: 2
  24: 1
  25: 1
  26: 1
  27: 2
  28: 1
  29: 1
  30: 1
*/
