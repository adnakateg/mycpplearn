#pragma once

#include "Queue.hpp"
#include <gtest/gtest.h>
#include <limits>

TEST(QueueTests, Create) {
  dst::queue::Queue<int> queue(2);
  EXPECT_EQ(queue.getLength(), 1);
  EXPECT_EQ(queue.getFirst(), 2);
  EXPECT_EQ(queue.getLast(), 2);
}

TEST(QueueTests, Enqueue) {
  dst::queue::Queue<int> queue(2);
  EXPECT_EQ(queue.getLength(), 1);
  queue.enqueue(3);
  EXPECT_EQ(queue.getLength(), 2);
  queue.enqueue(4);
  EXPECT_EQ(queue.getLength(), 3);
  EXPECT_EQ(queue.getLast(), 4);
  EXPECT_EQ(queue.getFirst(), 2);
}

TEST(QueueTests, Dequeue) {
  dst::queue::Queue<int> queue(2);
  EXPECT_EQ(queue.getLength(), 1);
  queue.enqueue(3);
  EXPECT_EQ(queue.getLength(), 2);
  queue.enqueue(4);

  EXPECT_EQ(queue.dequeue(), 2);
  EXPECT_EQ(queue.dequeue(), 3);
  EXPECT_EQ(queue.dequeue(), 4);
  EXPECT_EQ(queue.dequeue(), std::numeric_limits<int>::max());
  EXPECT_EQ(queue.dequeue(), std::numeric_limits<int>::max());
  EXPECT_EQ(queue.dequeue(), std::numeric_limits<int>::max());
}
