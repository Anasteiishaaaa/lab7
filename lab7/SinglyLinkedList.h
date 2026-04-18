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

	bool isEmpty() const {
		return length == 0;
	}

	size_t size() const {
		return length;
	}

	void push_front(const T& value) {
		auto newNode = std::make_shared<Node<T>>(value);
		newNode->next = head;
		head = newNode;
		length++;
	}

	void push_back(const T& value) {
		auto newNode = std::make_shared<Node<T>>(value);
		if (isEmpty()) {
			head = newNode;
		}
		else {
			auto current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
		length++;
	}
};