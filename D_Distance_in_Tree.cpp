//Author:coding_with_alzheimer
//Date: 2026-06-18 08:25

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
const lli N=5e4+18;
const lli K=5e2+18;
lli n,k;
vvll adj(N);
vll sz(N);
vll vis(N);
vll f(K);
lli ans=0;

void dfs(lli node,lli par=-1){
    sz[node]=1;
    for(auto &it:adj[node]){
        if(vis[it] || it==par)continue;
        dfs(it,node);
        sz[node]+=sz[it];
    }
}

lli find_cent(lli siz,lli node,lli par=-1){
     for(auto &it:adj[node]){
        if(!vis[it] && it!=par && 2*sz[it]>siz){
            return find_cent(siz,it,node);
        }
     }
     return node;
}

void get_dist(lli node,lli par,lli d,vll &dist){
    if(d>k)return;
    dist.psb(d);
    for(auto &it:adj[node]){
        if(vis[it] || it==par){
            continue;
        }
        get_dist(it,node,d+1,dist);
    }

}

void decom(lli node,lli par=-1){
    dfs(node);
    lli c=find_cent(sz[node],node,par);
    vis[c]=true;
    f[0]++;
    for(auto &it:adj[c]){
        if(vis[it])continue;
        vll dist;
        get_dist(it,c,1,dist);
        for(auto &it:dist){
           ans+=f[k-it];
        }
        for(auto &it:dist){
            f[it]++;
        }
    }
    for(auto &it:adj[c]){
        if(vis[it])continue;
        vll dist;
        get_dist(it,c,1,dist);
        for(auto &it:dist){
            f[it]--;
        }
    }
    f[0]--;
    for(auto &it:adj[c]){
        if(vis[it])continue;
        decom(it,node);
    }

}


void solve(){
cin>>n>>k;
fr(i,n-1){
lli u,v;cin>>u>>v;u--;v--;
adj[u].psb(v);
adj[v].psb(u);
}
decom(0);
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