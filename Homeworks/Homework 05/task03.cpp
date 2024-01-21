#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

    size_t n;
    cin >> n;

    vector<int> numbers(n);
    for (size_t i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    stack<pair<int, int>> st;
    int temp, winner = 0, tempWinner;
    for (size_t i = 0; i < n; i++)
    {
        tempWinner = 0;
        temp = numbers[i];

        while (!st.empty() && st.top().first >= temp)
        {
            tempWinner = max(tempWinner, st.top().second);
            st.pop();
        }

        if (!st.empty())
        {
            st.top().second = max(tempWinner, st.top().second) + 1;
            winner = max(winner, st.top().second);
        }

        st.push({ temp, 0 });
    }

    cout << winner;

    return 0;
}
