//Author:coding_with_alzheimer
//Date: 2026-07-11 12:25

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


class centroid{
     private:
     lli n;
     vvll adj;
     vll vis,sz,dad;
     public:
     centroid(lli N,vvll& ad){
        n=N;
        adj=ad;
        vis.assign(n+1,0);
        sz.assign(n+1,0);
        dad.assign(n+1,0);
        // build_centroid_tree(1,0);
     }
     void dfs(lli node,lli par){
        sz[node]=1;
        for(auto &it:adj[node]){
            if(it==par || vis[it])continue;
            dfs(it,node);
            sz[node]+=sz[it];
        }
     }
     lli get_cent(lli siz,lli node,lli par){
        for(auto &it:adj[node]){
            if(it!=par && !vis[it] && 2*sz[it]>siz){
                return get_cent(siz,it,node);
            }
        }
        return node;
     }
     void build_centroid_tree(lli node,lli par){
         dfs(node,par);
         lli c=get_cent(sz[node],node,par);
         vis[c]=true;
         dad[c]=par;
         for(auto &it:adj[c]){
            if(!vis[it]){
                build_centroid_tree(it,c);
            }
         }
     } 
     lli par(lli node){
        return dad[node];
     } 
     lli ans(){
        dfs(1,-1);
        return get_cent(sz[1],1,-1);
     }
    
};
 

void solve(){
lli n=0,k=0;string s;
cin>>n;
vvll adj(n+1);
fr(i,n-1){
    lli u,v;cin>>u>>v;
    adj[v].psb(u);
    adj[u].psb(v);
}
centroid cd(n,adj);
cout<<cd.ans();


}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}