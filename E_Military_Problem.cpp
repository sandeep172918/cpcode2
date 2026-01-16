//Author: sandeep172918
//Date: 2026-01-16 16:02

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
 
vvll adj;
vll v;
vll sz;
vll vis;
void dfs(lli u){
   vis[u]=1;

   v.psb(u);
   lli s=1;
   for(auto &v:adj[u]){
      if(!vis[v]){
        dfs(v);
        s+=sz[v];
      }
      
   }
   sz[u]=s;
}


void solve(){
lli n,k;cin>>n>>k;
adj=vvll(n);
fr(i,n-1){
    lli p;cin>>p;
    p--;
    adj[p].psb(i+1);
    adj[i+1].psb(p);
}
for(auto &it:adj)srt(it);
v.clear();
vis=vll(n,0);
sz=vll(n);
dfs(0);
vll ind(n);
fr(i,n)ind[v[i]]=i;
while(k--){
    lli u,r;
    cin>>u>>r;
    u--;
    lli curr=ind[u];
    if(r>sz[u])no1;
    else
    cout<<v[curr+r-1]+1<<'\n';
}

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}