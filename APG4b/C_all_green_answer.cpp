#include <bits/stdc++.h>
using namespace std;

int MinPro(vector<int> &p, vector<int> &c, vector<bool> com, int n, int &d, int &g) {
    if (n == d) {
        int score = 0;
        int nSolve = 0;
        for (int i = 0; i < d; i++) {
            if (com.at(i)) {
                score += p.at(i) * 100 * (i+1);
                score += c.at(i);
                nSolve += p.at(i);
            }
        }
        if (score >= g) return nSolve;
        for (int i = d-1; i >= 0; i--) {
            if (!com.at(i)) {
                int tmp = (g-score+(i+1)*100-1) / ((i+1)*100);
                if (p.at(i) > tmp) return nSolve + tmp;
            }
        }
        return 1000000;
    }
    com.at(n) = true;
    int tmp1 = MinPro(p,c,com,n+1,d,g);
    com.at(n) = false;
    int tmp2 = MinPro(p,c,com,n+1,d,g);
    return min(tmp1,tmp2);
}

int main() {
    int d, g;
    cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    vector<bool> com(d);
    for (int i = 0; i < d; i++) {
        cin >> p.at(i) >> c.at(i);
        com.at(i) = false;
    }

    cout << MinPro(p,c,com,0,d,g) << endl;
}