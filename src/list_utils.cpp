#include "list_utils.h"
#include "list.h"

int length(const LinkedList& list) {
    int len = 0;
    LinkedList::Node* current = list.getHead();
    while (current!= nullptr)
    {
        len++;
        current = current->next;
    }
    return len;
}

int sum(const LinkedList& list) {
    int sum = 0;
    LinkedList::Node* current = list.getHead();
    while (current != nullptr)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

bool contains(const LinkedList& list, int k) {
    LinkedList::Node* current = list.getHead();
    while (current != nullptr) {
        if (current->data == k) return true;
        current = current->next;
    }
    return false;
}

void reverse(LinkedList& list) {
    LinkedList::Node* prev = nullptr;
    LinkedList::Node* curr = list.getHead();
    LinkedList::Node* next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list.setHead(prev);
}

int nthFromEnd(const LinkedList& list, int n) {
    int len = length(list);
    if (n < 0 || n >= len) {
        throw runtime_error("Invalid lenght!");
    }

    int posFromStart = len - n - 1;
    LinkedList::Node* current = list.getHead();
    for (int i = 0; i < posFromStart; i++) {
        current = current->next;
    }

    return current->data;
}
