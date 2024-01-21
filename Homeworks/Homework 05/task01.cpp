#include <iostream>
#include <deque>

using namespace std;


int main() {
    size_t fightersAmount;
    cin >> fightersAmount;

    int* input = new int[fightersAmount];
    for (size_t i = 0; i < fightersAmount; i++) {
        cin >> input[i];
    }
    deque<int> positiveNumbers;

    int currentNumber;
    for (size_t i = 0; i < fightersAmount; ++i) {
        currentNumber = input[i];

        if (currentNumber > 0) {
            positiveNumbers.push_front(currentNumber);
            continue;
        }

        while (true) {
            if (positiveNumbers.empty()) {
                cout << currentNumber << ' ';
                break;
            }

            if (-currentNumber > positiveNumbers.front()) {
                positiveNumbers.pop_front();
                continue;
            }
            else if (-currentNumber == positiveNumbers.front()) {
                positiveNumbers.pop_front();
            }
            break;
        }
    }

    while (!positiveNumbers.empty()) {
        cout << positiveNumbers.back() << ' ';
        positiveNumbers.pop_back();
    }

    delete[] input;

    return 0;
}
