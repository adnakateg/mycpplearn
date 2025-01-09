#pragma once
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>

namespace dst::hash {

template <auto THashFnc, size_t SIZE = 7, typename TKey = std::string,
          typename TValue = int>
class HashTable {
private:
  class Node {
  public:
    Node(TKey _key, TValue _value) : m_key(_key), m_value(_value) {}

    TKey m_key{};
    TValue m_value{};
    Node *m_next = nullptr;
  };
  Node *m_table[SIZE];

  auto hash(TKey _key) { return THashFnc(_key); }

public:
  HashTable() {
    for (size_t i = 0; i < SIZE; ++i) {
      m_table[i] = nullptr;
    }
  }
  auto set(TKey _key, TValue _value) {
    auto hashIdx = hash(_key);
    Node *node = new Node(_key, _value);
    if (m_table[hashIdx]) {
      Node *temp = m_table[hashIdx];
      while (temp->m_next) {
        temp = temp->m_next;
      }
      temp->m_next = node;
    } else {
      m_table[hashIdx] = node;
    }
    return hashIdx;
  }

  TValue get(TKey _key, TValue _null) {
    auto hashIdx = hash(_key);
    Node *temp = m_table[hashIdx];
    while (temp) {
      if (temp->m_key == _key) {
        return temp->m_value;
      } else {
        temp = temp->m_next;
      }
    }
    return _null;
  }

  void printHash() {
    for (size_t i = 0; i < SIZE; i++) {
      Node *temp = m_table[i];
      std::cout << "[" << i << "]: ";
      while (temp) {
        std::cout << temp->m_value << "->";
        temp = temp->m_next;
      }
      std::cout << "nullptr\n";
    }
  }
};
} // namespace dst::hash
