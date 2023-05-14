#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#2 Add Two Numbers
Attempt 1: 
Use stack to solve

Q: You are given two non-empty linked lists representing two non-negative integers. 
   The digits are stored in reverse order, and each of their nodes contains a single digit. 
   Add the two numbers and return the sum as a linked list.
   You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* head = nullptr;
        ListNode* traverseA = l1;
        ListNode* traverseB = l2;
        
        int carry = 0;
        while (traverseA != nullptr || traverseB != nullptr) {
            int sum = 0;
            if (traverseA == nullptr) {
                sum = traverseB->val + carry;
                traverseB = traverseB->next;
            } else if (traverseB == nullptr) {
                sum = traverseA->val + carry;
                traverseA = traverseA->next;
            } else {
                sum = traverseA->val + traverseB->val + carry;
                traverseA = traverseA->next;
                traverseB = traverseB->next;
            }
            if (sum >= 10) carry = 1;
            else carry = 0;

            if (result == nullptr) {
                result = new ListNode(sum % 10);
                head = result;
            } else {
                head->next = new ListNode(sum % 10);
                head = head->next;
            }
        }
        if (carry == 1) head->next = new ListNode(1);
        return result;
    }
};

ListNode* createList(vector<int> nums) {
    ListNode* head = nullptr;
    ListNode* traverse = nullptr;
    for (int i = 0; i < nums.size(); i++) {
        if (head == nullptr) {
            head = new ListNode(nums[i]);
            traverse = head;
        } else {
            traverse->next = new ListNode(nums[i]);
            traverse = traverse->next;
        }
    }
    return head;
}
void show(ListNode* head) {
    ListNode* traverse = head;
    while (traverse != nullptr) {
        cout << traverse->val << " ";
        traverse = traverse->next;
    }
    cout << "\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, vector<int>>> input{{{2,4,3}, {5,6,4}}, {{0}, {0}}, {{9,9,9,9,9,9,9}, {9,9,9,9}}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.addTwoNumbers(createList(input[i].first), createList(input[i].second)));
    }
}