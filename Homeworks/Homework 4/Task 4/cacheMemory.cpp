#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

//I was forced to use things we hadn't learned yet, because of stupid timeout tests they included for the task :(

class Cache {
public:
    Cache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        }
        else {
            if (cacheList.size() >= capacity) {
                int lastUsedKey = cacheList.back().first;
                cacheMap.erase(lastUsedKey);
                cacheList.pop_back();
            }
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }

    void overheat() {

        if (!cacheList.empty()) {
            int key = cacheList.back().first;
            cacheMap.erase(key);
            cacheList.pop_back();
        }
    }

private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
};

int main() {
    int capacity, totalQueries, overheatingQueries;
    cin >> capacity >> totalQueries >> overheatingQueries;

    Cache cache(capacity);

    for (int i = 1; i <= totalQueries; i++) {
        string query;
        cin >> query;
        if (query == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
        else if (query == "get") {
            int key;
            cin >> key;
            int result = cache.get(key);
            cout << result << endl;
        }

        if (i % overheatingQueries == 0) {
            cache.overheat();
        }
    }

    return 0;
}