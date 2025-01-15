#pragma once

#include <iostream>
#include <limits>
using std::cout;

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
  Node<T> *m_root = nullptr;

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

  bool r_contains(T _value) {
    cout << "\nRecursive search: " << _value << "\n";
    return rcontains(m_root, _value);
  }
  void r_insert(T _value) {
    cout << "\nRecursive insert: " << _value << "\n";
    if (m_root == nullptr) {
      m_root = new Node<T>(_value);
    } else {
      rinsert(m_root, _value);
    }
  }

  void deleteNode(T value) { m_root = deleteNode(m_root, value); }

  Node<T> *deleteNode(Node<T> *currentNode, int _value) {
    if (currentNode == nullptr) {
      return nullptr;
    }
    if (_value < currentNode->m_value) {
      currentNode = deleteNode(currentNode->m_left, _value);
    } else if (_value > currentNode->m_value) {
      currentNode = deleteNode(currentNode->m_right, _value);
    } else {
      if (currentNode->m_left == currentNode->m_right) { // leaf node
        delete (currentNode);
        return nullptr;
      } else if (currentNode->m_left == nullptr) {
        Node<T> *temp = currentNode->m_right;
        delete currentNode;
        return temp;
      } else if (currentNode->m_right == nullptr) {
        Node<T> *temp = currentNode->m_left;
        delete currentNode;
        return temp;
      } else {
        T subTreeMin = minValue(currentNode->m_right);
        currentNode->m_value = subTreeMin;
        currentNode->m_right = deleteNode(currentNode->m_right, subTreeMin);
      }
    }
    return currentNode;
  }

  T getMin() {
    Node<T> *node = m_root;
    T ret = std::numeric_limits<T>::max();
    while (node) {
      if ((node->m_left == nullptr) && (node->m_right == nullptr)) {
        ret = node->m_value;
        break;
      }
      if (node->m_left) {
        node = node->m_left;
      } else {
        node = node->m_right;
      }
    }
    return ret;
  }

  T getMax() {
    Node<T> *node = m_root;
    T ret = std::numeric_limits<T>::max();

    while (node) {
      if ((node->m_left == nullptr) && (node->m_right == nullptr)) {
        ret = node->m_value;
        break;
      }
      if (node->m_right) {
        node = node->m_right;
        continue;
      }
      if (node->m_left) {
        node = node->m_left;
      }
      return ret;
    }
  }
  T r_minValue(Node<T> *currentNode) {
    while (currentNode->m_left) {
      currentNode = currentNode->m_left;
    }
    return currentNode->m_value;
  }

private:
  bool rcontains(Node<T> *_node, T _value) {
    if (_node == nullptr) {
      cout << "NOTFOUND\n";
      return false;
    }
    if (_node->m_value == _value) {
      cout << "FOUND\n";
      return true;
    }
    if (_value < _node->m_value) {
      return rcontains(_node->m_left, _value);
    } else {
      return rcontains(_node->m_right, _value);
    }
  }

  Node<T> *rinsert(Node<T> *rnode, T _value) {
    if (rnode == nullptr) {
      return new Node<T>(_value);
    }
    if (_value < rnode->m_value) {
      rnode->m_left = rinsert(rnode->m_left, _value);
    } else {
      rnode->m_right = rinsert(rnode->m_right, _value);
    }
    return rnode;
  }
};
} // namespace dst::tree
