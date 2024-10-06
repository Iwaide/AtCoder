## mapのキーを使った累積和
- ABC371D Country https://atcoder.jp/contests/abc371/tasks/abc371_d

累積和の取り出し方に注意する
{ 0, 1 } , { 1, 2 }, { 3, 3 } , { 5, 4 }があるとき
累積和は{ 0, 1 } , { 1, 3 }, { 3, 6 } , { 5, 10 }になっている
2~4をとりたいとき、左: lower_bound取ってその1個前
右: upper_bound取ってその1個前
