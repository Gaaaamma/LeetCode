#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#876 Middle of the Linked List
Attempt 1: 
Two pointers(slow fast)

Q: Given the head of a singly linked list, return the middle node of the linked list.
   If there are two middle nodes, return the second middle node.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next == nullptr) break;
            fast = fast->next;
        }
        return slow;
    }
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(INT_MIN);
    ListNode* traverse = head;
    for (int i = 0; i < nums.size(); i++) {
        traverse->next = new ListNode(nums[i]);
        traverse = traverse->next;
    }
    ListNode* tmp = head->next;
    delete(head);
    return tmp;
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,4,5}, {1,2,3,4,5,6,7,8}, {4}};
    for (int i = 0; i < input.size(); i++) {
        ListNode* middle = solution.middleNode(createList(input[i]));
        cout << middle->val << "\n";
    }
}
