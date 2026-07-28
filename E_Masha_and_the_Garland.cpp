//Author:coding_with_alzheimer
//Date: 2026-07-28 23:41

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



void solve(){
lli n=0,k=0;string s;
cin>>n>>k;
//get(v,n);
cin>>s;
vll a(n+1);
vll b(n+1);
string ss="";
fr(i,n){
    if(i&1)ss+='0';
    else ss+='1';
    a[i+1]=(ss[i]!=s[i]);
    ss[i]='1'+'0'-ss[i];
    b[i+1]=(ss[i]!=s[i]);
}
a.psb(0);
b.psb(0);
vll l,l1,r,r1;
lli curr=0;
frs(i,1,n){
  if(a[i]==1)curr++;
  else{
    if(curr){
      lli rr=i-1;
      lli ll=i-1-curr+1;
      l.psb(ll);
      r.psb(rr);
    }
    curr=0;
  }
}
curr=0;
frs(i,1,n){
  if(b[i]==1)curr++;
  else{
    if(curr){
      lli rr=i-1;
      lli ll=i-1-curr+1;
      l1.psb(ll);
      r1.psb(rr);
    }
    curr=0;
  }
}

fr(i,k){
    lli x,y,kk;
    cin>>x>>y>>kk;
    lli ll=lower_bound(all(l),x)-l.begin();
    lli rr=upper_bound(all(r),y)-r.begin()-1;
    if((rr-ll+1)<=kk){
        yes;
        continue;
    }
    ll=lower_bound(all(l1),x)-l1.begin();
    rr=upper_bound(all(r1),y)-r1.begin()-1;
    if((rr-ll+1)<=kk){
        yes;
    }else no;
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