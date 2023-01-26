#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#707 Design Linked List
Attempt 1: 
Purely implement Linked List structure
Complexity: O(-)
*/

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

struct Node {
    int val;
    Node* next;
    
    Node() : val(0), next(NULL) {}
    Node(int val) : val(val), next(NULL) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

class MyLinkedList {
private:
    Node* head;
    int length;

public:
    MyLinkedList() : head(NULL), length(0) {}
    
    int get(int index) {
        int result = -1;
        int count = 0;
        
        if (index < 0) {
            return result;
        }

        Node* traverse = head;
        while (traverse != NULL && count != index) {
            traverse = traverse->next;
            count++;
        }

        if (traverse != NULL) {
            result = traverse->val;
        }

        return result;
    }
    
    void addAtHead(int val) {
        Node* tmp = new Node(val, head);
        head = tmp;
        length++;
    }
    
    void addAtTail(int val) {
        Node* tmp = new Node(val);

        if (head == NULL) {
            head = tmp;

        } else {
            Node* traverse = head;

            while (traverse->next != NULL) {
                traverse = traverse->next;
            }
            traverse->next = tmp;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);

        } else if (index == length) {
            addAtTail(val);

        } else if (index < length) {
            int count = 0;

            Node* traverse = head;
            while (count != index - 1) {
                traverse = traverse->next;
                count++;
            }
            
            Node* tmp = new Node(val, traverse->next);
            traverse->next = tmp;
            length++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < length) {
            // Create virtual head
            Node* virtualHead = new Node(-1, head);
            head = virtualHead;
            index += 1;

            int count = 0;
            Node* traverse = head;
            while (count != index - 1) {
                traverse = traverse->next;
                count++;
            }

            // delete
            Node* remove = traverse->next;
            traverse->next = traverse->next->next;
            delete(remove);
            length--;

            // Recover
            head = virtualHead->next;
            delete(virtualHead);
        }
    }

    void output() {
        Node* traverse = head;

        if (traverse == NULL) {
            cout << "[]\n";
        } else {
            cout << "[";
            while (traverse->next != NULL) {
                cout << traverse->val << ",";
                traverse = traverse->next;
            }
            cout << traverse->val << "]\n";
        }
    }
};

int main(int argc, char* argv[]){
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2);                     // linked list becomes 1->2->3
    cout << "Get(1): " << myLinkedList->get(1) << "\n"; // return 2
    myLinkedList->deleteAtIndex(1);                     // now the linked list is 1->3
    cout << "Get(1): " <<myLinkedList->get(1) << "\n";  // return 3

    myLinkedList->output();
}