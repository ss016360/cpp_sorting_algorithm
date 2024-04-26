#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib> // For srand and rand
#include <ctime> // For time
#include "cardlib.h"
#include "test_cardlib.h"


int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    // Call test functions
    void assert_swap_tests();
    void assert_bubbleSort_tests();
    void assert_compareCards_tests();

    // Output success message
    std::cout << "All tests passed!\n";

    std::vector<std::vector<int> > allSuits = get20Cards();

    std::cout << "Sorted array: \n";

    for (int i = 0; i < allSuits.size(); i++) {
        bubbleSort(allSuits[i]);
        for (int j = 0; j < allSuits[i].size(); j++) {
        }
    }


    for (int suit = 0; suit < allSuits.size(); ++suit) {
        for (int card = 0; card < allSuits[suit].size(); ++card) {
            if (suit == 0) {
                std::cout << "H" << cardToStr(allSuits[suit], card) << " ";
            }
            else if (suit == 1) {
                std::cout << "C" << cardToStr(allSuits[suit], card) << " ";
            }
            else if (suit == 2) {
                std::cout << "D" << cardToStr(allSuits[suit], card) << " ";
            }
            else if (suit == 3) {
                std::cout << "S" << cardToStr(allSuits[suit], card) << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}