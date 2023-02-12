#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#24 Swap Nodes in Pairs
Attempt 2: 
traverse the linked list and swap the node step by step

Complexity: O(N)

Q: Given a linked list, swap every two adjacent nodes and return its head. 
   You must solve the problem without modifying the values in the list's nodes 
   (i.e., only nodes themselves may be changed.)
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
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* traverse = head;
        ListNode* right = traverse->next->next;
        head = head->next;

        while (right != nullptr) {
            traverse->next->next = traverse;
            if (right->next != nullptr) {
                traverse->next = right->next;
                traverse = right;
                right = right->next->next;
            } else {
                traverse->next = right;
                return head;
            }
        }
        traverse->next->next = traverse;
        traverse->next = nullptr;
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
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {};
    int arr3[] = {1};
    int arr4[] = {1,2};
    int arr5[] = {1,2,3};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    vector<int> input4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    vector<int> input5(arr5, arr5 + sizeof(arr5) / sizeof(int));

    Solution solution;
    output(solution.swapPairs(createList(input1)));
    output(solution.swapPairs(createList(input2)));
    output(solution.swapPairs(createList(input3)));
    output(solution.swapPairs(createList(input4)));
    output(solution.swapPairs(createList(input5)));

}