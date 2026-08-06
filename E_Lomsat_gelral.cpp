//Author:coding_with_alzheimer
//Date: 2026-08-05 22:59

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
vll c;
vll ans;
vll f;    //frequency of dominating
vll curr;  //current ans of each node
vector<map<lli,lli>>m;

void dfs(lli node,lli p){
   f[node]=m[node][c[node]]=1;
   curr[node]=c[node];

   for(auto &it:adj[node]){
    if(it==p)continue;
    dfs(it,node);
    if(m[it].size()>m[node].size()){   //small to large 
        swap(m[it],m[node]);
        swap(f[node],f[it]);
        swap(curr[node],curr[it]);
    }
    for(auto &it:m[it]){  //merging
        m[node][it.ff]+=it.ss;  
        if(m[node][it.ff]>f[node]){  //agr naya wla dominating hua  toh wahi ans hoga
           curr[node]=it.ff;
           f[node]=m[node][it.ff];
        }else if(m[node][it.ff]==f[node]){  // age ye max freq ke barabar aa rha mltb lrta 3 2 bar tha 
           curr[node]+=it.ff;               // ab 6 do bar ho gya so it will get added to ans
        }
    }

   }
    ans[node]=curr[node];

}

void solve(){
lli n=0,k=0;string s;
cin>>n;
get(v,n);
c=v;
adj=vvll(n);
f=vll(n);
curr=vll(n);
ans=vll(n);
m=vector<map<lli,lli>>(n);
fr(i,n-1){
    lli a,b;
    cin>>a>>b;
    a--;
    b--;
    adj[a].psb(b);
    adj[b].psb(a);
}
//cin>>s;
dfs(0,-1);
out(ans);

}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}