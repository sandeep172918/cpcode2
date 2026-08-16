// //Author:coding_with_alzheimer
// //Date: 2026-08-14 22:23

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
#define PI 3.14159265358979323846



// void solve(){
// lli n=0,k=0;string s;
// lli a,b,h;
// cin>>a>>b>>h;
// vector<double>p(90);
// frs(i,1,89){
//     double r=i*PI/180.0;
//     p[i]=tan(r);
// }
// double ans=(double)h;
// ans*=p[a];
// ans/=(p[a]+p[b]);
// cout<<setprecision(9)<<fixed<<ans<<'\n';
// }

// int32_t main(){
// fastio;
// lli test=1;
// cin>>test;
// while(test--){
// solve();
// }
// }

// #include <bits/stdc++.h>
// using namespace std;
typedef long long LL;
LL n, k;
LL p[20];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    cin >> k;

    LL n1 = max(n/2-2, 0LL);

    LL s = 0;
    LL e = 1100000000000000000LL;


    map<LL,LL> cnt;
    cnt[1] = 1;
    for(int j = 0; j < n1; j++){
        map<LL,LL> newcnt2;
        for(map<LL,LL>::iterator it = cnt.begin(); it != cnt.end(); it++){
            LL f = it->first;
            newcnt2[f] += it->second;
            while(f <= e/p[j]){
                f *= p[j];
                newcnt2[f] += it->second;
            }
        }
        cnt = newcnt2;
    }
    map<LL,LL> cnt2;
    cnt2[1] = 1;
    for(int j = n1; j < n; j++){
        map<LL,LL> newcnt2;
        for(map<LL,LL>::iterator it = cnt2.begin(); it != cnt2.end(); it++){
            LL f = it->first;
            newcnt2[f] += it->second;
            while(f <= e/p[j]){
                f *= p[j];
                newcnt2[f] += it->second;
            }
        }
        cnt2 = newcnt2;
    }

    for(auto &it:cnt2){
      cout<<it.ff<<' '<<it.ss<<'\n';
    }

    // find number of
    vector<pair<LL,LL> > p1;
    vector<pair<LL,LL> > p2;
    for(map<LL,LL>::iterator it = cnt.begin(); it != cnt.end(); it++){
        p1.push_back({it->first, it->second});
    }
    for(map<LL,LL>::iterator it = cnt2.begin(); it != cnt2.end(); it++){
        p2.push_back({it->first, it->second});
    }
    reverse(p1.begin(), p1.end());

    while(s + 1 < e){
        LL m = (s+e)/2;
        LL total = 0;
        LL sum = 0;
        LL b = 0;
        for(LL a = 0; a < p1.size(); a++){
            while(b < p2.size() && p1[a].first <= m / p2[b].first){
                sum += p2[b].second;
                b++;
            }
            total += sum * p1[a].second;
        }

        if(total >= k){
            e = m;
        } else {
            s = m;
        }
    }
    cout << e << endl;
}
