#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long S;
    int q;
    cin >> S >> q;

    // 1. Find all divisors of S
    vector<long long> d;
    d.push_back(0); // 0 is added to 1-index the divisors cleanly
    for (long long i = 1; i * i <= S; ++i) {
        if (S % i == 0) {
            d.push_back(i);
            if (i * i != S) {
                d.push_back(S / i);
            }
        }
    }
    sort(d.begin(), d.end());

    int k = d.size() - 1;
    
    // 2. Precompute the area under the step function (prefix sums)
    vector<long long> pref(k + 1, 0);
    for (int m = 1; m <= k; ++m) {
        // Area of the current step: width * height
        pref[m] = pref[m - 1] + (d[m] - d[m - 1]) * (S / d[m]);
    }

    // Helper lambda to calculate the area under the step function up to coordinate X
    auto get_P = [&](long long X) -> long long {
        if (X == 0) return 0;
        // Find the largest divisor d_m <= X
        auto it = upper_bound(d.begin(), d.end(), X);
        int idx = distance(d.begin(), it) - 1;
        
        long long ans = pref[idx];
        // Add the partial block if X is between divisors
        if (X > d[idx]) {
            ans += (X - d[idx]) * (S / d[idx + 1]);
        }
        return ans;
    };

    // 3. Process Queries
    for (int i = 0; i < q; ++i) {
        long long x, y;
        cin >> x >> y;

        // X_y is the largest divisor <= S / y
        long long target = S / y;
        auto it = upper_bound(d.begin(), d.end(), target);
        int idx = distance(d.begin(), it) - 1;
        long long X_y = d[idx];

        // Intersection boundary
        long long x_prime = min(x, X_y);

        // Total area = area cut off by y + area naturally under the step function
        long long ans = x_prime * y + get_P(x) - get_P(x_prime);
        cout << ans << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed (crucial for q up to 3*10^5)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}