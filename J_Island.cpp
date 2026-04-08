//Author:coding_with_alzheimer
//Date: 2026-04-06 17:53

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
lli n=0,k=0,m=0,x=0;cin>>n>>k;
//get(v,n);
vpr p(n);
vll s;
fr(i,n){
    lli l,r;cin>>l>>r;
    p[i]={l,r};
    s.psb(l);
    s.psb(r+1);
}
m=s.size();
vll diff(m);
srt(s);
for(auto &[l,r]:p){
    diff[lower_bound(all(s),l)-s.begin()]++;
    diff[lower_bound(all(s),r+1)-s.begin()]--;
}
//we are woking on breakpoints 
// input:
// [1,10]
// [3,7]
// s:
// 1, 3, 8, 11
// segments:
// [1,3)   freq = 1    length = 2
// [3,8)   freq = 2    length = 5
// [8,11)  freq = 1    length = 3

//diff[i] batayega ki [s[i]  s[i+1])  is range ke har ek element ka freq
// acc[i] is storing length of segment * freq which will be total freq of this segment

frs(i,1,m-1){
    diff[i]+=diff[i-1];
}
vll acc(m);
frs(i,1,m-1){
    acc[i]=acc[i-1]+diff[i-1]*(s[i]-s[i-1]);
}
// out(acc);
fr(i,k){
    lli x;cin>>x;
    x--;
    lli id=upper_bound(all(acc),x)-acc.begin()-1;
    // cout<<id <<' ';
    // cout<<s[id];
    // return;
    cout<<s[id]+(x-acc[id])/diff[id]<<'\n';
    //return;
}



}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}