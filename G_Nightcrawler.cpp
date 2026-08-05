//Author:coding_with_alzheimer
//Date: 2026-08-05 11:49

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
vll a;
vector<multiset<lli>>dp;
vll temp;
void dfs(lli node){
    if(adj[node].size()==0){
        dp[node].insert(a[node]);
        return;
    }
    for(auto &it:adj[node]){
        dfs(it);
        if(dp[it].size()>dp[node].size()){
            swap(dp[node],dp[it]);
        }
        for(auto &itt:dp[it])dp[node].insert(itt);
        dp[it].clear();
    }
    lli x=*dp[node].begin();
    dp[node].extract(x);
    dp[node].insert(max(x,a[node]));
    temp.psb(min(x,a[node]));
}

void solve(){
lli n=0,k=0;
cin>>n;
get(v,n);
a=v;
adj=vvll(n);
dp=vector<multiset<lli>>(n);
frs(c,1,n-1){
    lli p;
    cin>>p;
    adj[p-1].psb(c);
}
// return;
for(auto &it:adj){
    if(!it.size())k++;
}
vll ans;
fr(i,k-1)ans.psb(-1);
temp.clear();
// return;

dfs(0);
lli curr=accumulate(all(dp[0]),0ll);
// cout<<curr<<'\n';
// return;

ans.psb(curr);
// out(ans);
// out(temp);
rsrt(temp);
fr(i,temp.size()){
    curr+=temp[i];
    ans.psb(curr);
}
out(ans);

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}