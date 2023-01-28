#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#24 Swap Nodes in Pairs
Attempt 1: 
Use a vector<ListNode*> to store even index node
Each of the ptr is responsible for its next
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
    ListNode* swapPairs(ListNode* head) {
        // Locate even index
        int index = 0;
        vector<ListNode*> nodeVec;
        ListNode* traverse = head;

        // Check head
        if (head == nullptr) {
            return head;
        } else if (head->next != nullptr) {
            head = head->next;
        }

        while (traverse != nullptr) {
            if (index % 2 == 0) {
                nodeVec.push_back(traverse);
            }
            traverse = traverse->next;
            index++;
        }

        for (int i = 0; i < nodeVec.size(); i++) {
            if (nodeVec[i]->next != nullptr) {
                nodeVec[i]->next->next = nodeVec[i];
            } 

            if (i != nodeVec.size() - 1) {
                // Not the last one
                if (nodeVec[i + 1]->next != nullptr) {
                    nodeVec[i]->next = nodeVec[i + 1]->next;
                } else {
                    nodeVec[i]->next = nodeVec[i + 1];
                }
            } else {
                nodeVec[i]->next = nullptr;
            }
        }
        return head;
    }
};

void output(ListNode* head) {
    if (head == nullptr) {
        cout << "[]\n" ;
        return;
    }

    cout << "[";
    ListNode* traverse = head;
    while (traverse->next != nullptr) {
        cout << traverse->val << ",";
        traverse = traverse->next;
    }
    cout << traverse->val << "]\n";
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
    int arr1[] = {1,2,3,4};
    int arr2[] = {};
    int arr3[] = {1};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));

    Solution solution;
    output(solution.swapPairs(createList(input1)));
    output(solution.swapPairs(createList(input2)));
    output(solution.swapPairs(createList(input3)));

}