#pragma once

#include <iostream>
#include <limits>

namespace dst::stack {
template <typename T> class Node {
public:
  Node(T _value) : m_value(_value) {}

  T m_value{};
  Node *m_next = nullptr;
};

template <typename T> class Stack {
public:
  Stack(T _value) {
    Node<T> *node = new Node<T>(_value);
    m_top = node;
    m_height++;
  }

  void push(T _value) {
    Node<T> *node = new Node<T>(_value);
    node->m_next = m_top;
    m_top = node;
    m_height++;
  }

  T pop() {
    if (m_top) {
      Node<T> *temp = m_top;
      T val = temp->m_value;

      m_top = m_top->m_next;
      delete temp;
      m_height--;
      return val;
    }
    return std::numeric_limits<T>::max();
  }

  const size_t getHeight() const { return m_height; }

private:
  Node<T> *m_top = nullptr;
  size_t m_height{};
};

} // namespace dst::stack
