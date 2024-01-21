#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int programmersAmount, teamsAmount;
    cin >> programmersAmount >> teamsAmount;

    vector<size_t> programmers(programmersAmount);

    size_t sum = 0, highest = 0;
    for (size_t i = 0; i < programmersAmount; i++) {

        cin >> programmers[i];
        sum += programmers[i];
        if (programmers[i] > highest) {
            highest = programmers[i];
        }
    }

    size_t best = highest, low = best, high = sum, lastBestSuccess = 0;

    while (low <= high) {
        int createdTeamsAmount = 0;
        size_t currentTeamSum = 0;

        for (size_t i = 0; i < programmersAmount; i++) {
            if (programmers[i] + currentTeamSum > best) {
                createdTeamsAmount++;
                currentTeamSum = 0;
            }
            currentTeamSum += programmers[i];
        }

        if (currentTeamSum > 0) {
            createdTeamsAmount++;
        }

        if (createdTeamsAmount > teamsAmount) {
            low = best + 1;
        }
        else {
            high = best - 1;
        }

        if (createdTeamsAmount == teamsAmount) {
            lastBestSuccess = best;
        }
        best = low + (high - low) / 2;
    }

    cout << lastBestSuccess;
}
