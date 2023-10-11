#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef> // for size_t

template<typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // Member functions
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (empty()) {
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
        num_items++;
    }

    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (empty()) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        num_items++;
    }

    void pop_front() {
        if (!empty()) {
            Node* old_head = head;
            head = head->next;
            delete old_head;
            num_items--;
        }
    }

    void pop_back() {
        if (!empty()) {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            current->next = nullptr;
            num_items--;
        }
    }

    Item_Type& front() const {
        return head->data;
    }

    Item_Type& back() const {
        return tail->data;
    }

    bool empty() const {
        return head == nullptr;
    }

    void insert(size_t index, const Item_Type& item) {
        if (index >= num_items) {
            push_back(item);
            return;
        }

        Node* new_node = new Node(item);
        if (index == 0) {
            new_node->next = head;
            head = new_node;
        }
        else {
            Node* current = head;
            for (size_t i = 1; i < index; i++) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
        num_items++;
    }

    bool remove(size_t index) {
        if (index >= num_items) {
            return false;
        }

        if (index == 0) {
            pop_front();
        }
        else {
            Node* current = head;
            for (size_t i = 1; i < index; i++) {
                current = current->next;
            }
            Node* to_delete = current->next;
            current->next = to_delete->next;
            delete to_delete;

            if (index == num_items - 1) {
                tail = current;
            }
            num_items--;
        }
        return true;
    }

    size_t find(const Item_Type& item) const {
        Node* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == item) {
                return index;
            }
            current = current->next;
            index++;
        }
        return num_items;  // return size of the list if not found
    }

    size_t size() const {
        return num_items;
    }
};

#endif

