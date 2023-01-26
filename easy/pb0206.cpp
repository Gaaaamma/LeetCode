#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#206 Reverse Linked List
Attempt 1: 
Just traverse the linked list and reverse it
Complexity: O(N)
*/     

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode* left = head;
        ListNode* right = left->next;
        left->next = NULL;
        ListNode* next = NULL;
        while (right != NULL) {
            next = right->next;
            right->next = left;
            left = right;
            right = next;
        }

        return left;
    }
};

void output(ListNode* head) {
    ListNode* checker = head;

    if (checker == NULL) {
        cout << "[]\n";
        return; 
    }

    cout << "[";
    while (checker != NULL) {
        if (checker->next == NULL) {
            cout << checker->val << "]\n";
            break;
        } else {
            cout << checker->val << ",";
            checker = checker->next;
        }
    }
    
}

ListNode* createList(vector<int> nums) {
    if (nums.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(nums.back());
    for (int i = nums.size() - 2; i >= 0; i--) {
        ListNode* tmp = new ListNode(nums[i], head);
        head = tmp;
    }
    return head;
}

int main(int argc, char* argv[]){
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1};
    int arr3[] = {};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    
    Solution solution;

    output(solution.reverseList(createList(input1)));
    output(solution.reverseList(createList(input2)));
    output(solution.reverseList(createList(input3)));
}