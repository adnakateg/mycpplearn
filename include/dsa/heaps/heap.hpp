#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <limits>
#include <vector>
using std::cout;
using std::vector;

template <typename T> class Heap {
public:
  void insert(T value) {
    m_data.push_back(value);
    size_t current = m_data.size() - 1;

    while (current > 0) {
      if (m_data[current] < m_data[parent(current)]) {
        break;
      }
      swap(current, parent(current));
      current = parent(current);
    }
  }

  T root() {
    if (m_data.size()) {
      return m_data[0];
    }
    return std::numeric_limits<T>::max();
  }

  void printHeap() {
    cout << "\n[";
    for (const auto &e : m_data) {
      cout << e << " ";
    }
    cout << "]\n";
  }

  T remove() {
    if (m_data.empty()) {
      return std::numeric_limits<T>::max();
    }
    T maxVal = m_data.front();
    if (m_data.size() == 1) {
      m_data.pop_back();
    } else {
      m_data[0] = m_data.back();
      m_data.pop_back();
      sinkDown(0);
    }
    return maxVal;
  }

private:
  size_t leftLeaf(size_t index) { return (2 * index) + 1; }
  size_t rightLeaf(size_t index) { return (2 * index) + 2; }
  size_t parent(size_t index) { return (index - 1) / 2; }
  void swap(size_t index1, size_t index2) {
    std::swap(m_data[index1], m_data[index2]);
  }
  void sinkDown(size_t _index) {
    size_t index = _index;
    size_t maxIndex = index;
    while (true) {
      size_t left = leftLeaf(index);
      size_t right = rightLeaf(index);

      if (left < m_data.size() && m_data[left] > m_data[maxIndex]) {
        maxIndex = left;
      }
      if (right < m_data.size() && m_data[right] > m_data[maxIndex]) {
        maxIndex = right;
      }
      if (maxIndex != index) {
        swap(index, maxIndex);
        index = maxIndex;
      } else {
        return;
      }
    }
  }

  vector<T> m_data{};
};

TEST(heap_test, test01) {
  Heap<int> _heap;
  _heap.insert(99);
  _heap.insert(72);
  _heap.insert(61);
  _heap.insert(58);

  _heap.printHeap();
  EXPECT_EQ(_heap.root(), 99);
  _heap.insert(100);
  _heap.printHeap();
  EXPECT_EQ(_heap.root(), 100);
  _heap.insert(75);
  _heap.printHeap();

  _heap.insert(20);
  _heap.printHeap();
  _heap.insert(102);
  _heap.printHeap();

  EXPECT_EQ(_heap.root(), 102);
  _heap.remove();
  _heap.printHeap();
  EXPECT_EQ(_heap.root(), 100);
  _heap.remove();
  _heap.printHeap();
  EXPECT_EQ(_heap.root(), 99);
  _heap.remove();
  _heap.printHeap();
  EXPECT_EQ(_heap.root(), 75);
  _heap.remove();
  _heap.printHeap();
  EXPECT_EQ(_heap.root(), 72);
}
