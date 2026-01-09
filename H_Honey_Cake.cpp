//Author: sandeep172918
//Date: 2025-12-17 13:43

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
 
vll get_d(lli x){
    vll temp;
    for(lli i=1;i*i<=x;i++){
        if(x%i==0){
            temp.psb(i);
            if(i*i!=x)temp.psb(x/i);
        }
    }
    srt(temp);
    return temp;
}
void solve(){
lli w,h,d;cin>>w>>h>>d;
lli n;cin>>n;
n=(__int128)n;
vll ww=get_d(w);
vll hh=get_d(h);
vll dd=get_d(d);
__int128 cc=w*h*d;
for (auto i :ww) {
    for (auto j :hh) {
        __int128 prod = (__int128)i * j * n;
        if (cc % prod != 0) continue;

        lli k = cc / prod;
        if (d % k == 0) {
            cout << (w/i - 1) << " "<< (h/j - 1) << " " << (d/k - 1) << "\n";
            return;
        }
    }
}
no1;

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}