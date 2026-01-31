//Author: sandeep172918
//Date: 2026-01-29 21:58

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

lli dp[31][3][3];
//0  -- p>x 
// 1 --  p<x  
//2 x==p
pr c[31][3][3];
lli xx,yy;
lli dpp(lli b,lli x,lli y){
    if(b<0)return 0;
    if(dp[b][x][y]!=-1)return dp[b][x][y];
    lli ans=1e18;

    lli bx=(xx>>b)&1;
    lli by=(yy>>b)&1;

    vpr mv={{0,0},{1,0},{0,1}};

    for(auto &[bp,bq] :mv){
        lli nx=x;
        lli ny=y;
        
        if(x==2){ 
          if(bp>bx){
               nx=0;
          }else if(bp<bx){
             nx=1;
          }
        }
         if(y==2){
          if(bq>by){
               ny=0;
          }else if(bq<by){
             ny=1;
          }
        }
        
        lli curr=(abs(bx-bp)+abs(by-bq))*(1LL<<b)+dpp(b-1,nx,ny);

        if(curr<ans){
            ans=curr;
            c[b][x][y]={bp,bq};
        }

    }
    return dp[b][x][y]=ans;
}

void solve(){
cin>>xx>>yy;
memset(dp,-1,sizeof(dp));
memset(c,-1,sizeof(c));
dpp(30,2,2);
lli p=0,q=0;
lli x=2,y=2;
rfr(i,30,0){
    pr ch=c[i][x][y];
    lli bp=ch.ff;
    lli bq=ch.ss;
    
    if(bp)p|=(1LL<<i);
    if(bq)q|=(1LL<<i);

    lli bx=(xx>>i)&1;
    lli by=(yy>>i)&1;


    if(x==2){
        if(bp>bx)x=0;
        else if(bx>bp)x=1;
    }
    if(y==2){
        if(bq>by)y=0;
        else if(by>bq)y=1;
    }

}

cout<<p<<' '<<q<<'\n';
}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}
