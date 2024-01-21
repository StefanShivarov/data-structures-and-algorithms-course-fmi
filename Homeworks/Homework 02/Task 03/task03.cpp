#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct BoyData {

    double diameter;
    double time;
    int index;

    double efficiency() const {
        return (diameter * diameter) / time;
    }

    double compareTo(const BoyData& other) const {

        double result = this->efficiency() - other.efficiency();

        if (result == 0) {
            return this->diameter - other.diameter;
        }

        return result;
    }

};

bool operator<(const BoyData& b1, const BoyData& b2) {

    return b1.compareTo(b2) > 0;
}


int main() {

    int boysAmount;
    cin >> boysAmount;

    vector<BoyData> boysDataArr(boysAmount);

    for (int i = 0; i < boysAmount; i++) {
        cin >> boysDataArr[i].diameter >> boysDataArr[i].time;
        boysDataArr[i].index = i + 1;
    }

    sort(boysDataArr.begin(), boysDataArr.end());

    for (int i = 0; i < boysAmount; i++) {
        cout << boysDataArr[i].index << " ";
    }

}
