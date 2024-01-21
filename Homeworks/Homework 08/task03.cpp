#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Group {

    size_t peopleInGroup;
    size_t getOn;
    size_t getOff;

    Group(size_t peopleAmount, size_t getOn, size_t getOff) : peopleInGroup(peopleAmount), getOn(getOn), getOff(getOff) {}
};

bool canTakeOnBoard(const vector<Group>& groups, size_t busCapacity) {

    vector<pair<int, int>> events;

    for (const auto& group : groups) {
        events.emplace_back(group.getOn, group.peopleInGroup);
        events.emplace_back(group.getOff + 1, -(int)group.peopleInGroup);
    }

    sort(events.begin(), events.end());

    size_t occupiedCapacity = 0;
    for (const auto& event : events) {
        occupiedCapacity += event.second;

        if (occupiedCapacity > busCapacity) {
            return false;
        }
    }

    return true;
}

int main() {
    size_t queriesAmount;
    cin >> queriesAmount;

    size_t groupsAmount, busCapacity;
    while (queriesAmount-- > 0) {
        cin >> groupsAmount >> busCapacity;
        vector<Group> groups;

        size_t peopleInGroup, getOnBus, getOffBus;
        for (size_t i = 0; i < groupsAmount; i++) {
            cin >> peopleInGroup >> getOnBus >> getOffBus;
            groups.push_back(Group(peopleInGroup, getOnBus, getOffBus));
        }

        cout << canTakeOnBoard(groups, busCapacity) << endl;
    }

}