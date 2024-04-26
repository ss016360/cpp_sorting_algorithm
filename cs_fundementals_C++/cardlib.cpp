#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include "cardlib.h"

// Definitions of functions declared in cardlib.h

std::string cardToStr(std::vector<int> s, int i) {
    std::string cardStr;
    
    if (s[i] == 1) {
        cardStr += "A";
    }
    else if (s[i] == 11) {
        cardStr += "J";
    }
    else if (s[i] == 12) {
        cardStr += "Q";
    }
    else if (s[i] == 13) {
        cardStr += "K";
    }
    else {
        cardStr += std::to_string(s[i]);
    }
    //
   return cardStr;
}

aCard getCard(const std::string& studentNumber)
{  // function returns a card  - using student number studentNumber (8 numerical chars)
    aCard ans;
    int random_num = 0;
    std::string randomCardString = studentNumber.substr(rand() % 8, 1) + studentNumber.substr(rand() % 8, 1);    // two random characters from studentNumber
    int randomCard = stoi(randomCardString) % 52;          // get integer in range 0..51
    std::string res = "  ";
    //std::cout << "randomCard: " << randomCard << std::endl;
    //std::cout << "randomCardString: " << randomCardString << std::endl;
    ans.cardVal = 1 + randomCard % 13;                         // give cardVal 1..13
    ans.cardSuit = static_cast<Suit>(randomCard / 13);         // and for suit
    //std::cout << "Card: " << ans.cardSuit << " " << ans.cardVal << std::endl;
    return ans;
}



/*
// Simple mix function - Placeholder for more complex logic
int mixDigits(const std::string& studentNumber) {
    int mixedValue = 0;
    for (char digit : studentNumber) {
        mixedValue += digit - '0'; // Convert char to int and add to mix
        mixedValue *= 10; // Arbitrary mix step
    }
    return mixedValue;
}

aCard getCard(const std::string& studentNumber) {
    static size_t callCount = 0; // Ensure different results on subsequent calls
    int mixedValue = mixDigits(studentNumber) + callCount++; // Mix digits and increment call count

    aCard card;
    mixedValue = mixedValue % 52; // Ensure value falls within card range
    card.cardVal = 1 + mixedValue % 13; // Values between 1 and 13
    card.cardSuit = static_cast<Suit>(mixedValue / 13); // Suits between 0 and 3

    return card;
}
*/

bool cardExists(std::vector<int> suit, int n) {
    for (int i = 0; i < suit.size(); i++) {
        if (suit[i] == n) {
            return true;
        }
    }
    return false;
}

std::vector<std::vector<int> > get20Cards() {
    std::vector<std::vector<int> > allSuits;
    std::vector<int> hearts, clubs, diamonds, spades;

    while (hearts.size() < 5 || clubs.size() < 5 || diamonds.size() < 5 || spades.size() < 5) {
        aCard c = getCard("32016360"); // Always generate a new card at the start of the loop

        switch (c.cardSuit) {
            case 0:
                if (hearts.size() < 5 && !cardExists(hearts, c.cardVal)) {
                    hearts.push_back(c.cardVal);
                }
                break;
            case 1:
                if (clubs.size() < 5 && !cardExists(clubs, c.cardVal)) {
                    clubs.push_back(c.cardVal);
                }
                break;
            case 2:
                if (diamonds.size() < 5 && !cardExists(diamonds, c.cardVal)) {
                    diamonds.push_back(c.cardVal);
                }
                break;
            case 3:
                if (spades.size() < 5 && !cardExists(spades, c.cardVal)) {
                    spades.push_back(c.cardVal);
                }
                break;
        }
    }

    std::cout << "Hearts: ";
    for (int i = 0; i < hearts.size(); i++) {
        std::cout << hearts[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Clubs: ";
    for (int i = 0; i < clubs.size(); i++) {
        std::cout << clubs[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Diamonds: ";
    for (int i = 0; i < diamonds.size(); i++) {
        std::cout << diamonds[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Spades: ";
    for (int i = 0; i < spades.size(); i++) {
        std::cout << spades[i] << " ";
    }
    std::cout << std::endl;

    allSuits.push_back(hearts);
    allSuits.push_back(clubs);
    allSuits.push_back(diamonds);
    allSuits.push_back(spades);

    return allSuits;
}

void swapCards(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void compareCards(int* xp, int* yp) {
    if (*xp > *yp) {
        swapCards(xp, yp);
        std::cout << "Swapped " << *xp << " and " << *yp << std::endl;
    }
}

void bubbleSort(std::vector<int>& suit) {
    for (int i = 0; i < suit.size() - 1; i++) {
        for (int j = 0; j < suit.size() - i - 1; j++) {
            compareCards(&suit[j], &suit[j + 1]);
        }
    }
}



//give me an array of cards
