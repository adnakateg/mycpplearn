#pragma once

#include <iostream>
#include <limits>

namespace dst::queue {
template <typename T> class Node {
public:
  Node(T _value) : m_value(_value) {}

  T m_value{};
  Node *m_next = nullptr;
};

template <typename T> class Queue {
public:
  Queue(T _value) {
    Node<T> *node = new Node<T>(_value);
    m_first = node;
    m_last = node;
    m_length++;
  }

  T getFirst() {
    if (m_first) {
      Node<T> *temp = m_first;
      return temp->m_value;
    }
    return std::numeric_limits<T>::max();
  }

  T getLast() {
    if (m_last) {
      Node<T> *temp = m_last;
      return temp->m_value;
    }
    return std::numeric_limits<T>::max();
  }

  const size_t getLength() const { return m_length; }

  void enqueue(T _value) {
    Node<T> *node = new Node<T>(_value);
    if (m_first && m_last) {
      m_last->m_next = node;
      m_last = m_last->m_next;
    } else {
      m_first = node;
      m_last = node;
    }
    m_length++;
  }

  T dequeue() {
    T val;
    if (m_first && m_last) {
      val = m_first->m_value;

      Node<T> *tmp = m_first;
      m_first = m_first->m_next;
    } else {
      val = std::numeric_limits<T>::max();
    }
    m_length--;
    if (m_length == 0) {
      m_last = nullptr;
    }
    return val;
  }

private:
  Node<T> *m_first = nullptr;
  Node<T> *m_last = nullptr;
  size_t m_length{};
};

} // namespace dst::queue
