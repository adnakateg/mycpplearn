#pragma once
#include <gtest/gtest.h>
#include <stack>
#include <string>

using std::stack;
using std::string;

bool isBalancedParantheses(const string &parantheses) {
  stack<char> paranthesesStack{};
  if (!parantheses.empty()) {
    for (const auto &e : parantheses) {
      if (e == '(') {
        paranthesesStack.push('(');
      } else if (e == ')') {
        if (paranthesesStack.empty()) {
          return false;
        }
        if (paranthesesStack.top() == '(') {
          paranthesesStack.pop();
        }
      }
    }
  }
  return paranthesesStack.empty();
}

TEST(IsBalancedParanthesesTest, EmptyString) {
  string str = "";

  EXPECT_TRUE(isBalancedParantheses(str));
}

TEST(IsBalancedParanthesesTest, OneCharString) {
  string str = "A";

  EXPECT_TRUE(isBalancedParantheses(str));
}

TEST(IsBalancedParanthesesTest, MultiCharString) {
  string str = "AbCdE";

  EXPECT_TRUE(isBalancedParantheses(str));
}

TEST(IsBalancedParanthesesTest, WithBalancedParantheses) {
  string str = "A(bCd)E";

  EXPECT_TRUE(isBalancedParantheses(str));
}

TEST(IsBalancedParanthesesTest, WithoutBalancedParantheses) {
  string str = ")(";

  EXPECT_FALSE(isBalancedParantheses(str));

  str = "(()))";
  EXPECT_FALSE(isBalancedParantheses(str));
}
