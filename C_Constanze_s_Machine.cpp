//Author: sandeep172918
//Date: 2025-12-12 11:28

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
 vll fib(2e5);
void pre(){
    fib[1]=1;
    fib[2]=2;
    fib[3]=3;
    frs(i,4,2e5-1){
        fib[i]=(fib[i-1]+fib[i-2])%MOD;
    }
}
static inline lli mod_pow(lli a, lli e, lli m=MOD){
        lli r = 1 % m;
        a %= m;
        while(e){
            if(e & 1) r = (__int128)r * a % m;
            a = (__int128)a * a % m;
            e >>= 1;
        }
        return r;
    }

void solve(){
string s;cin>>s;
lli n=s.size();
lli curr=0;
map<lli,lli>m;
fr(i,n){
     if(s[i]=='m' || s[i]=='w'){
        cout<<"0\n";
        return;
    }
}
fr(i,n){
   
    if(s[i]=='n'){
       curr++;
    }else{
        if(curr)
        m[curr]++;
        curr=0;
    }
}
if(curr)m[curr]++;
curr=0;
fr(i,n){
    if(s[i]=='u'){
       curr++;
    }else{
        if(curr)
        m[curr]++;
        curr=0;
    }
}
if(curr)m[curr]++;
lli ans=1;
for(auto &it:m){
   // cout<<it.ff<<' '<<it.ss<<'\n';
   ans=((ans%MOD)*mod_pow(fib[it.ff],it.ss))%MOD;
}
cout<<ans<<'\n';



}

int32_t main(){
fastio;
pre();
lli test=1;
while(test--){
solve();
}
}