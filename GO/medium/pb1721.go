package medium

import "gaaaamma/list"

/*
#1721 Swapping Nodes in a Linked List

Q: You are given the head of a linked list, and an integer k.
   Return the head of the linked list after swapping the values of the kth node
   from the beginning and the kth node from the end (the list is 1-indexed).
*/

/*
* Definition for singly-linked list.
* type ListNode struct {
*     Val int
*     Next *ListNode
* }
 */

func SwapNodes(head *list.ListNode, k int) *list.ListNode {
	front, slow, fast := head, head, head
	for i := 1; i < k; i++ {
		fast = fast.Next
	}
	front = fast
	for fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}

	front.Val, slow.Val = slow.Val, front.Val
	return head
}
