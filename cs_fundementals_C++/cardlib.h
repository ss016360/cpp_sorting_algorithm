#pragma once

// header file for cardlib
// RJM 06/01/24


#include <string>
#include <iostream>
#include <cassert>


enum Suit {
    hearts,
    clubs,
    diamonds,
    spades
};      // define suits


struct aCard {                          // defines a card
    int cardVal;                        // number 1..13
    Suit cardSuit;                      // suit
};

std::string cardToStr(std::vector<int> s, int i);			// declare function to represent a card as a two character string

aCard getCard(const std::string& studentNumber);        // declares function to get a card from stdno string

bool cardExists(std::vector<int> suit, int n);      // declares function to check if a card exists in an array

std::vector<std::vector<int> > get20Cards();                      // declares function to get 20 cards

void swapCards(int* xp, int* yp);            // declares function to swap two integers

void compareCards(int* xp, int* yp);     // declares function to compare two integers

void bubbleSort(std::vector<int>& suit);      // declares function to sort an array of integers