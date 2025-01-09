#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::unordered_map;
using std::vector;

template <typename T>
vector<T> getCommonKeys(vector<T> &left, vector<T> &right) {
  vector<T> keys{};
  unordered_map<T, bool> uoMap{};

  for (const auto &e : left) {
    uoMap.insert({e, true});
  }
  for (const auto &e : right) {
    if (uoMap[e] == true) {
      keys.push_back(e);
    }
  }
  return keys;
}

TEST(GetCommonKeys, test) {
  vector<int> left{1, 3, 5, 7, 9};
  vector<int> right{2, 3, 4, 5, 6, 7};

  auto ret = getCommonKeys(left, right);
  EXPECT_EQ(ret[0], 3);
  EXPECT_EQ(ret[1], 5);
  EXPECT_EQ(ret[2], 7);

  for (const auto &e : ret) {
    cout << e << "  ";
  }
  cout << "\n";
}
