## 決め打ち二分探索
最小値を最大化、最大値を最小化する問題に使いやすい。
答えとなる値を仮で決め打ちして、その値が達成可能かを判定しながら二分探索する。

- ABC374E
https://atcoder.jp/contests/abc374/tasks/abc374_e

この問題では2つの機械の生産能力が交換可能なときの最大台数についても触れている
Si: Ai個/台, Ti: Bi個/台のとき
SiのほうがコスパがいいときTiの台数はAi台以下となる
= Tiの台数Ai台 * Bi個 / 台 は SiのBi台 * Ai個 / 台で交換可能なため
Tiのほうがコスパが良いときにも同じことが言えるため、両方のケースを計算すればよい
