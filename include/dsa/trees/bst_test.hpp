#pragma once

#include "bst.hpp"
#include <gtest/gtest.h>

TEST(BSTTests, Insert) {
  dst::tree::BST<int> bst;
  bst.insert(47);
  bst.insert(21);
  bst.insert(76);
  bst.insert(18);
  bst.insert(52);
  bst.insert(82);

  EXPECT_FALSE(bst.insert(47));
  bst.insert(27);
  EXPECT_EQ(bst.m_root->m_left->m_right->m_value, 27);
}

TEST(BSTTests, Contains) {
  dst::tree::BST<int> bst;
  bst.insert(47);
  bst.insert(21);
  bst.insert(76);
  bst.insert(18);
  bst.insert(52);
  bst.insert(82);

  EXPECT_TRUE(bst.contains(47));
  EXPECT_TRUE(bst.contains(21));
  EXPECT_TRUE(bst.contains(76));
  EXPECT_TRUE(bst.contains(18));
  EXPECT_TRUE(bst.contains(52));
  EXPECT_TRUE(bst.contains(82));
  EXPECT_FALSE(bst.contains(8));
}

TEST(BSTTests, GetMin) {
  dst::tree::BST<int> bst;
  bst.insert(47);
  bst.insert(21);
  bst.insert(76);
  bst.insert(18);
  bst.insert(52);
  bst.insert(82);

  EXPECT_EQ(bst.getMin(), 18);
}
