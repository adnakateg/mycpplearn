#pragma once

#include "hash.hpp"
#include <gtest/gtest.h>
#include <limits>

TEST(HashTables, tests) {
  constexpr size_t SIZE = 7;
  auto hashF = [](const std::string &key) -> auto {
    int hash{};
    for (size_t i = 0; i < key.length(); i++) {
      int asciival = int(key[i]);
      hash = (hash + (asciival * 23)) % SIZE;
    }
    return hash;
  };
  dst::hash::HashTable<hashF, SIZE> ht;
  ht.set("Hello", 101);
  ht.set("Darkness", 201);
  ht.set("My", 301);
  ht.set("Old", 401);
  ht.set("Friend", 501);
  ht.set("I've", 102);
  ht.set("Come", 202);
  ht.set("See", 302);
  ht.set("You", 402);
  ht.set("Once", 502);
  ht.set("Again", 103);
  ht.printHash();

  EXPECT_EQ(ht.get("Hello", std::numeric_limits<int>::max()), 101);
  EXPECT_EQ(ht.get("Darkness", std::numeric_limits<int>::max()), 201);
  EXPECT_EQ(ht.get("My", std::numeric_limits<int>::max()), 301);
  EXPECT_EQ(ht.get("Old", std::numeric_limits<int>::max()), 401);
  EXPECT_EQ(ht.get("Friend", std::numeric_limits<int>::max()), 501);
  EXPECT_EQ(ht.get("I've", std::numeric_limits<int>::max()), 102);
  EXPECT_EQ(ht.get("Come", std::numeric_limits<int>::max()), 202);
  EXPECT_EQ(ht.get("See", std::numeric_limits<int>::max()), 302);
  EXPECT_EQ(ht.get("You", std::numeric_limits<int>::max()), 402);
  EXPECT_EQ(ht.get("Once", std::numeric_limits<int>::max()), 502);
  EXPECT_EQ(ht.get("Again", std::numeric_limits<int>::max()), 103);
}
