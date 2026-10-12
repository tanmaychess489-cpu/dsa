#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> memo;

string clean(string s) {
    bool changed = true;
    while (changed) {
        changed = false;
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (j < (int)s.size() && s[j] == s[i]) j++;
            if (j - i >= 3) {
                s.erase(i, j - i);
                changed = true;
                break;
            }
            i = j;
        }
    }
    return s;
}

int solve(string board, string hand) {
    if (board == "") return 0;
    if (hand == "") return 100;

    string key = board + "#" + hand;
    if (memo.count(key)) return memo[key];

    int best = 100;
    int n = board.size();

    for (int j = 0; j < (int)hand.size(); j++) {
        if (j > 0 && hand[j] == hand[j - 1]) continue;

        string rest = hand;
        rest.erase(j, 1);

        for (int i = 0; i <= n; i++) {
            if (i > 0 && board[i - 1] == hand[j]) continue;

            bool sameNext = (i < n && board[i] == hand[j]);
            bool betweenPair = (i > 0 && i < n && board[i - 1] == board[i] && board[i] != hand[j]);

            if (sameNext || betweenPair) {
                string next = board;
                next.insert(i, 1, hand[j]);
                next = clean(next);
                best = min(best, 1 + solve(next, rest));
            }
        }
    }

    memo[key] = best;
    return best;
}

int main() {
    string board, hand;
    cout << "Enter the board string: ";
    cin >> board;
    cout << "Enter the hand string: ";
    cin >> hand;
    sort(hand.begin(), hand.end());
    int ans = solve(board, hand);
    if (ans >= 100) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
