//Author: sandeep172918
//Date: 2025-12-22 12:10

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
lli n,k;
vll v;
lli dp[102][51][51][2];
lli comp(lli i,lli ev,lli odd,lli pp){//pp prev pairity
 if(i==n)return 0;
 if(dp[i][ev][odd][pp]!=-1)return dp[i][ev][odd][pp];
 lli ans=1e18;
 lli curr=v[i]%2;
 if(v[i]){
    if(i==0 || pp==curr)ans=min(ans,comp(i+1,ev,odd,curr));
    else ans=min(ans,1+(i+1,ev,odd,curr));
 }else{
    
      if(ev)ans=min(ans,(pp==1)+comp(i+1,ev-1,odd,0));
      if(odd)ans=min(ans,(pp==0)+comp(i+1,ev,odd-1,1));
   
 }
 return dp[i][ev][odd][pp]=ans;
}
 
void solve(){
cin>>n;
v.resize(n);
memset(dp,-1,sizeof(dp));
lli odd=0,ev=0;
fr(i,n){
    cin>>v[i];
    if(v[i]){
        if(v[i]&1)odd++;
        else ev++;
    }
}
odd=(n+1)/2-odd;
ev=n/2-ev;
cout<<comp(0,ev,odd,2)<<'\n';

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}