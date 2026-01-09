//Author: sandeep172918
//Date: 2025-12-11 21:25

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
const int MOD= 998244353;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
map<pr,lli>dp;
vvll adj;
vpr e;
vll v;

lli dfs(lli node,lli val){
    if(dp.find({node,val})!=dp.end()){
        return dp[{node,val}];
    }
    lli ans=0;
    for(auto &it:adj[node]){
        if(v[it]==val)
          ans=(ans+1+dfs(it,v[node]+v[it]))%MOD;
    }
    return dp[{node,val}]=ans;
}




void solve(){
lli n,k;cin>>n>>k;
v=vll(n);
fr(i,n)cin>>v[i];
dp.clear();
e=vpr(k);
adj=vvll(n);
fr(i,k){
    lli u,vv;cin>>u>>vv;
    u--;vv--;
    e[i]={u,vv};
    adj[u].psb(vv);
}
lli ans=0;
for(auto &[x,y]:e){
    lli next=v[x]+v[y];
    ans=(ans+1+dfs(y,next))%MOD;
    
}
cout<<ans<<'\n';

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}