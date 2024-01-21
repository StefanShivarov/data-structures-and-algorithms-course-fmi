#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

class MedianFinder {
    priority_queue<double, vector<double>, greater<double>> minHeap;
    priority_queue<double> maxHeap;
public:
    MedianFinder() {}

    void addNum(double num) {
        if (maxHeap.empty() or maxHeap.top() > num) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty()) {
                return 0;
            }
            return (maxHeap.top() + minHeap.top()) / 2.0;;
        }
        else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};

int main() {

    cout << fixed << setprecision(1);

    MedianFinder* medianFinder = new MedianFinder();

    size_t numbersAmount;
    cin >> numbersAmount;

    for (size_t i = 0; i < numbersAmount; i++) {
        double num;
        cin >> num;
        medianFinder->addNum(num);
        cout << medianFinder->findMedian() << endl;
    }

    return 0;
}
