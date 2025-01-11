/*
 * Implement a function called groupAnagrams() that groups a list of strings
 * based on their anagram equivalence.
 */
#pragma once
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

vector<vector<string>>
getAnagrams([[__maybe_unused__]] const vector<string> &strings) {

  auto hasher = [](const string &str) -> auto {
    string _str = str;
    std::sort(_str.begin(), _str.end());
    return std::hash<std::string>{}(_str);
  };

  unordered_map<size_t, size_t> uoMap{};
  vector<vector<string>> res{};

  for (auto &e : strings) {
    auto key = hasher(e);
    if (uoMap.find(key) == uoMap.end()) {
      uoMap[key] = res.size();
      res.push_back({});
    }
    res[uoMap[key]].push_back(e);
  }
  return res;
}

TEST(group_of_anagrams_test, test01) {
  vector<string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> anagrams = getAnagrams(input);

  for (const auto &e1 : anagrams) {
    for (const auto &e2 : e1) {
      cout << e2 << " ";
    }
    cout << "\n";
  }
}
