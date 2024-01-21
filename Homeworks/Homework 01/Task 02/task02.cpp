#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int examinationsAmount;
    cin >> examinationsAmount;

    while (examinationsAmount-- > 0) {
        int studentsAmount, minFailures;
        string examSummary;
        cin >> studentsAmount >> minFailures >> examSummary;

        set<char> failedStudents;

        vector<int> symbolCount(26, 0);
        for (char symbol : examSummary) {
            if (isupper(symbol)) {
                symbolCount[symbol - 'A']++;
            }
        }

        for (char symbol : examSummary) {
            if (isupper(symbol) && symbolCount[symbol - 'A'] >= minFailures && failedStudents.find(symbol) == failedStudents.end()) {
                failedStudents.insert(symbol);
            }
        }

        for (char symbol : failedStudents) {
            cout << symbol;
        }
        cout << endl;
    }
    return 0;
}
