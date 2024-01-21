#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    size_t maxSequenceLength = 0, currentSequenceLength = 0;

    for (size_t i = 0; i < s1.size(); i++) {
        currentSequenceLength = 0;
        size_t currentIndex = i;

        for (size_t j = 0; j < s2.size(); j++) {
            if (currentIndex >= s1.size()) {
                break;
            }

            if (s1[currentIndex] != s2[j]) {
                currentSequenceLength = 0;
            }
            else {
                currentSequenceLength++;
                maxSequenceLength = max(maxSequenceLength, currentSequenceLength);
            }

            currentIndex++;
        }
    }

    cout << maxSequenceLength;

    return 0;
}
