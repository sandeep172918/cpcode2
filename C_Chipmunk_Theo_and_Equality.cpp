//Author:coding_with_alzheimer
//Date: 2026-06-06 15:35

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

get(v,n);
map<lli,lli>f,a;
lli ans=1e10;
srt(v);
k=v[0];
lli c=0;
while(true){
    f[k]++;
    a[k]+=c;
    if(k==1)break;

    if(k&1){
        k++;
    }else{
        k/=2;
    }
    c++;
   
}
 if(v[0]==1){
       a[2]++;
       f[2]++;
 }
frs(i,1,n-1){
    k=v[i];
    lli c=0;
    while(true){
        if(f.find(k)!=f.end()){
           f[k]++;
           a[k]+=c;
        }
        if(k==1)break;
        if(k&1)k++;
        else k/=2;
        c++;
       
    }
    if(v[i]==1){
        if(f.find(2)!=f.end()){
            a[2]++;
            f[2]++;
        }
    }
 
}
for(auto &it:f){
  if(it.ss==n){
    ans=min(ans,a[it.ff]);
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
