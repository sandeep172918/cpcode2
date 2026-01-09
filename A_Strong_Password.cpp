//Author: sandeep172918
//Date: 2025-12-11 11:11

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
 
string curr;
map<lli,vll>mp;

bool check(string curr){
  lli j=0;
  fr(i,curr.size()){
    auto it=mp[curr[i]-'0'];
    auto itt=lower_bound(all(it),j);
    if(itt==it.end())return false;
    j=(itt-it.begin());
  }
  return true;
}

bool found(lli ind,string l,string r,lli m){
    if(ind==m){
        if(check(curr)){
            return true;
        }else return false;
    }
    bool ans=false;
    frs(i,l[ind]-'0',r[ind]-'0'){
        curr+=('0'+i);
        ans|=found(ind+1,l,r,m);
        curr.ppb;
    }
    return ans;



}


void solve(){
string s;cin>>s;
curr="";
mp.clear();
lli n=s.size(),m;cin>>m;
string l,r;cin>>l>>r;
fr(i,n){
    mp[s[i]-'0'].psb(i);
}
if(found(0,l,r,m))yes;
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