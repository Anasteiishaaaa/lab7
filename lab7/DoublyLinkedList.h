#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    size_t length;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}
};