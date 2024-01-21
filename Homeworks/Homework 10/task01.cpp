#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

void findFire(vector<vector<int>>& forest, int i, int j, set<pair<int, int>>& fire) {
    if (i < 0 || j < 0 || i >= forest.size() || j >= forest[0].size() || forest[i][j] == 0) {
        return;
    }

    fire.insert({ i, j });
    forest[i][j] = 0;

    findFire(forest, i + 1, j, fire);
    findFire(forest, i - 1, j, fire);
    findFire(forest, i, j + 1, fire);
    findFire(forest, i, j - 1, fire);
}

void findBounds(int& minI, int& minJ, int& maxI, int& maxJ, const set<pair<int, int>>& fire) {
    for (const auto& pair : fire) {
        if (pair.first < minI) {
            minI = pair.first;
        }
        if (pair.first > maxI) {
            maxI = pair.first;
        }
        if (pair.second < minJ) {
            minJ = pair.second;
        }
        if (pair.second > maxJ) {
            maxJ = pair.second;
        }
    }
}

vector<int> calculateFireAreas(vector<vector<int>>& forest) {
    vector<int> areas;

    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest[0].size(); j++) {
            if (forest[i][j] == 1) {
                int maxI = 0, maxJ = 0, minI = INT_MAX, minJ = INT_MAX;
                set<pair<int, int>> fire;
                findFire(forest, i, j, fire);
                findBounds(minI, minJ, maxI, maxJ, fire);
                int area = (maxI - minI + 1) * (maxJ - minJ + 1);
                areas.push_back(area);
            }
        }
    }

    sort(areas.rbegin(), areas.rend());

    return areas;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> forest(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    vector<int> result = calculateFireAreas(forest);

    for (int area : result) {
        cout << area << " ";
    }

    return 0;
}
