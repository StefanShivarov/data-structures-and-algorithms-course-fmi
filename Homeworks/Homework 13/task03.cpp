#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RoadSegment {
    int start, end, quality;
};

bool compareRoadSegments(const RoadSegment& a, const RoadSegment& b) {
    return a.end < b.end;
}

int maxTotalQuality(int numSegments, int maxOrders, vector<RoadSegment>& roadSegments) {
    sort(roadSegments.begin(), roadSegments.end(), compareRoadSegments);

    vector<int> maxQuality(numSegments + 1, 0);

    for (int i = 1; i <= numSegments; ++i) {
        maxQuality[i] = max(maxQuality[i - 1], roadSegments[i - 1].quality);

        for (int j = i - 1; j >= max(0, i - maxOrders); --j) {
            if (roadSegments[i - 1].start >= roadSegments[j].end) {
                maxQuality[i] = max(maxQuality[i], maxQuality[j] + roadSegments[i - 1].quality);
                break;
            }
        }
    }

    return maxQuality[numSegments];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numSegments, maxOrders;
    cin >> numSegments >> maxOrders;

    vector<RoadSegment> roadSegments(numSegments);

    for (int i = 0; i < numSegments; ++i) {
        cin >> roadSegments[i].start >> roadSegments[i].end >> roadSegments[i].quality;
    }

    int result = maxTotalQuality(numSegments, maxOrders, roadSegments);

    cout << result << endl;

    return 0;
}
