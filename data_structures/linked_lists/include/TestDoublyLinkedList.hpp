#pragma once

#include "DoublyLinkedList.hpp"
#include <gtest/gtest.h>

TEST(TestDoublyLinkedList, Create) {
  dst::dbll::DoublyLinkedList<int> testList(10);

  EXPECT_EQ(testList.getLength(), 1);
}

TEST(TestDoublyLinkedList, CreateAndAppend) {
  dst::dbll::DoublyLinkedList<int> testList(10);
  testList.append(20);

  EXPECT_EQ(testList.getLength(), 2);
  testList.append(30);

  EXPECT_EQ(testList.getLength(), 3);
}

TEST(TestDoublyLinkedList, DeleteLast) {
  dst::dbll::DoublyLinkedList<int> testList(10);

  testList.append(20);
  testList.append(30);

  EXPECT_EQ(testList.getLength(), 3);

  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 2);

  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 1);

  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 0);

  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 0);
}

TEST(TestDoublyLinkedList, PrependTest) {
  dst::dbll::DoublyLinkedList<int> testList(10);

  testList.prepend(20);
  EXPECT_EQ(testList.getHead()->m_value, 20);
  testList.prepend(30);
  EXPECT_EQ(testList.getHead()->m_value, 30);
  testList.prepend(40);
  EXPECT_EQ(testList.getHead()->m_value, 40);
  testList.prepend(50);
  EXPECT_EQ(testList.getHead()->m_value, 50);

  EXPECT_EQ(testList.getLength(), 5);
  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 4);
  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 3);
  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 2);
  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 1);
  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 0);
  testList.deleteLast();
  EXPECT_EQ(testList.getLength(), 0);
}

TEST(TestDoublyLinkedList, DeleteFirst) {
  dst::dbll::DoublyLinkedList<int> testList(10);

  // delete 1 item list
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);

  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);

  testList.append(10);
  EXPECT_EQ(testList.getLength(), 1);

  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);

  testList.append(10);
  testList.prepend(20);
  testList.append(30);
  testList.prepend(40);
  EXPECT_EQ(testList.getLength(), 4);

  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 3);
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 2);
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 1);
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);
}

TEST(TestDoublyLinkedList, GetIndex) {
  dst::dbll::DoublyLinkedList<int> testList(10);
  testList.append(20);
  testList.append(30);
  testList.append(40);
  testList.append(50);

  EXPECT_EQ(testList.get(0)->m_value, 10);
  EXPECT_EQ(testList.get(1)->m_value, 20);
  EXPECT_EQ(testList.get(2)->m_value, 30);
  EXPECT_EQ(testList.get(3)->m_value, 40);
  EXPECT_EQ(testList.get(4)->m_value, 50);
}

TEST(TestDoublyLinkedList, SetIndex) {
  dst::dbll::DoublyLinkedList<int> testList(10);
  testList.append(20);
  testList.append(30);
  testList.append(40);
  testList.append(50);

  testList.set(2, 100);
  EXPECT_EQ(testList.get(2)->m_value, 100);

  testList.set(4, 200);
  EXPECT_EQ(testList.get(4)->m_value, 200);
}

TEST(TestDoublyLinkedList, Insert) {
  dst::dbll::DoublyLinkedList<int> testList(10);
  testList.deleteFirst();
  EXPECT_EQ(testList.getLength(), 0);

  testList.insert(0, 20);
  EXPECT_EQ(testList.get(0)->m_value, 20);

  testList.append(30);
  testList.append(40);
  testList.append(50);

  EXPECT_FALSE(testList.insert(10, 10));

  testList.insert(4, 60);
  EXPECT_EQ(testList.get(4)->m_value, 60);

  testList.insert(4, 70);
  EXPECT_EQ(testList.get(4)->m_value, 70);
  EXPECT_EQ(testList.get(5)->m_value, 60);
}

TEST(TestDoublyLinkedList, DeleteNode) {
  dst::dbll::DoublyLinkedList<int> testList(10);
  testList.deleteNode(0);
  EXPECT_EQ(testList.getLength(), 0);

  testList.deleteNode(3);
  EXPECT_EQ(testList.getLength(), 0);

  testList.append(10);
  testList.append(20);
  testList.append(30);
  testList.append(40);
  testList.append(50);
  EXPECT_EQ(testList.getLength(), 5);

  testList.deleteNode(5);
  EXPECT_EQ(testList.getLength(), 5);

  testList.deleteNode(4);
  EXPECT_EQ(testList.getLength(), 4);

  testList.deleteNode(1);
  EXPECT_EQ(testList.getLength(), 3);
}
