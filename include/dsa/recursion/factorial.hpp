#pragma once

#include <gtest/gtest.h>

template <typename T> T factorial(T n) {
  if (n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

TEST(factorial_test, test01) {
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(4), 24);
  EXPECT_EQ(factorial(5), 120);
}
