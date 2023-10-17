#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    string word;
    cin >> word;

    int numberOfSymbols;
    cin >> numberOfSymbols;

    char S;
    cin >> S;

    int index = 0, symbolOccurencesCounter = 0;

    while (numberOfSymbols-- > 0) {

        if (index == word.length()) {
            index = 0;
        }

        if (word[index++] == S) {
            symbolOccurencesCounter++;
        }
    }

    cout << symbolOccurencesCounter;
    return 0;
}
