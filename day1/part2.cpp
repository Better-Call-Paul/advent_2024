#include <iostream>
#include <vector>
#include <climits>
#include <limits>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;

using namespace std;

void solve() {

    int curr;
    bool turn = false;
    unordered_map<int, int> left, right;
    unordered_set<int> in_left;

    while (cin >> curr) {
        if (!turn) {
            left[curr]++;
            in_left.insert(curr);
        }
        else {
            right[curr]++;
        }
        turn = !turn;
    }

    ll score = 0;
    for (const auto& val : in_left) {
        if (right.find(val) != right.end()) {
            ll score_per_num = val * right[val];
            score += left[val] * score_per_num;
        }
    }
    cout << score << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}