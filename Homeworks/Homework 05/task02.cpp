#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    stack<int> heightsStack;

    int maxArea = 0;
    for (int i = 0; i <= n; i++) {
        while (!heightsStack.empty() && (i == n || input[heightsStack.top()] >= input[i])) {
            int height = input[heightsStack.top()];
            heightsStack.pop();
            int width;
            if (heightsStack.empty()) {
                width = i;
            }
            else {
                width = i - heightsStack.top() - 1;
            }
            maxArea = max(maxArea, width * height);
        }
        heightsStack.push(i);
    }

    cout << maxArea;
}
