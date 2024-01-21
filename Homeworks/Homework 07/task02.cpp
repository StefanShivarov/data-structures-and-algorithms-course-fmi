#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {

    size_t bound, numbersAmount;
    cin >> bound >> numbersAmount;

    vector<size_t> missingNumbers, input(numbersAmount), result;
    vector<bool> visited(bound + 1, false);

    for (size_t i = 0; i < input.size(); i++) {
        cin >> input[i];
        visited[input[i]] = true;
    }

    for (size_t i = 1; i <= bound; i++) {
        if (!visited[i]) {
            missingNumbers.push_back(i);
        }
    }

    input.push_back(numeric_limits<size_t>::max());
    missingNumbers.push_back(numeric_limits<size_t>::max());

    size_t currentElementIndex = 0, missingElementIndex = 0;
    for (size_t i = 0; i < bound; i++) {
        if (missingNumbers[missingElementIndex] > input[currentElementIndex]) {
            cout << input[currentElementIndex] << ' ';
            currentElementIndex++;
        }
        else {
            cout << missingNumbers[missingElementIndex] << ' ';
            missingElementIndex++;
        }
    }

    return 0;
}
