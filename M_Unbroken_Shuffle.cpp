// //Author:coding_with_alzheimer
// //Date: 2026-08-18 20:13

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define lli long long int
// #define fr(i,n) for(lli i=0;i<n;i++)
// #define frs(i,a,b) for(lli i=a;i<=b;i++)
// #define rfr(i,b,a) for(lli i=b;i>=a;i--)
// #define srt(v) sort(v.begin(),v.end())
// #define rsrt(v) sort(v.rbegin(),v.rend())
// #define pr pair<lli,lli>
// #define vll vector<lli>
// #define vbl vector<bool>
// #define vpr vector<pr>
// #define vvll vector<vector<lli>>
// #define get(v,n) vll v(n);fr(i,n)cin>>v[i]
// #define ff first
// #define ss second
// #define tr true
// #define fs false
// #define bitc(x) __builtin_popcountll(x)
// #define mxe(v)  *max_element(v.begin(),v.end())
// #define mne(v)  *min_element(v.begin(),v.end())
// #define psb(a) push_back(a)
// #define ppb pop_back()
// #define all(v) v.begin(),v.end()
// #define rall(v) v.rbegin(),v.rend()
// #define sq(x) sqrtl(x)
// #define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
// #define yes cout<<"YES\n"
// #define no cout<<"NO\n"
// #define no1 cout<<"-1\n"
// #define nl cout<<"\n"
// #define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
// #define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
// using namespace std;
// const lli MOD=998244353;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// vll v;
// void pre(){
//     lli n=5e5+18;
//     v=vll(n);
//     vll f(n);
//     f[0]=f[1]=1;
//     frs(i,2,n-1){
//       f[i]=(f[i-1]*i)%MOD;
//     }

    
// }
// void solve(){
// lli n=0,k=0;string s;
// cin>>n;
// cout<<v[n]<<'\n';
// }

// int32_t main(){
// fastio;
// lli test=1;
// pre();
// cin>>test;
// while(test--){
// solve();
// }
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int P = 998244353;
const int G = 3;

int power(int a, int b) {
    int res = 1;
    a %= P;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return res;
}

void ntt(vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = power(G, (P - 1) / len);
        if (invert)
            wlen = power(wlen, P - 2);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = 1LL * a[i + j + len / 2] * w % P;
                a[i + j] = (u + v >= P ? u + v - P : u + v);
                a[i + j + len / 2] = (u - v < 0 ? u - v + P : u - v);
                w = 1LL * w * wlen % P;
            }
        }
    }
    if (invert) {
        int n_inv = power(n, P - 2);
        for (int& x : a)
            x = 1LL * x * n_inv % P;
    }
}

void poly_inv(const vector<int>& a, vector<int>& b, int n) {
    b.assign(1, power(a[0], P - 2));
    int len = 1;
    while (len < n) {
        len <<= 1;
        vector<int> A(a.begin(), a.begin() + min((int)a.size(), len));
        A.resize(2 * len, 0);
        vector<int> B = b;
        B.resize(2 * len, 0);
        ntt(A, false);
        ntt(B, false);
        for (int i = 0; i < 2 * len; ++i) {
            B[i] = 1LL * B[i] * (2LL - 1LL * A[i] * B[i] % P + P) % P;
        }
        ntt(B, true);
        B.resize(len);
        b = B;
    }
    b.resize(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int MAXN = 500005;
    vector<int> c(MAXN);
    int fact = 1;
    for (int i = 0; i < MAXN; i++) {
        fact = 1LL * fact * (i + 1) % P;
        c[i] = fact;
    }

    vector<int> inv_c;
    poly_inv(c, inv_c, MAXN);

    int q;
    if (cin >> q) {
        while (q--) {
            int n;
            cin >> n;
            if (n == 1) {
                cout << 1 << "\n";
            } else {
                int ans = (P - inv_c[n - 1]) % P;
                cout << ans << "\n";
            }
        }
    }
    return 0;
}