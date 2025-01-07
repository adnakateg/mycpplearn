#pragma once

namespace dst::tree {
template <typename T> class Node {
public:
  T m_value{};
  Node *m_left = nullptr;
  Node *m_right = nullptr;
  Node(T _value) { m_value = _value; }
  bool operator<(const Node &other) const { return m_value < other.m_value; }
  bool operator==(const Node &other) const { return m_value == other.m_value; }
  bool operator>(const Node &other) const { return m_value > other.m_value; }
};

template <typename T> class BST {
public:
  BST() { m_root = nullptr; }

  bool insert(T _value) {
    Node<T> *node = new Node(_value);
    if (m_root) {
      Node<T> *temp = m_root;
      while (true) {
        if (*node == *temp) {
          return false;
        }
        if (*node < *temp) {
          if (temp->m_left) {
            temp = temp->m_left;
            continue;
          }
          temp->m_left = node;
          break;
        } else {
          if (temp->m_right) {
            temp = temp->m_right;
            continue;
          }
          temp->m_right = node;
          break;
        }
      }
    } else {
      m_root = node;
    }
    return true;
  }

  bool contains(T _value) {
    Node<T> *temp = m_root;
    while (temp) {
      if (temp->m_value == _value) {
        return true;
      }
      if (temp->m_value > _value) {
        temp = temp->m_left;
      } else {
        temp = temp->m_right;
      }
    }
    return false;
  }

  bool remove(T _value) {
    Node<T> *temp = m_root;

    while (temp) {
      if (temp->m_value == _value) {
        break;
      }
      if (temp->m_value > _value) {
        temp = temp->m_left;
      } else {
        temp = temp->m_right;
      }
    }
    return false;
  }

  Node<T> *m_root = nullptr;
};
} // namespace dst::tree
