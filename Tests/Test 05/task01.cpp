#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool canMakeSentence(unordered_map<string, size_t>& firstSentence, unordered_map<string, size_t>& secondSentence) {

    if (secondSentence.size() > firstSentence.size()) {
        return false;
    }

    for (auto& pair : secondSentence) {
        if (firstSentence[pair.first] == 0 || firstSentence.count(pair.first) == 0 || firstSentence[pair.first] < pair.second) {
            return false;
        }
        firstSentence[pair.first]--;
    }

    return true;
}

int main() {

    size_t testsAmount;
    cin >> testsAmount;

    for (size_t i = 0; i < testsAmount; i++) {
        unordered_map<string, size_t> firstSentenceMap, secondSentenceMap;
        size_t firstSentenceWordsAmount, secondSentenceWordsAmount;
        cin >> firstSentenceWordsAmount >> secondSentenceWordsAmount;

        for (size_t j = 0; j < firstSentenceWordsAmount; j++) {
            string word;
            cin >> word;

            if (firstSentenceMap.count(word) == 0) {
                firstSentenceMap[word] = 1;
            }
            else {
                firstSentenceMap[word]++;
            }

        }
        for (size_t j = 0; j < secondSentenceWordsAmount; j++) {
            string word;
            cin >> word;

            if (secondSentenceMap.count(word) == 0) {
                secondSentenceMap[word] = 1;
            }
            else {
                secondSentenceMap[word]++;
            }
        }

        if (canMakeSentence(firstSentenceMap, secondSentenceMap)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
