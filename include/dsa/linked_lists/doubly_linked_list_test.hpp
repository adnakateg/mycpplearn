#pragma once

#include "doubly_linked_list.hpp"
#include <gtest/gtest.h>

class DoublyLinkedListTest : public testing::Test {
protected:
  DoublyLinkedListTest() {}
  void SetUp() override {}
  void TearDown() override {}

  dst::dbll::DoublyLinkedList<int> m_dll{1};
};

TEST_F(DoublyLinkedListTest, CreateAndAppend) {
  EXPECT_EQ(m_dll.getLength(), 1);
  m_dll.append(20);

  EXPECT_EQ(m_dll.getLength(), 2);
  m_dll.append(30);

  EXPECT_EQ(m_dll.getLength(), 3);
}

TEST_F(DoublyLinkedListTest, DeleteLast) {
  dst::dbll::DoublyLinkedList<int> m_dll(10);

  m_dll.append(20);
  m_dll.append(30);

  EXPECT_EQ(m_dll.getLength(), 3);

  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 2);

  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 1);

  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 0);

  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 0);
}

TEST_F(DoublyLinkedListTest, PrependTest) {
  dst::dbll::DoublyLinkedList<int> m_dll(10);

  m_dll.prepend(20);
  EXPECT_EQ(m_dll.getHead()->m_value, 20);
  m_dll.prepend(30);
  EXPECT_EQ(m_dll.getHead()->m_value, 30);
  m_dll.prepend(40);
  EXPECT_EQ(m_dll.getHead()->m_value, 40);
  m_dll.prepend(50);
  EXPECT_EQ(m_dll.getHead()->m_value, 50);

  EXPECT_EQ(m_dll.getLength(), 5);
  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 4);
  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 3);
  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 2);
  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 1);
  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 0);
  m_dll.deleteLast();
  EXPECT_EQ(m_dll.getLength(), 0);
}

TEST_F(DoublyLinkedListTest, DeleteFirst) {
  dst::dbll::DoublyLinkedList<int> m_dll(10);

  // delete 1 item list
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);

  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);

  m_dll.append(10);
  EXPECT_EQ(m_dll.getLength(), 1);

  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);

  m_dll.append(10);
  m_dll.prepend(20);
  m_dll.append(30);
  m_dll.prepend(40);
  EXPECT_EQ(m_dll.getLength(), 4);

  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 3);
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 2);
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 1);
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);
}

TEST_F(DoublyLinkedListTest, GetIndex) {
  dst::dbll::DoublyLinkedList<int> m_dll(10);
  m_dll.append(20);
  m_dll.append(30);
  m_dll.append(40);
  m_dll.append(50);

  EXPECT_EQ(m_dll.get(0)->m_value, 10);
  EXPECT_EQ(m_dll.get(1)->m_value, 20);
  EXPECT_EQ(m_dll.get(2)->m_value, 30);
  EXPECT_EQ(m_dll.get(3)->m_value, 40);
  EXPECT_EQ(m_dll.get(4)->m_value, 50);
}

TEST_F(DoublyLinkedListTest, SetIndex) {
  dst::dbll::DoublyLinkedList<int> m_dll(10);
  m_dll.append(20);
  m_dll.append(30);
  m_dll.append(40);
  m_dll.append(50);

  m_dll.set(2, 100);
  EXPECT_EQ(m_dll.get(2)->m_value, 100);

  m_dll.set(4, 200);
  EXPECT_EQ(m_dll.get(4)->m_value, 200);
}

TEST_F(DoublyLinkedListTest, Insert) {
  dst::dbll::DoublyLinkedList<int> m_dll(10);
  m_dll.deleteFirst();
  EXPECT_EQ(m_dll.getLength(), 0);

  m_dll.insert(0, 20);
  EXPECT_EQ(m_dll.get(0)->m_value, 20);

  m_dll.append(30);
  m_dll.append(40);
  m_dll.append(50);

  EXPECT_FALSE(m_dll.insert(10, 10));

  m_dll.insert(4, 60);
  EXPECT_EQ(m_dll.get(4)->m_value, 60);

  m_dll.insert(4, 70);
  EXPECT_EQ(m_dll.get(4)->m_value, 70);
  EXPECT_EQ(m_dll.get(5)->m_value, 60);
}

