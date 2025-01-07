#pragma once
#include <gtest/gtest.h>
#include <stack>

TEST(StdStackTest, test_01) {
  std::stack<char> _stack;

  _stack.push('a');
  _stack.push('b');
  _stack.push('c');
  _stack.push('d');
  _stack.push('e');

  EXPECT_EQ(_stack.top(), 'e');
  _stack.pop();
  EXPECT_EQ(_stack.top(), 'd');
  _stack.pop();
  EXPECT_EQ(_stack.top(), 'c');
  _stack.pop();
  EXPECT_EQ(_stack.top(), 'b');
  _stack.pop();
  EXPECT_EQ(_stack.top(), 'a');
}
