#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t gradesInIntervalAmount(size_t* grades, size_t gradesAmount, size_t min, size_t max) {
    size_t* upper = upper_bound(grades, grades + gradesAmount, max);
    size_t* lower = lower_bound(grades, grades + gradesAmount, min);
    return size_t(upper - lower);
}

int main() {
    size_t gradesAmount, intervalsAmount;
    cin >> gradesAmount >> intervalsAmount;

    size_t grades[gradesAmount];
    size_t low, high;
    for (size_t i = 0; i < gradesAmount; ++i) {
        cin >> grades[i];
    }

    sort(grades, grades + gradesAmount);

    for (size_t i = 0; i < intervalsAmount; ++i) {
        cin >> low >> high;
        if (low > high) {
            cout << 0 << endl;
        }
        else {
            cout << gradesInIntervalAmount(grades, gradesAmount, low, high) << endl;
        }
    }
    return 0;

}
