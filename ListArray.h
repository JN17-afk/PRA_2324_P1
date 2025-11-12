#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept> // std::out_of_range

template <typename T>
class ListArray {
private:
    T* arr;                  // Puntero al array de elementos
    int max;                 // Capacidad actual del array
    int n;                   // Número de elementos
    static const int MINSIZE = 2; // Capacidad mínima

    // Redimensiona el array a un nuevo tamaño
    void resize(int new_size) {
        if (new_size < MINSIZE)
            new_size = MINSIZE;

        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++)
            new_arr[i] = arr[i];

        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() : max(MINSIZE), n(0) {
        arr = new T[max];
    }

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Inserta el elemento e en la posición pos
    void insert(int pos, const T& e) {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida en insert()");
        if (n == max)
            resize(max * 2);

        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = e;
        n++;
    }

    // Inserta al final
    void append(const T& e) {
        insert(n, e);
    }

    // Inserta al principio
    void prepend(const T& e) {
        insert(0, e);
    }

    // Elimina y devuelve el elemento en la posición pos
    T remove(int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida en remove()");

        T removed = arr[pos];
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;

        if (n < max / 4 && max / 2 >= MINSIZE)
            resize(max / 2);

        return removed;
    }

    // Devuelve el elemento en la posición pos
    T get(int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida en get()");
        return arr[pos];
    }

    // Busca el primer elemento igual a e
    int search(const T& e) const {
        for (int i = 0; i < n; i++)
            if (arr[i] == e)
                return i;
        return -1;
    }

    // Indica si la lista está vacía
    bool empty() const {
        return n == 0;
    }

    // Devuelve el número de elementos
    int size() const {
        return n;
    }
};

#endif
