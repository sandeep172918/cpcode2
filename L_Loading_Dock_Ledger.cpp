//Author:coding_with_alzheimer
//Date: 2026-08-23 15:53

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
#define out(v) fr(i,v.size())cout<<v[i]<<'\n'
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



void solve(){
lli n=0,k=0;string c;

cin>>n>>k;
vector<string>s(k);
vll v(k,-1);
stack<lli>st;
vll f(n+1);
vll ans;
fr(i,k){
  cin>>s[i];
  if(s[i]=="IN"){
    cin>>c;
    if(c!="?"){
      lli x=stoll(c);
      f[x]=1;
      v[i]=x;
    }
  }
}
vll m;
frs(i,1,n){
    if(!f[i])m.psb(i);
}
lli j=0;
fr(i,k){
  if(s[i]=="IN"){
    st.push(v[i]);
  }else{
    if(st.empty()){
        cout<<"invalid\n";
        return;
    }
    lli y=st.top();
    st.pop();
    if(y==-1){
        if(j==m.size()){
            cout<<"invalid\n";
            return;
        }
      ans.psb(m[j++]);
    }else{
        ans.psb(y);
    }
  }
}
out(ans);

}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}