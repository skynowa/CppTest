// Chars.cpp : Defines the entry point for the console application.
//

#include <StdTest.h>

std::string
sGetString(const size_t cuiLength) {
    const bool letters = true;
    const bool numbers = true;
    const bool symbols = true;

    std::string sRes;
    // the shortest way to do this is to create a string, containing
    // all possible values. Then, simply add a random value from that string
    // to our return value
    std::string allPossible; // this will contain all necessary characters

    if (letters == true) {
        for (int i = 65; i <= 90; i++) {
            allPossible += static_cast<char>(i);
            allPossible += static_cast<char>(i+32); // add a lower case letter, too!
        }
    }

    if (numbers == true) {
        for (int i = 48; i <= 57; i++) {
            allPossible += static_cast<char>(i);
        }
    }

    if (symbols == true) { // if you want symbols, we'll add symbols (note, their ASCII values are scattered)
        for (int i = 33; i <= 47; i++) {
            allPossible += static_cast<char>(i);
        }

        for (int i = 58; i <= 64; i++) {
            allPossible += static_cast<char>(i);
        }

        for (int i = 91; i <= 96; i++) {
            allPossible += static_cast<char>(i);
        }

        for (int i = 123; i <= 126; i++) {
            allPossible += static_cast<char>(i);
        }
    }

    // get the number of characters to use (used for rand())
    size_t numberOfPossibilities = allPossible.length();
    for (size_t i = 0; i < cuiLength; i++) {
        sRes += allPossible[rand() % numberOfPossibilities];
    }

    //std::random_shuffle(sRes.begin(), sRes.end());

    return sRes;
}

int main(int, char **)
{
    //const std::string sBucketA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //std::cout << "Ansi: "<< std::endl;
    //for (size_t i = 0; i < sBucketA.size(); ++ i ) {
    //    std::cout << sBucketA.at(i) << ": " << (int)sBucketA.at(i) << std::endl;
    //}

    //const std::wstring sBucketW = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //std::wcout << L"Unicode: "<< std::endl;
    //for (size_t i = 0; i < sBucketW.size(); ++ i ) {
    //    std::wcout << sBucketW.at(i) << L": " << (int)sBucketW.at(i) << std::endl;
    //}


    srand(time_t(NULL));
    for (size_t i = 0; i < 10; ++ i ) {
        std::cout << sGetString(10) << std::endl;
    }

    return 0;
}

