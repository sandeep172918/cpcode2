//Author:coding_with_alzheimer
//Date: 2026-06-12 21:08

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli short
#define fr(i,n) for(lli i=0;i<n;i++)
#define frs(i,a,b) for(lli i=a;i<=b;i++)
#define rfr(i,b,a) for(lli i=b;i>=a;i--)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define pr pair<lli,lli>
#define vll vector<short>
#define vbl vector<bool>
#define vpr vector<pr>
#define vvll vector<vector<short>>
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

lli l[6001][6001];
lli r[6001][6001];

void solve(){
lli n=0,k=0;string s;
cin>>n;
get(v,n);
k=6001;
//cin>>s;
vector<bool> vis(n+2,false);
lli mini;
lli maxi;
vpr used;
fr(i,n){
    mini=v[i];
    maxi=v[i];
    frs(j,i,n-1){
        if(vis[v[j]])break;
        vis[v[j]]=1;
        mini=min(mini,v[j]);
        maxi=max(maxi,v[j]);
        if(maxi-mini==j-i){
            if(r[mini][maxi]>j)r[mini][maxi]=j;
            if(l[mini][maxi]<i)l[mini][maxi]=i;
        }
    }
    frs(j,i,n-1){
        if(!vis[v[j]])break;
        vis[v[j]]=0;
    }
}
lli ans=0;
lli low=1,high=n;
while(low<=high){
    lli mid=low+(high-low)/2;
    lli ll=mid;
    bool bol=false;

  frs(mn1,1,n-2*ll+1){
      lli mx1=mn1+ll-1;
      lli mn2=mn1+ll;
      lli mx2=mn1+2*ll-1;
      if(r[mn1][mx1]!=k && r[mn2][mx2]!=k){
            if(r[mn1][mx1]<l[mn2][mx2] || r[mn2][mx2]<l[mn1][mx1]){
                bol=true;
                ans=max(ans,ll);
            }
      }
  }
  if(bol)low=mid+1;
  else high=mid-1;

}
cout<<ans<<'\n';
mini=mne(v);
maxi=mxe(v);
frs(i,mini,maxi){
  frs(j,mini,maxi){
    l[i][j]=-1;
    r[i][j]=6001;
  }
}

}

int32_t main(){
fastio;
lli test=1;
memset(l,-1,sizeof(l));
memset(r,6001,sizeof(r));
cin>>test;
while(test--){
solve();
}
}