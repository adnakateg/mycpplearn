#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <unordered_set>
#include <vector>

using std::cout;
using std::unordered_set;
using std::vector;

vector<int> remove_duplicates(const vector<int> &myList) {
  vector<int> res{};
  unordered_set<int> uoSet{};

  for (const auto &e : myList) {
    if (uoSet.insert(e).second) {
      res.push_back(e);
    }
  }
  return res;
}

TEST(remove_duplicates_test, test01) {
  vector<int> inV = {1, 3, 2, 5, 4, 2, 1, 6, 3, 4, 6, 2, 7, 8, 0};

  auto res = remove_duplicates(inV);
  auto printVec = [](const auto &_vec) {
    for (const auto &e : _vec) {
      cout << e << " ";
    }
    cout << "\n";
  };

  cout << "in list: ";
  printVec(inV);
  cout << "unique list: ";
  printVec(res);
}
