//Author: sandeep172918
//Date: 2025-12-17 15:14

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
string aa,bb;cin>>aa>>bb;
lli n=aa.size();
vll a(n),b(n);
fr(i,n){
    a[i]=aa[i]-'0';
    b[i]=bb[i]-'0';
}
vvll dp(n,vll(2,1e18));
dp[0][1]=0;
dp[0][0]=0;
fr(i,2){
    if(i!=a[0])dp[0][i]++;
    if(i!=b[0])dp[0][i]++;
}
frs(i,1,n-1){
 fr(prev,2){
    fr(curr,2){
        lli c=dp[i-1][prev];
        if(curr!=b[i])c++;
        if((curr^prev) != a[i])c++;
        dp[i][curr]=min(dp[i][curr],c);
    }
 }
}
cout<<min(dp[n-1][0],dp[n-1][1])<<'\n';

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}