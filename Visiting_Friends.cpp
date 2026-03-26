//Author:coding_with_alzheimer
//Date: 2026-03-25 02:13

#include <bits/stdc++.h>
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

vvll adj,adjr,n_adj;
vll vis;
stack<lli>st;
vll t;

void dfs(lli nd){
    vis[nd]=1;
    for(auto &it:adj[nd]){
        if(!vis[it])dfs(it);
    }
    st.push(nd);
}

void dfs2(lli nd){
    vis[nd]=1;
    for(auto &it:adjr[nd]){
        if(!vis[it])dfs2(it);
    }
    t.psb(nd);
}
void dfs3(lli nd){
    vis[nd]=1;
    for(auto &it:n_adj[nd]){
        if(!vis[it])dfs3(it);
    }
    st.push(nd);
}


void solve(){
lli n,k;cin>>n>>k;
get(v,n);
vvll comp;
vll ans(n);
adj=vvll(n);
adjr=vvll(n);
vis=vll(n,0);
vpr p(k);
fr(i,k){
    lli u,v;
    cin>>u>>v;
    u--;
    v--;
    p[i]={u,v};
    adj[u].psb(v);
    adjr[v].psb(u);
}
fr(i,n){
    if(!vis[i])dfs(i);
}
vis=vll(n,0);

while(!st.empty()){
    lli nd=st.top();
    st.pop();
    if(!vis[nd]){
     dfs2(nd);
     comp.psb(t);
    }
    t.clear();
}
lli c=comp.size();

vll wt(n);

fr(i,c){
    lli curr=0;
    fr(j,comp[i].size()){
        ans[comp[i][j]]=i;
        curr+=v[comp[i][j]];
    }
    wt[i]=curr;
}
n_adj=vvll(c);
set<pr>stt;
fr(i,k){
    if(ans[p[i].ff]!=ans[p[i].ss]){
        stt.insert({ans[p[i].ff],ans[p[i].ss]});
    }
}
for(auto &it:stt){
    n_adj[it.ff].psb(it.ss);
}
while(!st.empty())st.pop();
vis=vll(c,0);
fr(i,c){
    if(!vis[i])dfs3(i);
}

vll dp(c);
vll topo;

while(!st.empty()){
   topo.psb(st.top());
   st.pop();
}
reverse(all(topo));
for(auto &u:topo){
    for(auto &it:n_adj[u]){
        dp[u]=max(dp[u],dp[it]);
    }
    dp[u]+=wt[u];
}
vll final(n);

fr(i,n){
    final[i]=dp[ans[i]];
}

out(final);
}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}