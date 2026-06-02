#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N, M;
        cin >> N >> M;

        long long ans = 0;

        long long p10mod = 1 % M;
        long long pow10 = 1;

        for (int d = 1; ; d++) {
            p10mod = (i128)p10mod * 10 % M;

            long long L = pow10;
            long long R;

            if (pow10 > N) break;

            if (pow10 > LLONG_MAX / 10)
                R = N;
            else
                R = min(N, pow10 * 10 - 1);

            long long cntY = R - L + 1;

            long long g = gcd(M, (p10mod - 1 + M) % M);
            long long need = M / g;

            long long cntX = N / need;

            ans = (ans + (__int128)(cntY % MOD) * (cntX % MOD)) % MOD;

            if (pow10 > N / 10) break;
            pow10 *= 10;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}