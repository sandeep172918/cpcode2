//Author:coding_with_alzheimer
//Date: 2026-08-13 16:28

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

lli n,a,r,m;
vll v;

lli check(lli x){
  lli pt=0,rm=0;
  fr(i,v.size()){
    if(v[i]>x){
       rm+=v[i]-x;
    }else if(v[i]<x){
       pt+=x-v[i];
    }
  }
  lli curr=rm*r+pt*a;
   if(rm<=pt){
    curr=min(curr,rm*m+(pt-rm)*a);
   }else{
    curr=min(curr,pt*m+(rm-pt)*r);
   }
   return curr;
}

void solve(){
lli n=0,k=0;string s;
cin>>n>>a>>r>>m;
v=vll(n);
fr(i,n)cin>>v[i];
lli low=0,high=1e10;
lli t=300;
while(t--){
    lli m1=low+(high-low)/3;
    lli m2=high-(high-low)/3;
    lli f1=check(m1);
    lli f2=check(m2);
    if(f1>f2){
       low=m1;
    }else if(f1<f2){
       high=m2;
    }else{
        low=m1;
        high=m2;
    }
}
lli ans=1e18;
frs(i,low+1,high){
    // cout<<check(i)<<'\n';
    ans=min(ans,check(i));
}
cout<<check(low+1)<<'\n';
// cout<<ans<<'\n';
}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}