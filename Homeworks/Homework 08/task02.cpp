#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int friendsAmount;
    cin >> friendsAmount;
    priority_queue<int, vector<int>, greater<int>> chairs;

    for (int i = 0; i < friendsAmount; i++) {
        chairs.push(i);
    }

    vector<tuple<int, int, bool>> friends(friendsAmount);
    for (int i = 0; i < friendsAmount; i++) {
        int a, l;
        cin >> a >> l;
        friends[i] = make_tuple(a, l, false);
    }

    int t;
    cin >> t;

    int a = get<0>(friends[t]);
    int l = get<1>(friends[t]);
    friends[t] = make_tuple(a, l, true);
    sort(friends.begin(), friends.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < friendsAmount; ++i) {
        if (pq.empty() || get<0>(friends[i]) < pq.top().first) {
            pq.push({ get<1>(friends[i]), chairs.top() });
            if (get<2>(friends[i])) {
                cout << chairs.top();
                break;
            }
            chairs.pop();
        }
        else {
            while (!pq.empty() && get<0>(friends[i]) >= pq.top().first) {
                chairs.push(pq.top().second);
                pq.pop();
            }

            pq.push({ get<1>(friends[i]), chairs.top() });

            if (get<2>(friends[i])) {
                cout << chairs.top();
                break;
            }
            chairs.pop();
        }

    }

    return 0;
}