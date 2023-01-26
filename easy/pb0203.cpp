#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#203 Remove Linked List Elements
Attempt 1: 
Simple remove element from list
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = NULL;
        ListNode* traverse = NULL;
        while (head != NULL) {
            if (head->val != val) {
                ListNode* tmp = new ListNode(head->val);
                if (result != NULL) {
                    traverse->next = tmp;
                    traverse = traverse->next;
                } else {
                    result = tmp;
                    traverse = result;
                }
            }
            head = head->next;
        }
        return result;
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
    int arr1[] = {1,2,6,3,4,5,6};
    int arr2[] = {};
    int arr3[] = {7,7,7,7};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    
    Solution solution;

    output(solution.removeElements(createList(input1), 6));
    output(solution.removeElements(createList(input2), 1));
    output(solution.removeElements(createList(input3), 7));
}