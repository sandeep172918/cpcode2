//Author:coding_with_alzheimer
//Date: 2026-07-27 09:46

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



// lli check(lli mid,vvll &v){
//     lli a=1,b=mid;
//     lli ans=0;
//     for(auto &it:v){
     
    
//    if((it[0]<=a && a<=it[1]) || (it[2]<=b && b<=it[3])){
//         continue;
//      }else{
//         ans++;
//         a++;
//         b--;
//     }
//  }
//  return ans;
// }


void solve(){
lli n=0,k=0;string s;
cin>>n;
vvll v(n,vll(4));
fr(i,n){
   fr(j,4)cin>>v[i][j];
}

// lli low=1,high=n;
// while(low<=high){
//     lli mid=(low+high)/2;
//     if(check(mid,v))
// }
lli ans=0;
frs(i,1,n){
    lli a=1,b=i;
    lli curr=0;
    for(auto &it:v){
    if((it[0]<=a && a<=it[1]) || (it[2]<=b && b<=it[3])){
        continue;
     }else{
        curr++;
        a++;
        b--;
    }
    if(a>i)break;
    
  }
  if(curr==i)
  ans=max(ans,curr);
}
cout<<ans<<'\n';

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
    // cout<<"hi\n";
solve();
}
}