#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    long long K;
    cin >> S >> K;
    // 連続した個数を数え上げる
    vector<long long> v;
    for (int i = 0; i < S.size();) {
        int j = i;
        while (j < S.size() && S[j] == S[i]) ++j;
        v.push_back(j - i);
        i = j;
    }
    if (S[0] != S.back()) {
        long long sum = 0;
        for (auto c : v) sum += c/2;
        cout << sum * K << endl;
    }
    else {
        if (v.size() == 1) cout << v[0] * K / 2 << endl;
        else {
            long long left = v[0], right = v.back(), mid = 0;
            for (int i = 1; i+1 < v.size(); ++i) mid += v[i]/2;
            cout << mid*K + (left+right)/2 * (K-1) + left/2 + right/2 << endl;
        }
    }
}
