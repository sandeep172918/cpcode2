//Author:coding_with_alzheimer
//Date: 2026-08-16 20:45

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

vll a,b;
set<lli>aa,bb;
lli check(lli mid){
    // lli ans=0;
    lli j=0;
    lli curr=0;
    lli tot=0;
    fr(i,a.size()){
        while(j<b.size() && a[i]<=mid/b[j]){
             curr++;
             j++;
        }
        tot+=curr;
    }
    return tot;
}


void solve(){
lli n=0,k=1e18;
cin>>n;
get(v,n);
lli x;cin>>x;
srt(v);
fr(i,n){
    if(i&1)b.psb(v[i]);
    else a.psb(v[i]);
}
// return;
aa.insert(1);
fr(i,a.size()){
    set<lli>c;
    for(auto &it:aa){
        c.insert(it);
        lli kk=it;
        while(kk<=k/a[i]){
          kk*=a[i];
          c.insert(kk);
        }
    } 
    aa=c;   
}
// return;
bb.insert(1);
fr(i,b.size()){
    set<lli>c;
    for(auto &it:bb){
        c.insert(it);
        lli kk=it;
        while(kk<=k/b[i]){
          kk*=b[i];
          c.insert(kk);
        }
    }
    bb=c;    
}
// return;
a.clear();
b.clear();
for(auto &it:aa)a.psb(it);
for(auto &it:bb)b.psb(it);
rsrt(a);
lli low=1,high=1e18;
lli t=200;
while(1 && low<high){
    lli mid=(low+high)/2;
    if(check(mid)<x){
        low=mid+1;
    }else{
        high=mid;
    }

}
cout<<low<<'\n';


}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}