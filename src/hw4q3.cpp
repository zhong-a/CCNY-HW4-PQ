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
    for (index; index < used; index = nextIndex(index)) {
        data[index] = source.data[index];
    }
}

template <class Item>
PriorityQueue<Item>::~PriorityQueue() {
    delete[] data;
}


#endif
