#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#148 Sort List
Attempt 1: 
Merge Sort

Q: Given the head of a linked list, return the list after sorting it in ascending order.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};

ListNode* createList(vector<int> nums) {
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

void show(ListNode* head) {
    if (head == nullptr) {
        cout << "nullptr\n";
        return;
    }
    ListNode* traverse = head;
    while (traverse != nullptr) {
        cout << traverse->val << " ";
        traverse = traverse->next;
    }
    cout << "\n";
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* middle = findMiddle(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(middle);
        
        ListNode* newHead = new ListNode(INT_MIN);
        ListNode* travH = newHead;
        ListNode* travL = left;
        ListNode* travR = right;
        while (travL != nullptr && travR != nullptr) {
            if (travL->val <= travR->val) {
                travH->next = travL;
                travH = travH->next;
                travL = travL->next;
            } else {
                travH->next = travR;
                travH = travH->next;
                travR = travR->next;
            }
        }
        if (travL == nullptr && travR != nullptr) travH->next = travR;
        if (travR == nullptr && travL != nullptr) travH->next = travL;

        ListNode* tmp = newHead->next;
        delete(newHead);
        return tmp;
    }
    ListNode* findMiddle(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode *prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast->next == nullptr) break;
            fast = fast->next;
        }
        prev->next = nullptr;
        return slow;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{2,5,4,4,6,1,3,7,8,9,3}, {1}, {}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.sortList(createList(input[i])));
    }
}