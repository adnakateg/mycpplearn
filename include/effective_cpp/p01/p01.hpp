#pragma once
#include <iostream>

#include <gtest/gtest.h>
template<typename T>
void non_uref_func(T&)
{
    std::cout << "Deduced As: \n" << __PRETTY_FUNCTION__ << "\n";
}

TEST(p01, with_lvalue)
{
    int x = 32;

    // T = int, Param = int&
    non_uref_func(x);
}

TEST(p01, with_const_lvalue)
{
    int x = 32;
    const int cx = x;

    // T = const int, Param = const int&
    non_uref_func(cx);
}

TEST(p01, with_const_lvalue_reference)
{
    int x = 32;
    const int& rx = x;

    // T = const int, Param = const int& ::: Reference part of the parameter is ignored
    non_uref_func(rx);
}

template<typename T>
void non_uref_func_const(const T&)
{
    std::cout << "Deduced As: \n" << __PRETTY_FUNCTION__ << "\n";
}

TEST(p01_const, with_lvalue)
{
    int x = 32;

    // T = int, Param = int&
    non_uref_func_const(x);
}

TEST(p01_const, with_const_lvalue)
{
    int x = 32;
    const int cx = x;

    // T = const int, Param = const int&
    non_uref_func_const(cx);
}

TEST(p01_const, with_const_lvalue_reference)
{
    int x = 32;
    const int& rx = x;

    // T = const int, Param = const int& ::: Reference part of the parameter is ignored
    non_uref_func_const(rx);
}
