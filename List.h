#ifndef LIST_H
#define LIST_H

#include <stdexcept>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;
    int length;

public:
    
    List() : head(nullptr), length(0) {}
    ~List() {
        while (!empty())
            remove(0);
    }

    
    void insert(int pos, const T& e) {
        if (pos < 0 || pos > length)
            throw std::out_of_range("Posición inválida en insert()");

        if (pos == 0)
            head = new Node(e, head);
        else {
            Node* prev = head;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            prev->next = new Node(e, prev->next);
        }
        length++;
    }

    void append(const T& e) {
        insert(length, e);
    }

    
    void prepend(const T& e) {
        insert(0, e);
    }

    
    T remove(int pos) {
        if (pos < 0 || pos >= length)
            throw std::out_of_range("Posición inválida en remove()");

        Node* target;
        T value;

        if (pos == 0) {
            target = head;
            head = head->next;
        } else {
            Node* prev = head;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            target = prev->next;
            prev->next = target->next;
        }

        value = target->data;
        delete target;
        length--;
        return value;
    }

    
    T get(int pos) const {
        if (pos < 0 || pos >= length)
            throw std::out_of_range("Posición inválida en get()");

        Node* current = head;
        for (int i = 0; i < pos; i++)
            current = current->next;
        return current->data;
    }

    
    int search(const T& e) const {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == e)
                return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    
    bool empty() const {
        return head == nullptr;
    }
};
#endif
