#pragma once

#include <iostream>

namespace dst::sll {

template <typename T> class Node {
private:
  T m_value{};
  Node *m_next = nullptr;
  Node(T value) {
    this->m_value = value;
    m_next = nullptr;
  }
};

template <typename T> class SinglyLinkedList {
private:
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;
  size_t length;

public:
  SinglyLinkedList(T _value) {
    Node<T> *newNode = new Node<T>(_value);
    head = newNode;
    length = 1;
  }

  ~SinglyLinkedList() {
    Node<T> *temp = head;
    while (head) {
      head = head->m_next;
      delete temp;
      temp = head;
    }
  }
};
} // namespace dst::sll
