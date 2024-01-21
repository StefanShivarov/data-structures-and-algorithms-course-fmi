#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t minXor = numeric_limits<size_t>::max();

    size_t n;
    cin >> n;

    set<size_t> numbers;
    numbers.insert(0);

    for (size_t i = 0; i < n; i++) {
        size_t num;
        cin >> num;

        auto iterPair = numbers.insert(num);
        if (!iterPair.second) {
            if (numbers.size() == 1) {
                cout << 0 << endl;
                continue;
            }
            cout << minXor << endl;
            continue;
        }

        auto iter = iterPair.first;

        minXor = min(minXor, (*iter) ^ (*prev(iter)));
        if (next(iter) != numbers.end()) {
            minXor = min(minXor, (*iter) ^ (*next(iter)));
        }

        cout << minXor << endl;
    }

    return 0;
}
