#include "all.hpp"
#include <gtest/gtest.h>
#include <iostream>
using std::cout;
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    auto ret = RUN_ALL_TESTS();
    cout << "\n\n====================\n";
    if (ret == 0)
    {
        cout << "TESTING SUCCESSFULL\n";
    }
    else
    {
        cout << "TESTING FAILED\n";
    }
    cout << "====================\n\n";
    return ret;
}
