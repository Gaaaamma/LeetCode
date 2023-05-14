#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#21 Merge Two Sorted List
Attempt 1: 
Two pointers

Q: You are given the heads of two sorted linked lists list1 and list2.
   Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
   Return the head of the merged linked list.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* result = new ListNode(INT_MIN);
        ListNode* traverseR = result;
        ListNode* traverseA = list1;
        ListNode* traverseB = list2;

        while (traverseA != nullptr && traverseB != nullptr) {
            if (traverseA->val <= traverseB->val) {
                traverseR->next = traverseA;
                traverseA = traverseA->next;
            } else {
                traverseR->next = traverseB;
                traverseB = traverseB->next;
            }
            traverseR = traverseR->next;
        }
        if (traverseA) traverseR->next = traverseA;
        if (traverseB) traverseR->next = traverseB;

        // Delete dummy head
        ListNode* tmp = result->next;
        delete(result);
        return tmp;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
}
