二分探索:
```cpp
lower_bound(a.begin(), a.end(), key)
```

大文字小文字判定
isupper(char);
islower
isdigit

大文字小文字変換
(char)('x' + ('A' - 'a'))
これtolower, toupperでよかった

アルファベット何文字目か、をやるとき
(int)(c - 'A')

# char to int
int (c - '0')
int to char
to_string(i)

文字列 S から連続する重複した文字を削除する
S.erase(unique(S.begin(), S.end()), S.end());
https://qiita.com/takuya000885/items/3ead0668127033070b65

```cpp
auto n = unique(s.begin(), s.end());
// これで s = abcda となってほしい
cout << s << '\n';//しかし s = abcda?????? とゴミが残る

// unique は返り値として ? の先頭を指すポインタを返す
// そこで n から最後まで erase すれば完成
s.erase(n,s.end());
```
