#pragma once

#include "Stack.hpp"
#include <gtest/gtest.h>
#include <limits>

TEST(StackTests, Create) {
  dst::stack::Stack<int> stack(2);
  EXPECT_EQ(stack.getHeight(), 1);
}

TEST(StackTests, Push) {
  dst::stack::Stack<int> stack(2);
  EXPECT_EQ(stack.getHeight(), 1);

  stack.push(2);

  EXPECT_EQ(stack.getHeight(), 2);
}

TEST(StackTests, PopInt) {
  dst::stack::Stack<int> stack(2);
  EXPECT_EQ(stack.getHeight(), 1);

  stack.push(3);
  EXPECT_EQ(stack.getHeight(), 2);

  EXPECT_EQ(stack.pop(), 3);
  EXPECT_EQ(stack.getHeight(), 1);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.getHeight(), 0);

  EXPECT_EQ(stack.pop(), std::numeric_limits<int>::max());
  EXPECT_EQ(stack.getHeight(), 0);
}

TEST(StackTests, PopLong) {
  dst::stack::Stack<long> stack(2);
  EXPECT_EQ(stack.getHeight(), 1);

  stack.push(3);
  EXPECT_EQ(stack.getHeight(), 2);

  EXPECT_EQ(stack.pop(), 3);
  EXPECT_EQ(stack.getHeight(), 1);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.getHeight(), 0);

  EXPECT_EQ(stack.pop(), std::numeric_limits<long>::max());
  EXPECT_EQ(stack.getHeight(), 0);
}
