#include <bits/stdc++.h>
using namespace std;

int N;
string S;

char win(char c) {
    if (c == 'R') return 'P';
    else if (c == 'P') return 'S';
    else return 'R';
}

int main() {
    cin >> N >> S;
    
    // dp[i][j]: i回目のジャンケンで手j（0: 'R', 1: 'P', 2: 'S'）を出した時の勝利回数の最大値
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));

    for (int i = 0; i < N; ++i) {
        char a_hand = S[i];
        char next_winning_hand = win(a_hand);

        int next_winning_hand_index = (next_winning_hand == 'R') ? 0 : (next_winning_hand == 'P') ? 1 : 2;
        int a_hand_index = (a_hand == 'R') ? 0 : (a_hand == 'P') ? 1 : 2;

        for (int j = 0; j < 3; ++j) {
            if (j != next_winning_hand_index) {
                dp[i + 1][next_winning_hand_index] = max(dp[i + 1][next_winning_hand_index], dp[i][j] + 1);
            }
            if (j != a_hand_index) {
                dp[i + 1][a_hand_index] = max(dp[i + 1][a_hand_index], dp[i][j]);
            }
        }
    }

    int maxVictory = max({dp[N][0], dp[N][1], dp[N][2]});
    cout << maxVictory << endl;

    return 0;
}
