//Author:coding_with_alzheimer
//Date: 2026-09-29 23:07

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

class manacher{
    private:
    vll d;
    string s;
    lli n;
    public:
    manacher(string &a){
       s="*";
       fr(i,a.size()){
         s+=a[i];
         s+='*';
       }
       n=s.size();
       d=vll(n);
       build();
    }
    void build(){
        lli l=1,r=1;
        frs(i,1,n-1){
            d[i]=max(0ll,min(r-i,d[l+(r-i)]));
            while(i+d[i]<n && i-d[i]>=0 && s[i+d[i]]==s[i-d[i]])d[i]++;
            if(r<i+d[i]){
                l=i-d[i];
                r=i+d[i];
            }
        }
    }
    lli longp(lli c,bool odd){
        lli i=2*c+1+(!odd);
        return d[i]-1;
    }


};


void solve(){
lli n=0,k=0;string s;
// cin>>n>>k;
//get(v,n);
cin>>s;
n=s.size();
manacher mc(s);
vll ans(n);
fr(i,n){
  k=mc.longp(i,1);
  ans[i+k/2]=max(ans[i+k/2],k);
  if(i<n-1){
    k=mc.longp(i,0);
    ans[i+k/2]=max(ans[i+k/2],k);
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