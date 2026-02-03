//Author: sandeep172918
//Date: 2026-02-04 00:44

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
map<lli,string>m;

void pre(){
    string a="1689";
    do{
      lli x=stoi(a);
      m[x%7]=a;
    }while(next_permutation(all(a)));
}

void solve(){
string s;cin>>s;
string ans="";
int a=1,b=6,c=8,d=9;
lli mod=0;
fr(i,s.size()){
   lli x=s[i]-'0';
   if(!x)continue;
   if(x==a){
    a=-1;
    continue;
   }
    if(x==b){
    b=-1;
    continue;
   }
    if(x==c){
    c=-1;
    continue;
   }
    if(x==d){
    d=-1;
    continue;
   }
   ans+=s[i];
   mod=(mod*10+x)%7;

}
// cout<<mod<<' ';
lli cnt=count(all(s),'0');
lli req=(-mod*10000)%7;
if(req<0)req+=7;
// cout<<req<<'\n';
ans+=m[req];
fr(i,cnt)ans+='0';
cout<<ans<<'\n';

}

int32_t main(){
fastio;
pre();
// for(auto &it:m){
//     cout<<it.ff<<' '<<it.ss<<'\n';
// }
lli test=1;
while(test--){
solve();
}
}