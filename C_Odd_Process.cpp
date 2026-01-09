//Author: sandeep172918
//Date: 2025-12-11 20:28

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
lli n,k;cin>>n;
get(v,n);
vll ev;
vll odd;
fr(i,n){
    if(v[i]&1)odd.psb(v[i]);
    else ev.psb(v[i]);
}
rsrt(ev);
rsrt(odd);

vll temp;
if(odd.size()==0){
    fr(i,n)cout<<"0 ";
    nl;
    return;
}
temp.psb(odd[0]);
fr(i,ev.size()){
    temp.psb(temp.back()+ev[i]);
}
lli x=temp.size();
// fr(i,x)cout<<temp[i]<<' ';
 lli s=odd.size()-1;
// lli a=temp[x-1];
// lli b=0;
// // cout<<x<<' ';

// if(x>=2)b=temp[x-2];
// // cout<<a<<' '<<b<<' ';
// frs(i,x,n-1){
//    lli xx=i-x; 
//   if(xx%2==0){
//     if(s>=2){
//         cout<<b<<' ';
//     }else{
//         cout<<"0 ";
//     }
//   }else{
//     if(s>=2)cout<<a<<' ';
//     else cout<<"0 ";
//   }
// }
// nl;


lli a=0,b=0;
a=temp.back();
if(x>=2)b=temp[x-2];fr(i,x)cout<<temp[i]<<' ';


fr(i,n){
    if(i<x){
        cout<<temp[i]<<' ';
        continue;
    }
    lli e_odd=i-x+1;
    if(e_odd%2){
       if(e_odd<=(s-1)){
        cout<<b<<' ';
       }else{
        cout<<"0 ";
       }

    }else{
      if(e_odd<=s){
        cout<<a<<' ';
      }else{
        cout<<"0 ";
      }
    }
}
nl;

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}