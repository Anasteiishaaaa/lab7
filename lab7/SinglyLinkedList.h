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


	void pop_front() {
		if (isEmpty()) {
			throw std::runtime_error("List is empty");
		}
		head = head->next;
		length--;
	}

	void pop_back() {
		if (isEmpty()) {
			throw std::runtime_error("List is empty");
		}
		if (length == 1) {
			head = nullptr;
		}
		else {
			auto current = head;
			while (current->next && current->next->next) {
				current = current->next;
			}
			current->next = nullptr;
		}
		length--;
	}

	T& at(size_t index) {
		if (index >= length) {
			throw std::out_of_range("Index out of range");
		}
		auto current = head;
		for (size_t i = 0; i < index; i++) {
			current = current->next;
		}
		return current->data;
	}

	void insert_at(size_t index, const T& val) {
		if (index > length) {
			throw std::out_of_range("Index out of range");
		}
		if (index == 0) {
			push_front(val);
			return;
		}
		auto newNode = std::make_shared<Node<T>>(val);
		auto current = head;
		for (size_t i = 0; i < index - 1; i++) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		length++;
	}

	void remove_at(size_t index) {
		if (index >= length) {
			throw std::out_of_range("Index out of range");
		}
		if (index == 0) {
			pop_front();
			return;
		}
		auto current = head;
		for (size_t i = 0; i < index - 1; i++) {
			current = current->next;
		}
		current->next = current->next->next;
		length--;
	}

	int find(const T& value) const {
		auto current = head;
		int index = 0;
		while (current) {
			if (current->data == value) {
				return index;
			}
			current = current->next;
			index++;
		}
		return -1;
	}

	friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& list) {
		auto current = list.head;
		while (current) {
			os << current->data << " -> ";
			current = current->next;
		}
		os << "nullptr";
		return os;
	}
};