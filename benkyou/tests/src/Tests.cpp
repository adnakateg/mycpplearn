#include <gtest/gtest.h>
#include "StackTests.h"

using namespace testing;

int main(int argc, char** argv)
{
    InitGoogleTest();

    auto ret = RUN_ALL_TESTS();

    return ret;
}
