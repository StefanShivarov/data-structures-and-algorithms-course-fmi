#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Point {

    int x;
    int y;
    int touristX;
    int touristY;

    Point() : x(0), y(0), touristX(0), touristY(0) {}
    Point(int x, int y, const Point& tourist) : x(x), y(y), touristX(tourist.x), touristY(tourist.y) {}

    double distanceTo(const Point& other) const {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    double distanceTo(int x, int y) const {
        return sqrt(pow(x - this->x, 2) + pow(y - this->y, 2));
    }

    bool operator<(const Point& other) const {
        double d1 = distanceTo(touristX, touristY);
        double d2 = other.distanceTo(touristX, touristY);

        if (d1 == d2) {
            return (x == other.x) ? (other.y < y) : (other.x < x);
        }

        return d2 < d1;
    }

    void print() const {
        cout << x << " " << y << endl;
    }
};

int main() {

    Point tourist;
    size_t pointsAmount, pointsOfInterest;
    cin >> tourist.x >> tourist.y >> pointsAmount >> pointsOfInterest;

    priority_queue<Point, vector<Point>, less<Point>> pq;

    for (size_t i = 0; i < pointsAmount; i++) {
        int x, y;
        cin >> x >> y;
        Point point(x, y, tourist);
        pq.push(point);
    }

    for (size_t i = 0; i < pointsOfInterest; i++) {
        pq.top().print();
        pq.pop();
    }
}
