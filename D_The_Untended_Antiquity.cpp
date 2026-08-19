// //Author:coding_with_alzheimer
// //Date: 2026-08-20 02:09

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define lli long long int
// #define fr(i,n) for(lli i=0;i<n;i++)
// #define frs(i,a,b) for(lli i=a;i<=b;i++)
// #define rfr(i,b,a) for(lli i=b;i>=a;i--)
// #define srt(v) sort(v.begin(),v.end())
// #define rsrt(v) sort(v.rbegin(),v.rend())
// #define pr pair<lli,lli>
// #define vll vector<lli>
// #define vbl vector<bool>
// #define vpr vector<pr>
// #define vvll vector<vector<lli>>
// #define get(v,n) vll v(n);fr(i,n)cin>>v[i]
// #define ff first
// #define ss second
// #define tr true
// #define fs false
// #define bitc(x) __builtin_popcountll(x)
// #define mxe(v)  *max_element(v.begin(),v.end())
// #define mne(v)  *min_element(v.begin(),v.end())
// #define psb(a) push_back(a)
// #define ppb pop_back()
// #define all(v) v.begin(),v.end()
// #define rall(v) v.rbegin(),v.rend()
// #define sq(x) sqrtl(x)
// #define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
// #define yes cout<<"Yes\n"
// #define no cout<<"No\n"
// #define no1 cout<<"-1\n"
// #define nl cout<<"\n"
// #define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
// #define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
// using namespace std;
// const lli MOD=1e9+7;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// class FenwickTree{
// private:
//     vector<vpr> bit;
//     lli x;
//     lli y;

// public:
//     FenwickTree(lli n,lli m){
//         x=n+2;
//         y=m+2;
//         bit.assign(x+18,vpr(y+18));
//     }

//     void update(lli i,lli yy,pr p){
//         for(i;i<x;i+=(i& -i)){
//             lli j=yy;
//             for(j;j<y;j+=(j& -j)){
//                bit[i][j].ff+=p.ff;
//                bit[i][j].ss+=p.ss;
//             }
//         }
           
//     } 

//     pr query(lli i,lli yy){
//         pr sum;
//         for(i;i>0;i-=(i& -i)){
//             lli j=yy;
//             for(j;j>0;j-=(j& -j)){
//               sum.ff+=bit[i][j].ff;
//               sum.ss+=bit[i][j].ss;
//             }
//         }
//         return sum;
//     }

// };

// void solve(){
// lli n=0,m,k=0;string s;
// cin>>n>>m>>k;
// FenwickTree ft(n,m);
// lli t,x1,y1,x2,y2;
// map<vll,pr>mp;
// fr(i,k){
// cin>>t>>x1>>y1>>x2>>y2;

// if(t==1){
// lli a=rand();
// lli b=rand();
// pr x={a,b};
// pr xx={-a,-b};
//   mp[{x1,y1,x2,y2}]=x;
//   ft.update(x1,y1,x);
//   ft.update(x2+1,y2+1,x);
//   ft.update(x2+1,y1,xx);
//   ft.update(x1,y2+1,xx);
// }else if(t==2){
//     pr x=mp[{x1,y1,x2,y2}];
//     pr xx=x;
//     xx.ff*=-1;
//     xx.ss*=-1;
//     ft.update(x1,y1,xx);
//     ft.update(x2+1,y2+1,xx);
//     ft.update(x2+1,y1,x);
//     ft.update(x1,y2+1,x);
// }else{
//     if(ft.query(x1,y1)==ft.query(x2,y2))yes;
//     else no;
// }

// }
// }
// int32_t main(){
// fastio;
// lli test=1;
// // cin>>test;
// while(test--){
// solve();
// }
// }
//Author:coding_with_alzheimer
//Date: 2026-08-20 02:09

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
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define no1 cout<<"-1\n"
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class FenwickTree{
private:
    vvll bit;
    lli x;
    lli y;

public:
    FenwickTree(lli n,lli m){
        x=n+2;
        y=m+2;
        bit.assign(x+18,vll(y+18));
    }

    void update(lli i,lli yy,lli val){
        for(i;i<x;i+=(i& -i)){
            lli j=yy;
            for(j;j<y;j+=(j& -j)){
               bit[i][j]+=val;
            }
        }
           
    } 

    lli query(lli i,lli yy){
        lli sum=0;
        for(i;i>0;i-=(i& -i)){
            lli j=yy;
            for(j;j>0;j-=(j& -j)){
              sum+=bit[i][j];
            }
        }
        return sum;
    }

};

void solve(){
lli n=0,m,k=0;string s;
cin>>n>>m>>k;
FenwickTree ft(n,m);
srand(998244353);
lli t,x1,y1,x2,y2;
map<vll,lli>mp;
fr(i,k){
cin>>t>>x1>>y1>>x2>>y2;
if(t==1){
  lli x=rand();
  mp[{x1,y1,x2,y2}]=x;
  ft.update(x1,y1,x);
  ft.update(x2+1,y2+1,x);
  ft.update(x2+1,y1,-x);
  ft.update(x1,y2+1,-x);
}else if(t==2){
    lli x=mp[{x1,y1,x2,y2}];
    ft.update(x1,y1,-x);
    ft.update(x2+1,y2+1,-x);
    ft.update(x2+1,y1,x);
    ft.update(x1,y2+1,x);
}else{
    if(ft.query(x1,y1)==ft.query(x2,y2))yes;
    else no;
}

}
}
int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}