#include "list.h"
#include <stdexcept>

// === LinkedList core ===
LinkedList::LinkedList() = default;

LinkedList::LinkedList(const LinkedList& other) {
    head = deepCopy(other.head);
}

LinkedList& LinkedList::operator=(LinkedList rhs) {

    swap(head, rhs.head);
    return *this;
}

LinkedList::~LinkedList() { freeChain(head); }

void LinkedList::prepend(int value) {
    head = new Node{value, head};
}

void LinkedList::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

int LinkedList::removeFront() {
    if (isEmpty()) throw runtime_error("removeFront on empty list");
    int value = head->data;
    Node* firstHead = head;
    head = head->next;
    delete firstHead;
    return value;

}

bool LinkedList::isEmpty() const { return head == nullptr; }

void LinkedList::print(ostream& out) const {
    out << '[';
    for (Node* cur = head; cur; cur = cur->next) {
        out << cur->data;
        if (cur->next) out << " → ";
    }
    out << ']';
}

// === private helpers ===
LinkedList::Node* LinkedList::deepCopy(Node* src) {
    if (src == nullptr)
    {
        return nullptr;
    }
    Node* newNode = new Node{src->data, nullptr};
    newNode->next = deepCopy(src->next);
    return newNode;
}

void LinkedList::freeChain(Node* n) {
    while ( n ) {
        Node* next = n->next;
        delete n;
        n = next;
    }
}
