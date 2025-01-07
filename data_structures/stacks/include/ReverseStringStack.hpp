#pragma once
#include <gtest/gtest.h>
#include <stack>
#include <string>

using std::stack;
using std::string;

string reverseString(const string &str) {
  std::cout << "Input str: " << str << "\n";
  string revStr{};
  stack<char> charStack{};

  if (str.empty() == false) {
    for (auto &ite : str) {
      charStack.push(ite);
    }
  }

  while (charStack.empty() == false) {
    revStr.append({charStack.top()});
    charStack.pop();
  }

  std::cout << "Return str: " << revStr << "\n";
  return revStr;
}

TEST(ReverseStringTests, EmptyString) {
  string str{};

  string ret = reverseString(str);

  EXPECT_STREQ(ret.c_str(), "");
}

TEST(ReverseStringTests, SingleCharacterString) {
  string str = "A";

  string ret = reverseString(str);

  string exp = "A";
  EXPECT_STREQ(ret.c_str(), exp.c_str());
}

TEST(ReverseStringTests, LongString) {
  string str = "Samudra Vishvajith Kapuruge";

  string ret = reverseString(str);

  string exp = "egurupaK htijavhsiV ardumaS";
  EXPECT_STREQ(ret.c_str(), exp.c_str());
}
