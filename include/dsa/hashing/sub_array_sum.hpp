/* Implement a function called subarraySum() that finds a continuous subarray
 * within a given vector of integers that adds up to a specific target number.
 */

#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::unordered_map;
using std::vector;

vector<int> sub_array_sum(const vector<int> &nums, int target) {
  unordered_map<int, int> uoMap{};
  int sums{};
  for (int i = 0; i < nums.size(); ++i) {
    sums = sums + nums[i];
    if (sums == target) {
      return {0, i};
    }
    uoMap.insert({sums, i});
    auto ite = uoMap.find(sums - target);
    if (ite != uoMap.end()) {
      return {ite->second + 1, i};
    }
  }
  return {};
}

TEST(sub_array_sum_test, test01) {
  vector<int> nums = {1, 2, 3, 4, 5};

  auto res = sub_array_sum(nums, 9);

  EXPECT_EQ(res[0], 1);
  EXPECT_EQ(res[1], 3);
}

TEST(sub_array_sum_test, test02) {
  vector<int> nums = {1, 3, 1, 7, 2, 4, 6, 8};

  auto res = sub_array_sum(nums, 13);

  EXPECT_EQ(res[0], 1);
  EXPECT_EQ(res[1], 4);
}

TEST(sub_array_sum_test, test03) {
  vector<int> nums = {3, 2, 5};

  auto res = sub_array_sum(nums, 10);

  EXPECT_EQ(res[0], 0);
  EXPECT_EQ(res[1], 2);
}
TEST(sub_array_sum_test, test04) {
  vector<int> nums = {10};

  auto res = sub_array_sum(nums, 10);

  EXPECT_EQ(res[0], 0);
  EXPECT_EQ(res[1], 0);
}

TEST(sub_array_sum_test, test05) {
  vector<int> nums{1, -2, 3, 4, -5, 6};

  auto res = sub_array_sum(nums, 6);

  EXPECT_EQ(res[0], 0);
  EXPECT_EQ(res[1], 3);
}
TEST(sub_array_sum_test, test06) {
  vector<int> nums{1, -2, 3, 4, 5, 6};

  auto res = sub_array_sum(nums, 100);

  EXPECT_EQ(res.size(), 0);
}
