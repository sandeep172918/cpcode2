//Author:coding_with_alzheimer
//Date: 2026-07-10 14:41

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
lli n=0,k=0,q;string s;
cin>>n>>k>>q;
vector<vpr>adj(n+1);
vvll dp(n+1,vll(n+1,1e13));
fr(i,k){
    lli u,v,w;cin>>u>>v>>w;
    dp[u][v]=min(dp[u][v],w);
    dp[v][u]=min(dp[v][u],w);
}
fr(i,n){
    dp[i+1][i+1]=0;
}
frs(via,1,n){
frs(i,1,n){
    frs(j,1,n){
            dp[i][j]=min(dp[i][j],dp[i][via]+dp[via][j]);
    }
}
}
fr(i,q){
    lli u,v;cin>>u>>v;
    if(dp[u][v]>=1e13)cout<<"-1\n";
    else cout<<dp[u][v]<<'\n';
}


}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}