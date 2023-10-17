#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int p;
    cin >> p;
    int k;
    cin >> k;
    vector<int> arr;
    for (int i = 0; i < p; i++) {
        int num;
        cin >> num;

        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int min = arr[p - 1] - arr[0];
    int index = 0;
    while (k <= p) {
        int diff = arr[k - 1] - arr[index];
        if (diff < min) {
            min = diff;
        }
        index++;
        k++;
    }
    cout << min;
    return 0;
}
