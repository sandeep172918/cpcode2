//Author:coding_with_alzheimer
//Date: 2026-08-12 23:27

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

lli check(vll &a,vll &b,lli mid){
    lli c=0;
    fr(i,a.size()){
      if(a[i]>=mid)break;
      c+=mid-a[i];
    }
    rfr(i,b.size()-1,0){
        if(b[i]<=mid)break;
        c+=b[i]-mid;
    }
    return c;
}

void solve(){
lli n=0,k=0,m;string s;
cin>>n>>m;
get(a,n);
get(b,m);
srt(a);
srt(b);
lli low=0,high=1e12;
lli t=200;
while(t--){
  lli m1=low+(high-low)/3;
  lli m2=high-(high-low)/3;
  lli f1=check(a,b,m1);
  lli f2=check(a,b,m2);
  if(f1<f2){
    high=m2;
  }else if(f1>f2){
    low=m1;
  }else{
   low=m1;
   high=m2;
  }
}
cout<<check(a,b,low+1)<<'\n';
}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}