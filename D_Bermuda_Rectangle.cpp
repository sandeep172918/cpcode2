//Author:coding_with_alzheimer
//Date: 2026-08-17 21:18

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
vll d;
lli s;
vll p;
lli sum(lli x){
    if(x==0)return 0;
   lli ans=0;
   lli i=upper_bound(all(d),x)-d.begin();
   ans+=p[i-1];
   if(x>d[i-1]){
    ans+=(x-d[i-1])*(s/d[i]);
   }
   return ans;
}

void solve(){
lli n=0,k=0;
cin>>s>>k;
d.clear();
for(lli i=1;i*i<=s;i++){
    if(s%i)continue;
    d.psb(i);
    if(i*i==s)continue;
    d.psb(s/i);
}
// return;
d.psb(0);
srt(d);
lli nn=d.size();
p=vll(nn);
// out(d);
// return;
frs(i,1,nn-1){
    p[i]=p[i-1]+(d[i]-d[i-1])*(s/d[i]);
}
// return;
fr(i,k){
    lli x,y;
    cin>>x>>y;
    auto id=upper_bound(all(d),s/y)-d.begin();

    lli xx=d[id-1];
    lli c=min(x,xx);
    // cout<<xx<<' '<<c<<' '<<'\n';
    // cout<<sum(x)<<' ';
    // cout<<sum(c)<<' ';
    // nl;
    cout<<c*y+sum(x)-sum(c)<<'\n';

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