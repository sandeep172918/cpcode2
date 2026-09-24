//Author:coding_with_alzheimer
//Date: 2026-09-06 23:26

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
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



void solve(){
lli n=0,k=0;string s;
cin>>n;
get(a,n);
cin>>k;
get(b,k);
map<lli,vll>m;
fr(i,n){
    m[a[i]].psb(i);
}
// vpr p;
vll t;
fr(i,k){
    vll c=m[b[i]];
    // for(auto &it:m[b[i]]){
    //   p.push_back({i,it});
    // }
    rfr(i,c.size()-1,0)t.psb(c[i]);
}
// srtp(p);
// fr(i,p.size()){
//     t.psb(p[i].ss);
// }
vll lis;
fr(i,t.size()){
    auto it=lower_bound(all(lis),t[i]);
    if(it==lis.end()){
        lis.psb(t[i]);
    }else{
        *it=t[i];
    }
}
cout<<lis.size()<<'\n';

}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}