//Author: sandeep172918
//Date: 2025-12-02 21:58

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
lli x,y,a,b,aa,bb;cin>>x>>y>>a>>b>>aa>>bb;
// 0-up,1-down,2-right,3-left;
vpr opo={{2,3},{2,3},{0,1},{0,1}};
vpr dir={{0,y},{0,-y},{x,0},{-x,0}};
map<pr,lli>m;
fr(i,4){
    lli x1,x2,y1,y2;
     x1=x2=a+dir[i].ff;
     y1=y2=b+dir[i].ss;
    pr op=opo[i];
    x1+=dir[op.ff].ff;
    y1+=dir[op.ff].ss;
    x2+=dir[op.ss].ff;
    y2+=dir[op.ss].ss;
    m[{x1,y1}]++;
    m[{x2,y2}]++;
}
lli ans=0;
fr(i,4){
    lli x1,x2,y1,y2;
     x1=x2=aa+dir[i].ff;
     y1=y2=bb+dir[i].ss;
    pr op=opo[i];
    x1+=dir[op.ff].ff;
    y1+=dir[op.ff].ss;
    x2+=dir[op.ss].ff;
    y2+=dir[op.ss].ss;
    if(m.find({x1,y1})!=m.end()){
       ans++;
       m.erase({x1,y1});
    }
     if(m.find({x2,y2})!=m.end()){
       ans++;
       m.erase({x2,y2});
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