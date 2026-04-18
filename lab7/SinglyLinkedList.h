#pragma once
#include <iostream>
#include "Node.h"
#include <stdexcept>
template <typename T>
class SinglyLinkedList {
private:
	std::shared_ptr<Node<T>> head;
	size_t length;
public:
	SinglyLinkedList() : head(nullptr), length(0) {}
};