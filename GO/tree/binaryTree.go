package tree

const Null = -1

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
