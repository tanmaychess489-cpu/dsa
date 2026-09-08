#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode* prev;

};
ListNode* reverselist(ListNode* head) {
    ListNode* curr = head;
    ListNode* temp = nullptr;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    return temp->prev;
    
}
int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty.\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        ListNode* newNode = new ListNode();
        newNode->val = value;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    head = reverselist(head);
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

    
