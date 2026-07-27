//Author:coding_with_alzheimer
//Date: 2026-07-27 22:12

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
lli n;cin>>n;
vpr u(n),v(n);
fr(i,n){
    lli x,y;
    cin>>x>>y;
    u[i]={x+y,i};
    v[i]={x-y,i};
}
if(n<=3){
    cout<<"0\n";
    return;
}
srt(u);
srt(v);
vll t;
lli ans=1e18;
fr(i,3){
  t.psb(u[i].ss);
  t.psb(v[i].ss);
  t.psb(u[n-i-1].ss);
  t.psb(v[n-i-1].ss);
}
srt(t);
t.erase(unique(all(t)),t.end());
fr(i,t.size()){
    frs(j,0,i-1){
        lli ii=t[i];
        lli jj=t[j];
        lli mnx=1e18,mny=1e18,mxx=-1e18,mxy=-1e18;
        fr(k,n){
           if(u[k].ss!=ii && u[k].ss!=jj){
             mnx=min(mnx,u[k].ff);
             mxx=max(mxx,u[k].ff);
           }
           if(v[k].ss!=ii && v[k].ss!=jj){
             mny=min(mny,v[k].ff);
             mxy=max(mxy,v[k].ff);
           }
        }
        ans=min(ans,max(mxx-mnx,mxy-mny));
    }
}
cout<<ans<<'\n';
}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}