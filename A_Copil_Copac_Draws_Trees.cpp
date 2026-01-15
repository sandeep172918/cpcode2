//Author: sandeep172918
//Date: 2026-01-15 22:26

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
#define vvll vector<vector<pr>>
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
vvll adj;
vll dp;
vll id; 

void dfs(lli node){
   
    // for(auto &it:adj[node]){
    //   lli curr=it.ff;
    //   lli curr_id=it.ss;
    //   lli par_id=id[node];
    //   if(!dp[curr]){
    //     dp[curr]=dp[node];
    //     if(curr_id<=par_id)dp[curr]++;
    //     id[curr]=curr_id;
    //     dfs(curr);
    //   }
    // }
    for(auto &[v,idd]:adj[node]){
        if(dp[v])continue;
        dp[v]=dp[node]+(idd<=id[node]);
        id[v]=idd;
        dfs(v);
    }
}

void solve(){
lli n,k;cin>>n;
adj=vvll(n);
dp=vll(n,0);
id=vll(n,0);
fr(i,n-1){
    lli u,v;cin>>u>>v;
    u--;
    v--;
    adj[u].push_back({v,i+1});
    adj[v].push_back({u,i+1});
}
dp[0]=1;
 dfs(0);
cout<<mxe(dp)<<'\n';


}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}