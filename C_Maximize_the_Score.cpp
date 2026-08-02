//Author:coding_with_alzheimer
//Date: 2026-08-02 00:32

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

vll v;
vpr p;
vll dp;
lli n;

lli dpp(lli i){
    if(i>=2*n)return 0;
    if(dp[i]!=-1)return dp[i];
    lli l=p[v[i]].ff;
    lli r=p[v[i]].ss;
    lli k=r-l+1;
    lli ans=0;
    if(l==i){
        lli pick=k*k+dpp(r+1);
        lli nopick=1+dpp(l+1);
        ans=max(pick,nopick);
    }else{  //already got processed.
        lli nopick=1+dpp(i+1);
        ans=max(ans,nopick);
    }
    return dp[i]=ans;
}

void solve(){
cin>>n;
v=vll(2*n);
p=vpr(n,{-1,-1});
dp=vll(2*n,-1);
fr(i,2*n)cin>>v[i];
fr(i,2*n)v[i]--;
fr(i,2*n){
    if(p[v[i]].ff==-1){
       p[v[i]].ff=i;
    }else{
        p[v[i]].ss=i;
    }
}
cout<<dpp(0)<<'\n';
}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}