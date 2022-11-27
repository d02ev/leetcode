#include <iostream>
using namespace std;

struct Node {
    int _data;
    Node* next_node;
    Node(int data): _data(data), next_node(nullptr) {}
};

Node* HEADNODE = nullptr;

void insertBack(int data) {
    Node* new_node = new Node(data);

    if (HEADNODE == nullptr) {
        HEADNODE = new_node;
        return;
    }

    Node* temp = HEADNODE;

    while (temp -> next_node != nullptr) {
        temp = temp -> next_node;
    }

    temp -> next_node = new_node;
    return;
}

Node* middleNode() {
    if (HEADNODE -> next_node == nullptr) {
        return HEADNODE;
    }

    Node *slow_ptr = HEADNODE, *fast_ptr = HEADNODE;

    while (fast_ptr != nullptr and fast_ptr -> next_node != nullptr) { 
        slow_ptr = slow_ptr -> next_node;
        fast_ptr = fast_ptr -> next_node -> next_node;
    }

    return slow_ptr;
}

int main(int argc, char** argv) {
    insertBack(1);
    insertBack(2);
    insertBack(3);
    insertBack(4);
    insertBack(5);
    insertBack(6);
    insertBack(7);
    insertBack(8);

    cout << middleNode() -> _data << endl;  // 5

    return 0;
}