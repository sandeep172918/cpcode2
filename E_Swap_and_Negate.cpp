//Author:coding_with_alzheimer
//Date: 2026-10-31 21:17

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
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define ff first
#define ss second
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define psbp(a,b) push_back({a,b})
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define no1 cout<<"-1\n"
#define pn(x) cout<<(x)<<"\n"
#define pt(x) cout<<(x)<<" "
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
#define arr(a) array<lli,a>
using namespace std;
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



void solve(){
lli n=0,k=0,ans=0;
array<lli,1>arr;
string s;
cin>>n;
get(v,n);
if(n==1){
    cout<<v[0]<<'\n';
}
else if(n==2){
   cout<<abs(v[0]+v[1])<<'\n';
}else{
    lli x=0;
    lli y=1e18;
    fr(i,n){
        ans+=abs(v[i]);
        if(v[i]<0)x++;
        y=min(y,abs(v[i]));
    }
    if(x&1)cout<<ans-2*y<<'\n';
    else cout<<ans<<'\n';
}
}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}