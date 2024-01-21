#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void generateLongestPrefixSuffixArray(const string& pattern, vector<size_t>& lps) {
    size_t patternLength = pattern.size();
    size_t length = 0;
    size_t i = 1;
    lps[0] = 0;

    while (i < patternLength) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = length;
                i++;
            }
        }
    }
}

size_t getPatternOccurences(const string& pattern, const string& str) {
    size_t patternLength = pattern.length(), strLength = str.length();
    vector<size_t> lps(patternLength);
    size_t patternIndex = 0;

    generateLongestPrefixSuffixArray(pattern, lps);

    size_t strIndex = 0, result = 0;

    while (strIndex < strLength) {
        if (pattern[patternIndex] == str[strIndex]) {
            patternIndex++;
            strIndex++;
        }

        if (patternIndex == patternLength) {
            patternIndex = lps[patternIndex - 1];
            result++;
        }
        else if (strIndex < strLength && pattern[patternIndex] != str[strIndex]) {
            if (patternIndex != 0) {
                patternIndex = lps[patternIndex - 1];
            }
            else {
                strIndex++;
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    cout << getPatternOccurences(s1, s2);

    return 0;
}
