#include <iostream>
#include <string>
#include <cassert>
#include "test_cardlib.h"

void assert_swap_tests() {
    // first example
    int a = 1;
    int b = 2;
    swapCards(&a, &b);
    assert(a == 2);
    assert(b == 1);
    
    // second example
    int c = 3;
    int d = 4;
    swapCards(&c, &d);
    assert(c == 4);
    assert(d == 3);
    
    // third example with negative numbers
    int e = -5;
    int f = -6;
    swapCards(&e, &f);
    assert(e == -6);
    assert(f == -5);
}

void assert_bubbleSort_tests() {
    std::vector<int> arr1;
    arr1.push_back(5);
    arr1.push_back(2);
    arr1.push_back(8);
    arr1.push_back(1);
    arr1.push_back(9);

    std::vector<int> arr2;
    arr2.push_back(10);
    arr2.push_back(7);
    arr2.push_back(3);
    arr2.push_back(6);
    arr2.push_back(2);

    std::vector<int> arr3;
    arr3.push_back(-5);
    arr3.push_back(-2);
    arr3.push_back(-8);
    arr3.push_back(-1);
    arr3.push_back(-9);


    // test case 1
    bubbleSort(arr1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 5);
    assert(arr1[3] == 8);
    assert(arr1[4] == 9);

    // test case 2
    bubbleSort(arr2);
    assert(arr2[0] == 2);
    assert(arr2[1] == 3);
    assert(arr2[2] == 6);
    assert(arr2[3] == 7);
    assert(arr2[4] == 10);
    
    // test case 3 with negative numbers
    bubbleSort(arr3);
    assert(arr3[0] == -9);
    assert(arr3[1] == -8);
    assert(arr3[2] == -5);
    assert(arr3[3] == -2);
    assert(arr3[4] == -1);
}

void assert_compareCards_tests() {
    // first example
    int a = 1;
    int b = 2;
    compareCards(&a, &b);
    assert(a == 1);
    assert(b == 2);
    
    // second example
    int c = 3;
    int d = 4;
    compareCards(&c, &d);
    assert(c == 3);
    assert(d == 4);
    
    // third example with negative numbers
    int e = -5;
    int f = -6;
    compareCards(&e, &f);
    assert(e == -6);
    assert(f == -5);
}