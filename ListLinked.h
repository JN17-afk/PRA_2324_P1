#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class ListLinked {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    void insert(int pos, const T& e) {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida en insert()");
        if (pos == 0)
            first = new Node<T>(e, first);
        else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(const T& e) {
        insert(n, e);
    }

    void prepend(const T& e) {
        insert(0, e);
    }

    T remove(int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida en remove()");
        Node<T>* target;
        T value;
        if (pos == 0) {
            target = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            target = prev->next;
            prev->next = target->next;
        }
        value = target->data;
        delete target;
        n--;
        return value;
    }

    T get(int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida en get()");
        Node<T>* current = first;
        for (int i = 0; i < pos; i++)
            current = current->next;
        return current->data;
    }

    int search(const T& e) const {
        Node<T>* current = first;
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
        return n == 0;
    }

    int size() const {
        return n;
    }

    T operator[](int pos) const {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        out << "[";
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr)
                out << ", ";
            current = current->next;
        }
        out << "]";
        return out;
    }
};

#endif


