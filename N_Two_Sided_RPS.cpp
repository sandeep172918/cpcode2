//Author:coding_with_alzheimer
//Date: 2026-08-14 21:18

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
lli n=0,k=0;string s;
cin>>n;
//get(v,n);
cin>>s;
char c;
cin>>c;
vector<char>a(n),b(n);
a[0]=s[0];
b[n-1]=s[n-1];
frs(i,1,n-1){
    a[i]=a[i-1];
    if(a[i-1]=='R' && s[i]=='S')a[i]='R';
    if(a[i-1]=='S' && s[i]=='R')a[i]='R';
    if(a[i-1]=='S' && s[i]=='P')a[i]='S';
    if(a[i-1]=='P' && s[i]=='S')a[i]='S';
    if(a[i-1]=='R' && s[i]=='P')a[i]='P';
    if(a[i-1]=='P' && s[i]=='R')a[i]='P';
}
rfr(i,n-2,0){
    b[i]=b[i+1];
    if(b[i+1]=='R' && s[i]=='S')b[i]='R';
    if(b[i+1]=='S' && s[i]=='R')b[i]='R';
    if(b[i+1]=='S' && s[i]=='P')b[i]='S';
    if(b[i+1]=='P' && s[i]=='S')b[i]='S';
    if(b[i+1]=='R' && s[i]=='P')b[i]='P';
    if(b[i+1]=='P' && s[i]=='R')b[i]='P';
}
lli ans=0;
frs(i,1,n-1){
    char cc=a[i-1];
    if(a[i-1]=='R' && b[i]=='S')cc='R';
    if(a[i-1]=='S' && b[i]=='R')cc='R';
    if(a[i-1]=='S' && b[i]=='P')cc='S';
    if(a[i-1]=='P' && b[i]=='S')cc='S';
    if(a[i-1]=='R' && b[i]=='P')cc='P';
    if(a[i-1]=='P' && b[i]=='R')cc='P';
    if(cc==c)ans++;
}
cout<<ans<<'\n';
}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}