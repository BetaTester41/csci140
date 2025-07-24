#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    void traverseRecursive(Node* node) const {
        if (!node) return;
        std::cout << node->data << " ";
        traverseRecursive(node->next);
    }

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void traverse() const {
        traverseRecursive(head);
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.traverse(); // Output: 3 2 1
    return 0;
}
