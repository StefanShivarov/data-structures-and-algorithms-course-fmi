#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void printIndicesOfUniqueLetters(string& input) {

    const int charactersAmount = 256;
    int letterCount[charactersAmount]{ 0 };

    for (char letter : input) {
        letterCount[letter]++;
    }

    for (int i = 0; i < input.size(); i++) {
        char letter = input[i];
        if (letterCount[letter] == 1) {
            cout << i << " ";
        }
    }

}

int main() {

    string input;
    cin >> input;
    printIndicesOfUniqueLetters(input);
    return 0;
}
