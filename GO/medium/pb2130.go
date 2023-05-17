package medium

import "gaaaamma/list"

/*
#2130 Maximum Twin Sum of a Linked List

Q: In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list
   is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

    - For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2.
	  These are the only nodes with twins for n = 4.

   The twin sum is defined as the sum of a node and its twin.
   Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/

/*
* Definition for singly-linked list.
* type ListNode struct {
*     Val int
*     Next *ListNode
* }
 */

func PairSum(head *list.ListNode) int {
	nums := make([]int, 0, 100000)
	traverse := head
	for traverse != nil {
		nums = append(nums, traverse.Val)
		traverse = traverse.Next
	}
	left, right := 0, len(nums)-1
	max := 0
	for left < right {
		sum := nums[left] + nums[right]
		if sum > max {
			max = sum
		}
		left++
		right--
	}
	return max
}