TEST_F(DoublyLinkedListTest, DeleteNode) {
  dst::dbll::DoublyLinkedList<int> m_dll(10);
  m_dll.deleteNode(0);
  EXPECT_EQ(m_dll.getLength(), 0);

  m_dll.deleteNode(3);
  EXPECT_EQ(m_dll.getLength(), 0);

  m_dll.append(10);
  m_dll.append(20);
  m_dll.append(30);
  m_dll.append(40);
  m_dll.append(50);
  EXPECT_EQ(m_dll.getLength(), 5);

  m_dll.deleteNode(5);
  EXPECT_EQ(m_dll.getLength(), 5);

  m_dll.deleteNode(4);
  EXPECT_EQ(m_dll.getLength(), 4);

  m_dll.deleteNode(1);
  EXPECT_EQ(m_dll.getLength(), 3);
}

TEST_F(DoublyLinkedListTest, SwapFirstLast) {
  dst::dbll::DoublyLinkedList<int> m_dll(0);
  m_dll.append(1);
  m_dll.append(2);
  m_dll.append(3);
  m_dll.append(4);
  m_dll.append(5);

  EXPECT_EQ(m_dll.get(0)->m_value, 0);
  EXPECT_EQ(m_dll.get(5)->m_value, 5);

  m_dll.swapFirstLast();

  EXPECT_EQ(m_dll.get(0)->m_value, 5);
  EXPECT_EQ(m_dll.get(5)->m_value, 0);
}

TEST_F(DoublyLinkedListTest, Reverse) {
  dst::dbll::DoublyLinkedList<int> m_dll(0);
  m_dll.append(1);
  m_dll.append(2);
  m_dll.append(3);
  m_dll.append(4);
  m_dll.append(5);

  EXPECT_EQ(m_dll.get(0)->m_value, 0);
  EXPECT_EQ(m_dll.get(1)->m_value, 1);
  EXPECT_EQ(m_dll.get(2)->m_value, 2);
  EXPECT_EQ(m_dll.get(3)->m_value, 3);
  EXPECT_EQ(m_dll.get(4)->m_value, 4);
  EXPECT_EQ(m_dll.get(5)->m_value, 5);

  m_dll.reverse();

  EXPECT_EQ(m_dll.get(0)->m_value, 5);
  EXPECT_EQ(m_dll.get(1)->m_value, 4);
  EXPECT_EQ(m_dll.get(2)->m_value, 3);
  EXPECT_EQ(m_dll.get(3)->m_value, 2);
  EXPECT_EQ(m_dll.get(4)->m_value, 1);
  EXPECT_EQ(m_dll.get(5)->m_value, 0);
}

TEST_F(DoublyLinkedListTest, IsPalindrome) {
  dst::dbll::DoublyLinkedList<int> m_dll(0);
  m_dll.append(1);
  m_dll.append(2);
  m_dll.append(3);
  m_dll.append(2);
  m_dll.append(1);
  m_dll.append(0);
  EXPECT_TRUE(m_dll.isPalindrome());

  dst::dbll::DoublyLinkedList<int> m_dll2(0);
  m_dll2.append(1);
  m_dll2.append(2);
  m_dll2.append(3);
  m_dll2.append(3);
  m_dll2.append(2);
  m_dll2.append(1);
  m_dll2.append(0);
  EXPECT_TRUE(m_dll2.isPalindrome());

  dst::dbll::DoublyLinkedList<int> m_dll3(0);
  EXPECT_TRUE(m_dll3.isPalindrome());

  dst::dbll::DoublyLinkedList<int> m_dll4(0);
  m_dll4.append(1);
  m_dll4.append(2);
  m_dll4.append(3);
  m_dll4.append(4);
  m_dll4.append(2);
  m_dll4.append(1);
  m_dll4.append(0);
  EXPECT_FALSE(m_dll4.isPalindrome());
}

TEST_F(DoublyLinkedListTest, SwapPairs) {
  dst::dbll::DoublyLinkedList<int> m_dll(0);
  m_dll.append(1);
  m_dll.append(2);
  m_dll.append(3);
  m_dll.append(4);
  m_dll.append(5);
  m_dll.append(6);

  m_dll.swapPairs();

  EXPECT_EQ(m_dll.get(0)->m_value, 1);
  EXPECT_EQ(m_dll.get(1)->m_value, 0);
  EXPECT_EQ(m_dll.get(2)->m_value, 3);
  EXPECT_EQ(m_dll.get(3)->m_value, 2);
  EXPECT_EQ(m_dll.get(4)->m_value, 5);
  EXPECT_EQ(m_dll.get(5)->m_value, 4);
  EXPECT_EQ(m_dll.get(6)->m_value, 6);
}
