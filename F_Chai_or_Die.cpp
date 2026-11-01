//Author:coding_with_alzheimer
//Date: 2026-11-01 11:18

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
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define ff first
#define ss second
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define psbp(a,b) push_back({a,b})
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define no1 cout<<"-1\n"
#define pn(x) cout<<(x)<<"\n"
#define pt(x) cout<<(x)<<" "
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
#define arr(a) array<lli,a>
using namespace std;
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;






class LCA{
private:
lli n,LOG,timer=0;
vvll adj,up,mini;
vll depth;
vll dis,tin,tout,chai;
  
void dfs(lli node,lli par){
 up[node][0]=par;
 mini[node][0]=min(chai[node],chai[par]);
 tin[node]=++timer;

 frs(j,1,LOG-1){
    up[node][j]=up[up[node][j-1]][j-1];
    mini[node][j]=min(mini[node][j-1],mini[up[node][j-1]][j-1]);
 }
 for(auto &it:adj[node]){
    if(it==par)continue;
    depth[it]=depth[node]+1;
    //dis[v]=dis[node]+wt;  //do arrangement like vvpr
    dfs(it,node);
 }

 tout[node]=timer;

}
public:

LCA(lli N,vvll &g,vll &d){   //1 based
 n=N;
 adj=g;
 LOG=1;
 while((1LL<<LOG)<=n) LOG++;
 up.assign(n+1,vll(LOG,0));
 mini.assign(n+1,vll(LOG,1e18));
 depth.assign(n+1,0);
 dis.assign(n+1,0);
 tin.assign(n+1,0);
 tout.assign(n+1,0);
 chai=d;

 dfs(1,0);   // root = 1
}
bool is_ancestor(lli u,lli v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

// lli kth_ancestor(lli u,lli k){

//    fr(j,LOG){
//      if(k&(1LL<<j)) u=up[u][j];
//      if(u==0) return 0;
//     }
//     return u;
// }

// lli kth_node_on_path(lli u, lli v, lli k){
//   lli w=lca(u,v);
//   lli left=depth[u]-depth[w]+1;
//   if(k<=left)
//     return kth_ancestor(u,k-1);

//   k-=left;

//   lli right=depth[v]-depth[w];
//   return kth_ancestor(v,right-k);
// }

lli lca(lli u,lli v){
    if(depth[u]<depth[v]) swap(u,v);

   // bring u to same depth as v
    lli diff=depth[u]-depth[v];

    fr(j,LOG){
      if(diff&(1LL<<j))
           u=up[u][j];
    }

    if(u==v) return u;

    rfr(j,LOG-1,0){
      if(up[u][j]!=up[v][j]){
          u=up[u][j];
          v=up[v][j];
        }
    }
    return up[u][0];
}

lli dist(lli u,lli v){
 lli w=lca(u,v);
  return depth[u]+depth[v]-2*depth[w];
}

lli detour(lli u,lli v){
  lli w=lca(u,v);
  lli ans=min({chai[u],chai[v],chai[w]});
  lli x=depth[u]-depth[w];
  fr(j,LOG){
    if((x>>j)&1){
      ans=min(ans,mini[u][j]);
      u=up[u][j];
    }
  }
  x=depth[v]-depth[w];
  fr(j,LOG){
    if((x>>j)&1){
      ans=min(ans,mini[v][j]);
      v=up[v][j];
    }
  }
  return ans;
}

};


void solve(){
lli n=0,k=0,ans=0;
array<lli,1>arr;
string s;
cin>>n>>k;
get(v,n);
queue<lli>q;
fr(i,n){
  if(v[i])q.push(i+1);
}
vvll adj(n+1);
fr(i,n-1){
  lli u,v;
  cin>>u>>v;
  adj[u].psb(v);
  adj[v].psb(u);
}
vll dist(n+1,1e18);
fr(i,n){
  if(v[i])dist[i+1]=0;
}
while(!q.empty()){
  lli u=q.front();
  q.pop();
  for(auto &it:adj[u]){
    if(dist[it]>dist[u]+1){
      dist[it]=dist[u]+1;
      q.push(it);
    }
  }
}
LCA lcaa(n,adj,dist);

while(k--){
  lli u,v;
  cin>>u>>v;
  cout<<lcaa.dist(u,v)+2*lcaa.detour(u,v)<<'\n';
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