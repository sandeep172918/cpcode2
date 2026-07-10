//Author:coding_with_alzheimer
//Date: 2026-07-10 15:05

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
vvll vv(k,vll(3));
vvll adj(n+1);

fr(i,k){
  fr(j,3)cin>>vv[i][j];
//   vv[i][2]*=-1;
}
for(auto x:vv){
    adj[x[0]].push_back(x[1]);
}
vll dist(n+1,-1e18);
dist[1]=0;
fr(i,n-1){
 for(auto &it:vv){
   lli u=it[0];
   lli v=it[1];
   lli w=it[2];
   if(dist[u]!=-1e18){
      if(dist[u]+w>dist[v]){
        dist[v]=dist[u]+w;
      }
   }
  
 }
}

vll bad(n+1,0);
for(auto &it:vv){
   lli u=it[0];
   lli v=it[1];
   lli w=it[2];
   //cout<<dist[u]<<' '<<dist[v]<<' '<<w<<endl;
   if(dist[u]!=-1e18){
   if(dist[v]<dist[u]+w){
    bad[v]=1;

   }
}
}

queue<int>q;
for(int i=1;i<=n;i++) if(bad[i]) q.push(i);

while(!q.empty()){
    auto node = q.front();
    q.pop();
    for(auto x:adj[node]){
        if(!bad[x]){
            q.push(x);
            bad[x]=1;
        }
    }
}


if(bad[n])cout<<"-1\n";
else{
    cout<<dist[n]<<'\n';
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