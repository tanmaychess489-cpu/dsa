#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseCircularList(Node* head) {
    if (!head || head->next == head) {
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;
    Node* tail = head;

    while (curr->next != head) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    curr->next = prev;
    tail->next = curr;

    return curr;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data <<" "<< endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;


    head = reverseCircularList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}


