//Author: sandeep172918
//Date: 2026-01-31 10:13

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
#define out(v) fr(i,v.size())cout<<v[i]-1<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const int MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vvll adj; 
vll ans;
lli n;
lli bfs(lli src){
    vll dist(n+1,0);
    queue<lli>q;
    q.push(src);
    dist[src]=1;
    lli node;
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(auto &it:adj[node]){
            if(!dist[it]){
                dist[it]=dist[node]+1;
                ans[it]=max(ans[it],dist[it]);
                q.push(it);
            }
        }

    }
    return node;
}

void solve(){
cin>>n;
if(n==1){
    cout<<"0\n";
    return;
}
adj=vvll(n+1);
ans=vll(n+1,-1);
fr(i,n-1){
    lli x,y;cin>>x>>y;
    adj[x].psb(y);
    adj[y].psb(x);
}
lli one=bfs(1);
lli two=bfs(one);
bfs(two);
ans.erase(ans.begin());
out(ans);


}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}