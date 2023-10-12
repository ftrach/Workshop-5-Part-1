// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// 2023/10/05 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    sdds::Book library[7];

    // Open the file
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "ERROR: Could not open the file." << std::endl;
        return 2;
    }

    int count = 0;
    std::string line;

    // Read lines from the file and create Book objects
    while (count < 7 && std::getline(file, line)) {
        if (!line.empty() && line[0] != '#') {
            library[count] = sdds::Book(line);
            count++;
        }
    }

    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;

    // Define lambda expression to update book prices
    auto updatePrice = [&usdToCadRate, &gbpToCadRate](sdds::Book& book) {
        if (book.country() == "US") {
            book.price() *= usdToCadRate;
        }
        else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) {
            book.price() *= gbpToCadRate;
        }
    };

    // Print the library content
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "The library content" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << library[i] << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;

    // Update book prices using the lambda expression
    for (int i = 0; i < count; i++) {
        updatePrice(library[i]);
    }

    // Print the library content with updated prices
    std::cout << "The library content (updated prices)" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << library[i] << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;

    return 0;
}