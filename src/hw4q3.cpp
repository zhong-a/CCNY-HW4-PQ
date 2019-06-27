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
    data[nextIndex(last)] = entry;
    size_t index = last;
    Item holder;
    size_t iter = 0;
    while (data[index] > data[nextIndex(index)]) {
        if (nextIndex(index) == first) {
            break;
        }
        holder = data[index];
        data[index] = data[nextIndex(index)];
        data[nextIndex(index)] = holder;
        index = prevIndex(index);
    }
}


#endif
