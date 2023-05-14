#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#19 Remove Nth Node From End of List
Attempt 1: 
Use two pointer, one it to check if it is on the last Node
the other is for locate the node to be deleted
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* dummy = new ListNode(0, head); //dummy head
        ListNode* traverse = dummy;
        ListNode* remove = dummy;
        
        while (traverse->next != nullptr) {
            if (count >= n) {
                remove = remove->next;
            }
            traverse = traverse->next;
            count++;
        }

        // remove
        if (remove->next == head) {
            head = head->next;
            delete(remove->next);
        } else {
            ListNode* tmp = remove->next;
            remove->next = tmp->next;
            delete(tmp);
        }
        delete(dummy);
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
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1};
    int arr3[] = {1,2};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));

    Solution solution;
    output(solution.removeNthFromEnd(createList(input1), 2));
    output(solution.removeNthFromEnd(createList(input2), 1));
    output(solution.removeNthFromEnd(createList(input3), 1));
}