#pragma once

#include <gtest/gtest.h>
#include <unordered_set>
#include <vector>

using std::cout;
using std::unordered_set;
using std::vector;

int longest_consecutive_sequence(const vector<int> &nums) {
  unordered_set<int> uoSet{};
  for (const auto &e : nums) {
    uoSet.insert(e);
  }

  int res{};
  for (const auto &e : nums) {
    if (uoSet.find(e) != uoSet.end() && uoSet.find(e - 1) == uoSet.end()) {
      auto cur = e;
      int cnt = 0;
      while (uoSet.find(cur) != uoSet.end()) {
        uoSet.erase(cur);
        ++cur;
        ++cnt;
      }
      res = std::max(res, cnt);
    }
  }

  return res;
}

TEST(longest_consecutive_sequence_test, test01) {
  vector<int> testVec{2, 1, 6, 9, 4, 3};

  EXPECT_EQ(longest_consecutive_sequence(testVec), 4);
}
