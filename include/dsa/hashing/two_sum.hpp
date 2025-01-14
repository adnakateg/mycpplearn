/* Implement a function called twoSum() that finds two numbers in a given vector
 * of integers that add up to a specific target number.
 */
#pragma once
#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::iostream;
using std::unordered_map;
using std::vector;

vector<size_t> two_sum(const vector<int> &nums, int target) {
  unordered_map<size_t, size_t> uoMap{};

  auto lambdaF = [](int x, int y) -> auto { return y - x; };

  for (size_t i = 0; i < nums.size(); ++i) {
    auto ite = uoMap.find(nums[i]);
    if (ite != uoMap.end()) {
      return {ite->second, i};
    }
    uoMap.insert({lambdaF(nums[i], target), i});
  }
  return {};
}

TEST(two_sum_test, test01) {
  vector<int> nums = {1, 3, 4, 2, 5};
  int target = 6;

  auto res = two_sum(nums, target);

  for (const auto &e : res) {
    cout << e << " ";
  }
}
