#include <iostream>
#include <math.h>
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

void printList() {
    if (HEADNODE == nullptr) {
        return;
    }

    Node* temp = HEADNODE;

    while (temp != nullptr) {
        cout << temp -> _data << " ";
        temp = temp -> next_node;
    }

    cout << endl;
}

int listLength() {
    if (HEADNODE == nullptr) {
        return 0;
    }

    Node* temp = HEADNODE;
    int counter = 0;

    while (temp != nullptr) {
        ++counter;
        temp = temp -> next_node;
    }

    return counter;
}

int getDecimalValue() {
    Node* temp = HEADNODE;
    int decimal_val = 0, exponent = listLength();

    while (temp != nullptr) {
        decimal_val += (temp -> _data * pow(2, --exponent));
        temp = temp -> next_node;
    }

    return decimal_val;
}

int getDecimalValue1() {
    Node* temp = HEADNODE;
    int sum = 0;

    while (temp != nullptr) {
        sum *= 2;
        sum += temp -> _data;
        temp = temp -> next_node;
    }

    return sum;
}



int main(int argc, char** argv) {
    insertBack(1);
    insertBack(0);
    insertBack(1);

    cout << getDecimalValue() << endl;
    cout << getDecimalValue1() << endl;

    return 0;
}