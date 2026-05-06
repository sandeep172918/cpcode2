//Author:coding_with_alzheimer
//Date: 2026-05-06 00:33

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
//BSDK math snippet hai



void solve(){
lli n=0,k=0;string s;
cin>>n;
//get(v,n);
cin>>s;
if(n&1){
    no;return;
}
lli a=count(all(s),'a');
lli b=count(all(s),'b');
lli c=count(all(s),'c');
lli tot=(a>0)+(b>0)+(c>0);
// cout<<tot<<' ';
if(tot==1){
    no;
    return;
}
if(tot==2){
    yes;
    return;
}
if(s[0]==s[1]  || s[n-2]==s[n-1]){
    yes;
    return;
}
set<lli>st;
vpr p;
bool bol=false;
lli l,r;
fr(i,n){
    st.insert(s[i]);
    bol=false;

    if(st.size()==2){
        bol=true;
        // st.clear();
    }else if(st.size()==3){
       st.clear();
       st.insert(s[i]);
    }
}
// cout<<bol;
if(bol){
    yes;
    return;
}
bol=true;
st.clear();
fr(i,n){
 st.insert(s[i]);
 if(st.size()==2 && bol){
    bol=false;
    l=i-1;

 }
 if(st.size()==3){
  st.clear();  
  r=i;
  p.push_back({l,r});
  bol=true;

 }
}
lli x=p.size();
l=0,r=n-1;
frs(i,l,p[0].ff-1)x--;
frs(i,p.back().ss+1,r)x--;
frs(i,1,p.size()-1){
  l=p[i-1].ss+1;
  r=p[i].ff-1;
  x-=(r-l+1);
}
if(x<=0)yes;
else no;

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}



