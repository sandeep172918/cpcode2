//Author:coding_with_alzheimer
//Date: 2026-06-11 10:21

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



class LCA{
private:
lli n,LOG,timer=0;
vvll adj,up;
vll depth;
vll dis,tin,tout;
  
void dfs(lli node,lli par){
 up[node][0]=par;
 tin[node]=++timer;

 frs(j,1,LOG-1){
    up[node][j]=up[up[node][j-1]][j-1];
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

LCA(lli N,vvll &g){   //1 based
 n=N;
 adj=g;
 LOG=1;
 while((1LL<<LOG)<=n) LOG++;
 up.assign(n+1,vll(LOG,0));
 depth.assign(n+1,0);
 dis.assign(n+1,0);
 tin.assign(n+1,0);
 tout.assign(n+1,0);
 dfs(1,0);   // root = 1
}
bool is_ancestor(lli u,lli v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

lli kth_ancestor(lli u,lli k){

   fr(j,LOG){
     if(k&(1LL<<j)) u=up[u][j];
     if(u==0) return 0;
    }
    return u;
}

lli kth_node_on_path(lli u, lli v, lli k){
  lli w=lca(u,v);
  lli left=depth[u]-depth[w]+1;
  if(k<=left)
    return kth_ancestor(u,k-1);

  k-=left;

  lli right=depth[v]-depth[w];
  return kth_ancestor(v,right-k);
}

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

lli lca2(lli u,lli v){
   if(is_ancestor(u,v)) return u;
   if(is_ancestor(v,u)) return v;
   rfr(j,LOG-1,0){
    if(!is_ancestor(up[u][j],v))
          u=up[u][j];
   }
   return up[u][0];
}

lli dist(lli u,lli v){
 lli w=lca(u,v);
  return depth[u]+depth[v]-2*depth[w];
}

lli weighted_dist(lli u,lli v){
    lli w=lca(u,v);
    return dis[u]+dis[v]-2*dis[w];
}

};

void solve(){
lli n=0,k=0;string s;
cin>>n>>k;
vvll adj(n+1);
frs(i,2,n){
    lli j;
    cin>>j;
    adj[i].psb(j);
    adj[j].psb(i);
}

LCA lca(n,adj);
fr(i,k){
    lli u,v;cin>>u>>v;
    cout<<lca.lca(u,v)<<'\n';
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