#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#160 Intersection of Two Linked Lists
Attempt 1: 
Modify the value to INT_MAT to check if there is insection in LinkedList (Not legal)
Complexity: O(n+m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<int> valA;
        ListNode* traverseA = headA;
        ListNode* traverseB = headB;
        while (traverseA != nullptr) {
            valA.push_back(traverseA->val);
            traverseA->val = INT_MAX;
            traverseA = traverseA->next;
        }

        while (traverseB != nullptr) {
            if (traverseB->val == INT_MAX) {
                break;
            }
            traverseB = traverseB->next;
        }

        traverseA = headA;
        for (int i = 0; i < valA.size(); i++) {
            traverseA->val = valA[i];
            traverseA = traverseA->next;
        }
        return traverseB;
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
}