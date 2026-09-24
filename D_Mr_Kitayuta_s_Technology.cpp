//Author:coding_with_alzheimer
//Date: 2026-09-17 20:19

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
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vvll adj,adj2;
vll vis;
vll path;
vll comp;
bool bol;

void dfs1(lli u){
    vis[u]=1;
    comp.psb(u);
    for(auto &v:adj[u]){
        if(!vis[v])dfs1(v);
    }
}

void dfs2(lli u){
    path[u]=1;
    for(auto &v:adj2[u]){
       if(path[v]==0){
        dfs2(v);
       }else if(path[v]==1){
         bol=1;
       }
    }
    path[u]=2;
}

void solve(){
lli n=0,k;
cin>>n>>k;
adj=vvll(n+1);
adj2=vvll(n+1);
fr(i,k){
 lli a,b;cin>>a>>b;
 adj2[a].psb(b);
 adj[a].psb(b);
 adj[b].psb(a);
}

vis=vll(n+1);
path=vll(n+1);

lli ans=0;

frs(i,1,n){
  if(!vis[i]){
    comp.clear();
    dfs1(i);
    bol=0;
    for(auto &u:comp){
        if(path[u]==0){
            dfs2(u);
        }
    }
    ans+=comp.size();
    if(!bol)ans--;
  }
}

cout<<ans<<'\n';

}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}