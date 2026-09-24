//Author:coding_with_alzheimer
//Date: 2026-09-06 20:33

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

void print128(__int128_t n){
    if(n==0){cout<<0<<'\n';return;}
    if(n<0){cout<<'-';n=-n;}
    string s;
    while(n>0){
        s+=(char)('0'+(n%10));
        n/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s<<'\n';
}


void solve(){
lli n=0,m,k=0;string s;
get(v,10);
__int128_t ans=0;
if(v[0]==0){
  no1;
  return;
}else{
  ans=pow(10,v[0]+1);
}
__int128_t curr=0;
frs(i,1,9){
    k=v[i]+1;
    while(k--){
        curr*=10;
        curr+=i;
    }
    ans=min(ans,curr);
    curr=0;

}
print128(ans-1);

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}