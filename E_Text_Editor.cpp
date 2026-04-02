//Author:coding_with_alzheimer
//Date: 2026-03-30 21:47

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long int
#define fr(i,n) for(lli i=0;i<n;i++)
#define frs(i,a,b) for(lli i=a;i<=b;i++)
#define rfr(i,b,a) for(lli i=b;i>=a;i--)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define pr pair<lli,lli>
#define vll vector<lli>
#define vbl vector<bool>
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define ff first
#define ss second
#define tr true
#define fs false
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sq(x) sqrtl(x)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define no1 cout<<"-1\n"
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const int MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//BSDK math snippet hai




vector<int> prep(string s) {
    int n = s.size();
    vector<int> pi(n, 0);

    int j = 0;
    for (int i = 1; i < n; i ++) {
        while (j && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) j ++;
        pi[i] = j;
    }

    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    int cur;

    getline(cin, s);
    getline(cin, t);
    cin >> cur;

    int n = s.size(), m = t.size();

    int l = 1, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;

        string tmp = t.substr(0, mid) + "#" + s;
        auto kmp = prep(tmp);

        int cnt = 0;
        for (auto &v: kmp) cnt += (v == mid);

        if (cnt >= cur) l = mid + 1;
        else r = mid - 1;
    }

    if (r) cout << t.substr(0, r);
    else cout << "IMPOSSIBLE";

    return 0;
}

