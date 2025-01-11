#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

class std_unorderedmap_test : public testing::Test {
protected:
  class custom_hash {
  public:
    int operator()(const std::string &key) const {
      int hash{};
      for (size_t i = 0; i < key.length(); i++) {
        int asciival = int(key[i]);
        hash = (hash + (asciival * 23)) % 7;
      }
      return hash;
    };
  };

  std_unorderedmap_test() {}

  void SetUp() override {
    ht.insert({"Hello", 101});
    ht.insert({"Darkness", 201});
    ht.insert({"My", 301});
    ht.insert({"Old", 401});
    ht.insert({"Friend", 501});
    ht.insert({"I've", 102});
    ht.insert({"Come", 202});
    ht.insert({"See", 302});
    ht.insert({"You", 402});
    ht.insert({"Once", 502});
    ht.insert({"Again", 103});
  }
  void TearDown() override {}

  unordered_map<string, int, custom_hash> ht;
};

TEST_F(std_unorderedmap_test, test_insert) {
  EXPECT_EQ(ht["Hello"], 101);
  EXPECT_EQ(ht["Darkness"], 201);
  EXPECT_EQ(ht["My"], 301);
  EXPECT_EQ(ht["Old"], 401);
  EXPECT_EQ(ht["Friend"], 501);
  EXPECT_EQ(ht["I've"], 102);
  EXPECT_EQ(ht["Come"], 202);
  EXPECT_EQ(ht["See"], 302);
  EXPECT_EQ(ht["You"], 402);
  EXPECT_EQ(ht["Once"], 502);
  EXPECT_EQ(ht["Again"], 103);
}

TEST_F(std_unorderedmap_test, get_bucket_count) {
  EXPECT_EQ(ht.bucket_count(), 13);
}

TEST_F(std_unorderedmap_test, get_max_bucket_count) {
  cout << "max_bucket_count: " << ht.max_bucket_count() << "\n";
}

TEST_F(std_unorderedmap_test, get_bucket_size) {
  for (size_t i = 0; i < ht.bucket_count(); i++) {
    cout << "bucket_index[" << i << "] :" << ht.bucket_size(i) << "\n";
  }
}

TEST_F(std_unorderedmap_test, print_buckets) {
  for (size_t i = 0; i < ht.bucket_count(); ++i) {
    for (auto j = ht.begin(i); j != ht.end(i); ++j) {
      cout << "(" << j->first << ", " << j->second << ")";
    }
    cout << "\n";
  }
}
