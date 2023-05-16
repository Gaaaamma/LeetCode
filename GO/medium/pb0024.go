package medium

import "gaaaamma/list"

/*
#24 Swap Nodes in Pairs

Q: Given a linked list, swap every two adjacent nodes and return its head.
   You must solve the problem without modifying the values in the list's nodes
   (i.e., only nodes themselves may be changed.)
*/

/*
* Definition for singly-linked list.
* type ListNode struct {
*     Val int
*     Next *ListNode
* }
 */

func SwapPairs(head *list.ListNode) *list.ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	result := head.Next
	left := head
	right := head.Next

	for {
		keep := right.Next
		right.Next = left
		if keep == nil || keep.Next == nil {
			left.Next = keep
			break
		} else {
			left.Next = keep.Next
			right = keep.Next
			left = keep
		}
	}
	return result
}
