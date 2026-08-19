//Author:coding_with_alzheimer
//Date: 2026-08-18 18:37

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
lli n=0,k=0;string s;
cin>>n;
vvll v(n,vll(3));
fr(i,n){
    fr(j,3)cin>>v[i][j];
}
lli ans=0;
frs(x,-2e5-18,2e5+18){
    vpr t;
    fr(i,n){
        lli mx=max(abs(x-v[i][0]),abs(x+1-v[i][0]));
        lli y=v[i][1];
        lli r=v[i][2];
        lli yy=r*r-mx*mx;
        if(yy<1)continue;
        yy=sqrt(yy);
        t.push_back({y-yy,y+yy-1});
    }
    if(t.empty())continue;
    srt(t);
    lli l=t[0].ff;
    lli r=t[0].ss;
    frs(i,1,t.size()-1){
       if(t[i].ff<=r)r=max(r,t[i].ss);
       else{
         ans+=r-l+1;
         l=t[i].ff;
         r=t[i].ss;
       }
    }
    ans+=r-l+1;
}
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
