#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_set>
using namespace std;

/*
#142 Linked List Cycle II
Attempt 1: 
Use unordered_set to check if there is loop in linked list
Complexity: O(N)

Q: Given the head of a linked list, return the node where the cycle begins. 
   If there is no cycle, return null.
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
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> unoset;
        ListNode* traverse = head;
        while (traverse != nullptr) {
            if (unoset.find(traverse) == unoset.end()) {
                // No find
                unoset.insert(traverse);
                traverse = traverse->next;
            } else {
                // find
                return traverse;
            }
        }
        return nullptr;
    }
};

void output(ListNode* head) {
    if (head == nullptr) {
        cout << "NULL\n";
    } else {
        cout << head->val << "\n";
    }
}

ListNode* createListWithCycle(vector<int> nums, int cycleIndex) {
    if (nums.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(nums.back());
    ListNode* tail = head;
    for (int i = nums.size() - 2; i >= 0; i--) {
        ListNode* tmp = new ListNode(nums[i], head);
        head = tmp;
    }

    // Create the cycle
    ListNode* traverse = head;
    while (cycleIndex) {
        traverse = traverse->next;
        if (traverse == nullptr) break;
        cycleIndex--;
    }

    if (cycleIndex == 0) {
        // valid cycleIndex
        tail->next = traverse;
    }
    return head;
}

int main(int argc, char* argv[]){
    int arr1[] = {3,2,0,-4};
    int arr2[] = {1,2};
    int arr3[] = {1};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));

    Solution solution;
    output(solution.detectCycle(createListWithCycle(input1, 1)));
    output(solution.detectCycle(createListWithCycle(input2, 0)));
    output(solution.detectCycle(createListWithCycle(input3, -1)));
}