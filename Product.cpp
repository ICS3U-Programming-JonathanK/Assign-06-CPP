// Copyright (c) 2021 Jonathan Kene All rights reserved.
//
// Created by: Jonathan Kene
// Created on: June 15, 2021
// The program uses a loop to enter each number floato a list of floategers.
// When the user enters -1, the loop stops. It then calls a function that
// accepts a list of floategers and returns the Product of all the numbers
// entered.

#include <math.h>
#include <list>
#include <string>
#include <stdexcept>
#include <iterator>
#include <iostream>

float calcProduct(std::list<float> listOfnumbers) {
    // calculate the Product in the list
    float total = 1;
    float product = -1;

    for (float number : listOfnumbers) {
        total = total*number;
    }

    if (listOfnumbers.size() == 0) {
        throw std::runtime_error("Cannot calculate the Product of empty list");
    } else {
        float size = listOfnumbers.size();
        product = total;
    }

    return product;
}


int main() {
    // initilizations
    // declaring variables
    std::list<float>listNumbers;
    std::string userNumberString, listString = "", NumberString;
    float userNumberfloat, counter = 0, number;
    float userNumberFloat, userProduct;

    std::cout << "This program calculates the Product of several numbers.\n";
    std::cout << "\n";

    while (true) {
        // gets a number for the list
        std::cout << " Enter a number between 0 to 100. Enter -1 to stop: ";
        std::cin >> userNumberString;

        try {
            userNumberfloat = std::stoi(userNumberString);

            userNumberFloat = std::stof(userNumberString);

            if (userNumberfloat == -1) {
                // breaks from the loop
                break;
            } else {
                // adds the numbers floato the list
                listNumbers.push_back(userNumberFloat);
            }
        } catch (std::invalid_argument) {
            // The user did not enter an floateger.
            std::cout << "Please enter a valid number, try again.\n";
        }

        std::cout << "\n";

    try {
        // calls the calcProduct funciton
        userProduct = calcProduct(listNumbers);
        // userProduct = round(userProduct);

        auto iter = listNumbers.begin();
        auto iterEnd = (++listNumbers.rbegin()).base();
        std::cout << "Here are the numbers: [";
        while (iter != listNumbers.end()) {
            if (iter == iterEnd) {
                number = *iter;
                std::cout << float(number) << "]\n";
                break;
            } else {
                number = *iter;
                std::cout << number << ", ";
                iter++;
            }
        }
        // displays the Product
        std::cout << "The product of all the "
                     "numbers in the list is: " << float(userProduct) << ".\n";
    } catch (std::runtime_error& e) {
            // The user did not enter an floateger.
            std::cout << "\n";
            std::cout << "Please enter a valid number, try again." << e.what();
        }
    }
}
