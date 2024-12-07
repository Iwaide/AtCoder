#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstdint> // for uint64_t

using namespace std;

// エラトステネスの篩で素数を生成する関数
vector<uint64_t> sieve_of_eratosthenes(uint64_t limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (uint64_t i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (uint64_t j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<uint64_t> primes;
    for (uint64_t i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// 正の約数が9個の整数を列挙する関数
vector<uint64_t> enumerate_divisors_9(uint64_t limit) {
    uint64_t sqrt_limit = static_cast<uint64_t>(sqrt(limit));
    vector<uint64_t> primes = sieve_of_eratosthenes(sqrt_limit);
    set<uint64_t> results;

    // Case 1: n = p^8
    for (uint64_t p : primes) {
        uint64_t n = 1;
        for (int i = 0; i < 8; ++i) {
            if (n > limit / p) {
                n = 0; // オーバーフロー回避
                break;
            }
            n *= p;
        }
        if (n > 0 && n <= limit) {
            results.insert(n);
        }
    }

    // Case 2: n = p1^2 * p2^2
    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i + 1; j < primes.size(); ++j) {
            uint64_t p1_square = primes[i] * primes[i];
            if (p1_square > limit / primes[j] / primes[j]) break; // オーバーフロー回避
            uint64_t n = p1_square * (primes[j] * primes[j]);
            if (n > limit) break;
            results.insert(n);
        }
    }

    return vector<uint64_t>(results.begin(), results.end());
}

int main() {
    uint64_t limit; // 探索範囲の上限
    cin >> limit;
    vector<uint64_t> results = enumerate_divisors_9(limit);

    // 結果を出力
    cout << results.size() << endl;
}
