//Author: sandeep172918
//Date: 2025-12-22 18:21

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
lli n,a,b;cin>>n>>a>>b;
get(v,n);
vpr p(n);
srt(v);
a-=count(all(v),1);
b-=count(all(v),1);
fr(i,n){
    lli x=v[i];
    p[i].ff=1;
    while(x>1 && (x%2==0)){
        p[i].ff*=2;
        x/=2;
    }
    p[i].ss=x;
}
lli c=0,d=0;
fr(i,n){
    if(p[i].ff==1)c++;
    if(p[i].ss==1)d++;
}

lli ans=0;
if(c==n){
 
  fr(i,a)ans+=v[i];
}
else if(d==n){
   fr(i,b)ans+=v[i];
}





}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}