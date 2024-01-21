#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Point {
    size_t x;
    size_t y;
};

bool areCollinear(const Point& a, const Point& b, const Point& c, const Point& d) {
    return (b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x) &&
        (c.y - b.y) * (d.x - c.x) == (d.y - c.y) * (c.x - b.x);
}

size_t crossProduct(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

bool isParallelogram(const Point& a, const Point& b, const Point& c, const Point& d) {
    Point ABVector = { b.x - a.x, b.y - a.y };
    Point CDVector = { d.x - c.x, d.y - c.y };
    Point ACVector = { c.x - a.x, c.y - a.y };
    Point BDVector = { d.x - b.x, d.y - b.y };

    if (crossProduct(ABVector, CDVector) == 0 && crossProduct(ACVector, BDVector) == 0) {
        return true;
    }

    return false;
}

size_t countParallelograms(vector<Point>& points) {
    size_t n = points.size();
    size_t count = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            for (size_t k = j + 1; k < n; ++k) {
                for (size_t l = k + 1; l < n; ++l) {
                    if (isParallelogram(points[i], points[j], points[k], points[l])
                        && !areCollinear(points[i], points[j], points[k], points[l])) {

                        count++;
                    }
                }
            }
        }
    }

    return count;
}

vector<Point> findXPoints(size_t N, size_t M, vector<vector<char>>& matrix) {
    vector<Point> xPoints;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            if (matrix[i][j] == 'x') {
                xPoints.push_back({ i, j });
            }
        }
    }

    return xPoints;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N, M;
    cin >> N >> M;

    vector<vector<char>> matrix(N, vector<char>(M));

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }
    vector<Point> xPoints = findXPoints(N, M, matrix);
    cout << countParallelograms(xPoints);

    return 0;
}
