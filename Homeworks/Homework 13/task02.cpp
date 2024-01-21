#include <iostream>
#include <vector>

using namespace std;

size_t countOfNumbers(const vector<size_t>& arr, size_t l, size_t r, size_t d) {
    size_t count = 0;
    for (size_t i = l - 1; i < r; ++i) {
        if (arr[i] % d == 0 || d % arr[i] == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N, Q;
    cin >> N >> Q;

    vector<size_t> numbers(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    for (size_t i = 0; i < Q; ++i) {
        size_t l, r, d;
        cin >> l >> r >> d;
        cout << countOfNumbers(numbers, l, r, d) << " ";
    }

    return 0;
}
