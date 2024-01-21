#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    size_t papayasAmount, minPower;
    cin >> papayasAmount >> minPower;

    priority_queue<size_t, vector<size_t>, greater<size_t>> papayas;

    for (size_t i = 0; i < papayasAmount; i++) {
        size_t power;
        cin >> power;
        papayas.push(power);
    }

    size_t result = 0;
    bool achieved = false;
    while (true) {

        if (papayas.top() >= minPower) {
            achieved = true;
            break;
        }

        if (papayas.size() < 2 && papayas.top() < minPower) {
            break;
        }

        size_t s1 = papayas.top();
        papayas.pop();

        size_t s2 = papayas.top();
        papayas.pop();

        size_t s3 = s1 + 2 * s2;
        papayas.push(s3);
        result++;


    }

    if (achieved) {
        cout << result;
    }
    else {
        cout << -1;
    }

    return 0;

}
