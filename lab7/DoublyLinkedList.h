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

    bool is_empty() const { 
        return length == 0; 
    }

    size_t size() const {
        return length; 
    }

    void push_front(const T& val) {
        auto newNode = std::make_shared<Node<T>>(val);
        if (is_empty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void push_back(const T& val) {
        auto newNode = std::make_shared<Node<T>>(val);
        if (is_empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void pop_front() {
        if (is_empty()) throw std::runtime_error("List is empty");
        if (length == 1) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev.reset();
        }
        length--;
    }

    void pop_back() {
        if (is_empty()) throw std::runtime_error("List is empty");
        if (length == 1) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev.lock();
            tail->next = nullptr;
        }
        length--;
    }

    T& at(size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        auto current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void insert_at(size_t index, const T& val) {
        if (index > length) throw std::out_of_range("Index out of range");
        if (index == 0) {
            push_front(val);
        }
        else if (index == length) {
            push_back(val);
        }
        else {
            auto newNode = std::make_shared<Node<T>>(val);
            auto current = head;
            for (size_t i = 0; i < index; i++) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev.lock()->next = newNode;
            current->prev = newNode;
            length++;
        }
    }

    void remove_at(size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        if (index == 0) {
            pop_front();
        }
        else if (index == length - 1) {
            pop_back();
        }
        else {
            auto current = head;
            for (size_t i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev.lock()->next = current->next;
            current->next->prev = current->prev;
            length--;
        }
    }

    int find(const T& val) const {
        auto current = head;
        int index = 0;
        while (current) {
            if (current->data == val) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
        auto current = list.head;
        os << "NULL <-> ";
        while (current) {
            os << current->data << " <-> ";
            current = current->next;
        }
        os << "NULL";
        return os;
    }
};