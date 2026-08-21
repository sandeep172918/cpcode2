//Author:coding_with_alzheimer
//Date: 2026-08-21 16:03

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
#define out(v) fr(i,v.size())cout<<v[i]+1<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
lli n,k,m;
vll v;
vvll dp;
lli dpp(lli i,lli n){
   if(n==0)return 0;
   if(i==m)return 1e18;
   if(dp[i][n]!=-1)return dp[i][n];
   lli skip=dpp(i+1,n);
   lli take=1e18;
   if(v[i]<=n){
    lli c=dpp(i,n-v[i]);
    if(c!=1e18){
        take=1+c;
    }
   }
   return dp[i][n]=min(skip,take);
}
lli poww(lli a,lli e){
    lli x=1;
    fr(i,e)x*=a;
    return x;
}

void solve(){

cin>>n>>k;
if(k==1){
    cout<<"1\n";
    cout<<n<<'\n';
    return;
}
v.clear();
lli a=1;
while(1){
  lli x=poww(a,k);  
  if(x>n)break;
  v.psb(x);
  a++;
}
// out(v);
m=v.size();
dp=vvll(m,vll(n+1,-1));
if(dpp(0,n)==1e18){
    cout<<"-1 -1\n";
    return;
}
vll t;
lli i=0,sum=n;
while(sum>0 && i<m){
    if(v[i]<=sum && dpp(i,sum)==(1+dpp(i,sum-v[i]))){
        t.psb(i);
        sum-=v[i];
    }else i++;
}
cout<<t.size()<<'\n';
out(t);
}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}

