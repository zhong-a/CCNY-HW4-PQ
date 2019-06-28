#ifndef __HW4Q3_CPP__
#define __HW4Q3_CPP__

#include "hw4q3.h"

template <class Item>
PriorityQueue<Item>::PriorityQueue() {
    capacity = DEF_CAP;
    first = 0;
    last = 0;
    used = 0;
    data = new Item[capacity];
}

template <class Item>
PriorityQueue<Item>::PriorityQueue(const PriorityQueue<Item>& source) {
    capacity = source.capacity;
    first = source.first;
    last = source.last;
    used = source.used;
    size_t index = first;
    data = new Item[capacity];
    for (int i = 0; i < used; i++) {
        data[index] = source.data[index];
        index = nextIndex(index);
    }
}

template <class Item>
PriorityQueue<Item>::~PriorityQueue() {
    delete[] data;
}

template <class Item>
void PriorityQueue<Item>::push(const Item& entry) {
    if (used == capacity) {
        return;
    }
    if (used == 0) {
        data[0] = entry;
        last = nextIndex(last);
        used++;
        return;
    }
    data[last] = entry;
    size_t index = prevIndex(last);
    Item holder;
    while (index != prevIndex(first) && data[index] > data[nextIndex(index)]) {
        holder = data[index];
        data[index] = data[nextIndex(index)];
        data[nextIndex(index)] = holder;
        index = prevIndex(index);
    }
    used++;
    last = nextIndex(last);
}

template <class Item>
void PriorityQueue<Item>::pop() {
    if (used < 1) {
        return;
    }
    first = nextIndex(first);
    used--;
}

template <class Item>
void PriorityQueue<Item>::operator=(const PriorityQueue<Item>& source) {
    this->capacity = source.capacity;
    this->used = source.used;
    this->first = source.first;
    this->last = source.last;
    for (int i = first; i != last; i = nextIndex(i)) {
        this->data[i] = source.data[i];
    }
}

template <class Item>
size_t PriorityQueue<Item>::size() const {
    return used;
}

template <class Item>
bool PriorityQueue<Item>::empty() const {
    return (used == 0);
}

template <class Item>
Item PriorityQueue<Item>::front() const {
    return data[first];
}
#endif
