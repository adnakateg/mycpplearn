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

TEST(BSTTests, RContains) {
  dst::tree::BST<int> bst{};
  bst.insert(47);
  bst.insert(21);
  bst.insert(76);
  bst.insert(18);
  bst.insert(52);
  bst.insert(82);

  EXPECT_TRUE(bst.r_contains(18));
  EXPECT_FALSE(bst.r_contains(111));
}

TEST(BSTTests, RInsert) {
  dst::tree::BST<int> bst{};
  bst.r_insert(47);
  bst.r_insert(21);
  bst.r_insert(76);
  bst.r_insert(18);
  bst.r_insert(52);
  bst.r_insert(82);

  EXPECT_TRUE(bst.r_contains(18));
  EXPECT_FALSE(bst.r_contains(111));
}

TEST(BSTTests, RminVal) {
  dst::tree::BST<int> bst{};
  bst.r_insert(47);
  bst.r_insert(21);
  bst.r_insert(76);
  bst.r_insert(18);
  bst.r_insert(27);
  bst.r_insert(52);
  bst.r_insert(82);

  EXPECT_EQ(bst.r_minValue(bst.m_root), 18);
  EXPECT_EQ(bst.r_minValue(bst.m_root->m_right), 52);
}

TEST(BSTTests, Delete) {
  dst::tree::BST<int> bst{};
  bst.r_insert(47);
  bst.r_insert(21);
  bst.r_insert(76);
  bst.r_insert(18);
  bst.r_insert(27);
  bst.r_insert(52);
  bst.r_insert(82);

  EXPECT_EQ(bst.r_minValue(bst.m_root), 18);
  EXPECT_EQ(bst.r_minValue(bst.m_root->m_right), 52);
}
