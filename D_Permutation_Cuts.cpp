//Author:coding_with_alzheimer
//Date: 2026-07-28 19:13

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
const int MOD=998244353;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
lli n=0,k=0;string s;
cin>>n;
get(v,n-1);
bool bol=true;
vll freq(n+1),f(n+1,-1),l(n+1);
fr(i,n-1){
    freq[v[i]]++;
    if(f[v[i]]==-1)f[v[i]]=i;
    l[v[i]]=i;
}
bol&=(mxe(v)==(n-1));
frs(i,1,n){
   if(freq[i])bol&=(freq[i]==l[i]-f[i]+1);
}
if(!bol){
    cout<<"0\n";
    return;
}
lli ans=1;
lli ll=f[n-1]-1;
lli rr=l[n-1]+1;
rfr(i,n-2,1){
    if(freq[i]){
      if(f[i]==rr)rr=l[i]+1;
      else if(l[i]==ll)ll=f[i]-1;
      else{
        cout<<"0\n";
        return;
      }
    }else{
      ans=(ans*max(0ll,(rr-ll+1-(n-i+1))))%MOD;
    }
}
cout<<(ans*2)%MOD<<'\n';
}

int32_t main(){
fastio;
lli test=1;
lli kk=1;
cin>>test;
while(test--){
    // cout<<"test #"<<(kk++)<<'\n';
solve();
}
}