
#include <bits/stdc++.h>

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
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sq(x) sqrtl(x)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define no1 cout<<"-1\n"
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const int MOD=1e9+7;
 
void solve(){
lli n,k;cin>>n;
get(v,n);
vll t(35);
lli maxi=0;
fr(i,n){
    lli x=v[i];
    maxi=max(maxi,(lli)log2(x)+1);
    fr(j,35){
        k=1ll<<j;
        k=k&x;
        t[j]+=(k>0);
    }
}
// out(t);
fr(i,maxi){
    if(t[i]!=1){
        no;
        return ;
    }

}
yes;

}

int32_t main(){
fastio;
lli tt=1;
cin>>tt;
while(tt--){
solve();
}
}