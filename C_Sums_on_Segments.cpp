//Author: sandeep172918
//Date: 2026-01-20 19:51

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
 
lli kadane(vll &v){
    lli maxi=0;
    lli curr=0;
    fr(i,v.size()){
        curr+=v[i];
        maxi=max(curr,maxi);
        if(curr<0)curr=0;
    }
    maxi=max(maxi,curr);
    return maxi;
}

void solve(){
lli n,k;cin>>n;
get(v,n);
vll t=v;
fr(i,n)t[i]*=-1;
lli id=-1;
fr(i,n){
    if(v[i]!=-1 && v[i]!=1){
        id=i;
    }
}
if(id==-1){
  lli r=kadane(v);
  lli l=kadane(t);
  l*=-1;
 // cout<<l<<' '<<r<<'\n';
 cout<<r-l+1<<'\n';
  frs(i,l,r){
    cout<<i<<' ';
  }
  nl;
}else{

   vll ll,ll1;
   fr(i,id){
    ll.psb(v[i]);
    ll1.psb(t[i]);
   } 
   lli lmx=kadane(ll);
   lli lmn=-1*kadane(ll1);
   vll rr,rr1;
   frs(i,id+1,n-1){
    rr.psb(v[i]);
    rr1.psb(t[i]);
   }
   lli rmx=kadane(rr);
   lli rmn=-1*kadane(rr1);

   lli mini1=v[id],maxi=v[id];
   lli maxi1=v[id],mini=v[id];
   lli prev=v[id];
   frs(i,id+1,n-1){
      prev+=v[i];
      maxi=max(maxi,prev);
      mini=min(mini,prev);
   }
   prev=v[id];
   rfr(i,id-1,0){
      prev+=v[i];
      mini1=min(mini1,prev);
      maxi1=max(maxi1,prev);
   }
  // cout<<mini1<<' '<<maxi<<'\n';
   set<lli>st;
   st.insert(0);
   frs(i,lmn,lmx)st.insert(i);
   frs(i,rmn,rmx)st.insert(i);
   frs(i,mini1+mini-v[id],maxi+maxi1-v[id])st.insert(i);
  //  frs(i,mini,maxi1)st.insert(i);
  cout<<st.size()<<'\n';
  for(auto &it:st)cout<<it<<' ';
  nl;
}

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}