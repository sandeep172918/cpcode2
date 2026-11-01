//Author:coding_with_alzheimer
//Date: 2026-11-01 11:39

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
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define ff first
#define ss second
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define psbp(a,b) push_back({a,b})
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define no1 cout<<"-1\n"
#define pn(x) cout<<(x)<<"\n"
#define pt(x) cout<<(x)<<" "
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
#define arr(a) array<lli,a>
using namespace std;
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

lli n,m;
map<pr,pr>mp;

// void fill(lli i,lli j,lli x,lli y,lli left,lli up){
//     set<lli>st;
//     st.insert(left);
//     st.insert(up);
//     lli c=0;
//     while(st.find(c)!=st.end())c++;
//     if(x==y){
//         m[{i,j}]=x;
//     }
 
//     if(x<=y){
//         fill(x,y-x,c,y);
//     }else{
//         fill(x-y,y,left,c);
//     }
// }

void solve(){
// lli n=0,k=0,ans=0;
// array<lli,1>arr;
// string s;
cin>>n>>m;
//get(v,n);
//cin>>s;
lli left=-1,up=-1;

lli x=n,y=m;
lli i=0,j=0;
lli c;
while(1){
    while(x>y){
    set<lli>st;
    st.insert(left);
    st.insert(up);
    c=0;
    while(st.find(c)!=st.end())c++;
    
 
    // if(x<y){
    //     x=x;
    //     y=y-x;
    //     left=c;
    //     up=up;
    //     mp[{i,j}]={x,c};
    //     i=i;
    //     j=j+x;

    // }else{
       x=x-y;
       y=y;
       left=left;
       up=c;
       mp[{i,j}]={y,c};
       i=i+y;
       j=j;
    // }
   }
   //y>x  here it is 

    
    set<lli>st;
    st.insert(left);
    st.insert(up);
    c=0;
    while(st.find(c)!=st.end())c++;


    if(x==y){
        mp[{i,j}]={x,c};
        break;
    }
        x=x;
        y=y-x;
        left=c;
        up=up;
        mp[{i,j}]={x,c};
        i=i;
        j=j+x;
        fr(k,x){
             set<lli>st;
          st.insert(left);
    st.insert(up);
    c=0;
    while(st.find(c)!=st.end())c++;

             mp[{(i+k),y}]={1,c};
             left=left;
             up=c;
        }
        j++;
        y--;


}
// for(auto &it:mp){
//     cout<<it.ff.ff<<' '<<it.ff.ss<<' '<<it.ss.ff<<' '<<it.ss.ss<<'\n';
// }
// return;
vector<vector<char>>v(n,vector<char>(m));
// vvll v(n,vll(m));
for(auto &it:mp){
    lli x=it.ff.ff;
    lli y=it.ff.ss;
    fr(i,it.ss.ff){
        fr(j,it.ss.ff){
           lli xx=x+i;
           lli yy=y+j;
           v[xx][yy]='A'+it.ss.ss;
        }
    }
}
fr(i,n){
    fr(j,m){
        cout<<v[i][j];
    }
    nl;
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