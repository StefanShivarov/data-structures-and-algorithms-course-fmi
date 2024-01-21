#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sum(size_t startIndex, size_t endIndex, const vector<int>& diffArr) {
    unordered_map<int, int> numberOfSubarraysMap;

    int result = 0, currentSum = 0;
    for (size_t i = startIndex; i < endIndex; i++) {
        currentSum += diffArr[i];

        if (currentSum == 0) {
            result++;
        }

        if (numberOfSubarraysMap.find(currentSum) != numberOfSubarraysMap.end()) {
            result += numberOfSubarraysMap[currentSum];
        }

        numberOfSubarraysMap[currentSum]++;
    }

    return result;
}

size_t numberOfSubarraysWithMedian(const vector<size_t>& input, size_t indexOfMedian) {
    size_t n = input.size();
    vector<bool> smaller(n, 0), greater(n, 0);
    vector<int> diff(n, 0);
    for (size_t i = 0; i < n; i++) {
        smaller[i] = input[i] < input[indexOfMedian];
        greater[i] = input[i] > input[indexOfMedian];
        diff[i] = smaller[i] - greater[i];
    }

    int subarraysFrom0ToN = sum(0, n, diff);
    int subarraysFrom0ToMedianIndex = sum(0, indexOfMedian, diff);
    int subarraysAfterMedianIndex = sum(indexOfMedian + 1, n, diff);

    return subarraysFrom0ToN - subarraysFrom0ToMedianIndex - subarraysAfterMedianIndex;
}

int main() {
    size_t arrLength, median;
    cin >> arrLength >> median;

    vector<size_t> input(arrLength);
    size_t indexOfMedian = 0;

    for (size_t i = 0; i < arrLength; i++) {
        cin >> input[i];
        if (input[i] == median) {
            indexOfMedian = i;
        }
    }

    cout << numberOfSubarraysWithMedian(input, indexOfMedian);

    return 0;
}
