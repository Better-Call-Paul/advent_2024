#include <iostream>
#include <vector>
#include <climits>
#include <limits>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

void solve() {


    bool turn = false;

    int curr;

    vector<int> left, right;

    while (cin >> curr) {
        vector<int>& target = (turn) ? left : right;

        target.push_back(curr);

        turn = !turn;
    }

    int n = left.size();

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += abs(left[i] - right[i]);
    }

    cout << total << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}