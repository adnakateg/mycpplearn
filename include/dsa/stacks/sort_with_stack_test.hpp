#pragma once
#include <gtest/gtest.h>
#include <stack>

using std::stack;

void sortStack(stack<int> &inStack) {
  stack<int> tmpStack{};
  int val{};
  while (!inStack.empty()) {
    val = inStack.top();
    inStack.pop();
    if (tmpStack.empty()) {
      tmpStack.push(val);
    } else if (val >= tmpStack.top()) {
      tmpStack.push(val);
    } else {
      while (!tmpStack.empty()) {
        if (val < tmpStack.top()) {
          inStack.push(tmpStack.top());
          tmpStack.pop();
        } else {
          break;
        }
      }
      tmpStack.push(val);
    }
  }
  while (!tmpStack.empty()) {
    inStack.push(tmpStack.top());
    tmpStack.pop();
  }
}

TEST(TestStackSort, test) {
  stack<int> inStack;
  inStack.push(4);
  inStack.push(10);
  inStack.push(9);
  inStack.push(1);
  inStack.push(13);
  inStack.push(2);

  sortStack(inStack);
  EXPECT_EQ(inStack.top(), 1);
  inStack.pop();
  EXPECT_EQ(inStack.top(), 2);
  inStack.pop();
  EXPECT_EQ(inStack.top(), 4);
  inStack.pop();
  EXPECT_EQ(inStack.top(), 9);
  inStack.pop();
  EXPECT_EQ(inStack.top(), 10);
  inStack.pop();
  EXPECT_EQ(inStack.top(), 13);
}
