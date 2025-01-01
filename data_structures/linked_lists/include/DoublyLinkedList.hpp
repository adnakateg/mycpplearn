#pragma once

#include <iostream>
using std::cout;

namespace dst::dbll {
template <typename T> class Node {
public:
  Node(T _value) {
    m_prev = nullptr;
    m_next = nullptr;
    m_value = _value;
  }

  Node *m_prev = nullptr;
  Node *m_next = nullptr;
  T m_value{};
};

template <typename T> class DoublyLinkedList {
public:
  DoublyLinkedList(T _value) {
    Node<T> *node = new Node<T>(_value);
    m_head = node;
    m_tail = node;
    m_length = 1;
  }

  virtual ~DoublyLinkedList() {
    if (m_head) {
      Node<T> *tmpNode = m_head;
      while (tmpNode) {
        m_head = m_head->m_next;
        delete tmpNode;
        tmpNode = m_head;
      }
    }
  }
  void printList() {
    Node<T> *current = m_head;
    while (current) {
      cout << current->m_value << "  ";
      current = current->m_next;
    }
    cout << "\n";
  }

  Node<T> *getHead() { return m_head; }
  Node<T> *getTail() { return m_tail; }
  size_t getLength() { return m_length; }

  void append(T _value) {
    Node<T> *newNode = new Node<T>(_value);
    m_length++;
    if (m_head && m_tail) {
      m_tail->m_next = newNode;
      newNode->m_prev = m_tail;
      m_tail = newNode;
    } else {
      m_head = newNode;
      m_tail = newNode;
    }
  }

  void deleteLast() {
    if (m_head) {
      if (m_head != m_tail) {
        Node<T> *temp = m_tail;
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
        delete temp;
      } else {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
      }
      m_length--;
    }
  }

  void prepend(T _value) {
    Node<T> *newNode = new Node<T>(_value);
    if (m_head) {
      m_head->m_prev = newNode;
      newNode->m_next = m_head;
      m_head = newNode;
    } else {
      m_head = newNode;
      m_tail = newNode;
    }
    m_length++;
  }

  void deleteFirst() {
    /* Edge cases
     * 1) empty list
     * 2) single element list
     */
    if (m_head == m_tail) {
      if (m_head) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_length--;
      }
    } else {
      Node<T> *tmp = m_head;
      m_head = m_head->m_next;
      m_head->m_prev = nullptr;
      delete tmp;
      m_length--;
    }
  }

  Node<T> *get(size_t _index) {
    if (_index < 0 || _index >= m_length) {
      return nullptr;
    }
    Node<T> *tmp = nullptr;
    if (_index < m_length / 2) {
      tmp = m_head;
      for (size_t i = 0; i < _index; ++i) {
        tmp = tmp->m_next;
      }
    } else {
      tmp = m_tail;
      for (size_t i = m_length - 1; i > _index; --i) {
        tmp = tmp->m_prev;
      }
    }
    return tmp;
  }

  bool set(size_t _index, T _value) {
    Node<T> *entry = get(_index);
    if (entry) {
      entry->m_value = _value;
      return true;
    } else {
      return false;
    }
  }

  bool insert(size_t _index, T _value) {
    if (_index < 0 || _index > m_length) {
      return false;
    }
    if (_index == 0) {
      prepend(_value);
    } else if (_index == m_length) {
      append(_value);
    } else {
      Node<T> *newNode = new Node<T>(_value);
      Node<T> *before = get(_index - 1);
      Node<T> *after = before->m_next;

      newNode->m_prev = before;
      newNode->m_next = after;
      before->m_next = newNode;
      after->m_prev = newNode;
      m_length++;
    }
    return true;
  }

  void deleteNode(size_t _index) {
    if (_index < 0 || _index >= m_length) {
      return;
    }
    if (_index == 0) {
      deleteFirst();
    } else if (_index == m_length - 1) {
      deleteLast();
    } else {
      Node<T> *delNode = get(_index);
      Node<T> *prev = delNode->m_prev;
      Node<T> *next = delNode->m_next;
      prev->m_next = next;
      next->m_prev = prev;
      delete delNode;
      m_length--;
    }
  }

private:
  Node<T> *m_head = nullptr;
  Node<T> *m_tail = nullptr;
  size_t m_length{};
};
} // namespace dst::dbll
