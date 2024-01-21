#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minSequence(const vector<int>& arr) {

    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    int start = 0, end = arr.size() - 1;

    while (start < arr.size() && arr[start] == sorted[start]) {
        start++;
    }

    while (end >= 0 && arr[end] == sorted[end]) {
        end--;
    }

    int seqLength = max(0, end - start + 1);

    return seqLength;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minSequence(arr);
}
