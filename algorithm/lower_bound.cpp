#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (a[mid] >= key) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main() {
    cout << binary_search(51) << endl; // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
    cout << binary_search(1) << endl; // a[0] = 1
    cout << binary_search(910) << endl; // a[9] = 910

    cout << binary_search(52) << endl; // 6
    cout << binary_search(0) << endl; // 0
    cout << binary_search(911) << endl; // 10 (場外)
}