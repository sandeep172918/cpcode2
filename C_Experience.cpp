//Author:coding_with_alzheimer
//Date: 2026-08-10 19:32

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
 vector<lli> par;
    vector<lli> sz;
    vector<lli>d;
    vector<lli>curr;
 
class UnionFind
{

   
public:
    UnionFind(lli n)
    {
        par = vector<lli>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<lli>(n, 1);
        d = vector<lli>(n);
        curr = vector<lli>(n);
    }
 
    lli find(lli u)
    {
        // this optimisation was good.
        if (par[u] != par[par[u]])
            par[u] = find(par[par[u]]);
        return par[u];
    }
    lli getval(lli u){
       lli ans=d[u];
       u=par[u];
       while(true){
        ans+=curr[u];
        if(u==par[u])break;
        u=par[u];
       }
    //    ans+=curr[u];
       return ans;
    }
 
    bool join(lli u, lli v)
    {
        u = find(u);
        v = find(v);
        if (u == v){

           return false;
        }
        if(sz[u]<sz[v])swap(u,v);
          sz[u] += sz[v];
            par[v] = u;
            d[v]-=curr[u];
            return 1;
        // if (sz[u] <= sz[v])
        // {
        //     sz[v] += sz[u];
        //     par[u] = v;
        //     d[u]-=curr[v];
        // }
        // else
        // {
           
        // }
        // return true;
    }
    void add(lli u,lli val){
        u=find(u);
        curr[u]+=val;
    }
    
};

void solve(){
lli n=0,k=0;string s;
cin>>n>>k;
UnionFind ds(n+1);
while(k--){
  cin>>s;
  lli u,v,val;
  if(s=="get"){
    cin>>u;
    // nl;
    cout<<ds.getval(u)<<"\n";
  }
  if(s=="join"){
    cin>>u>>v;
    if(u>v)swap(u,v);
    ds.join(u,v);
  }
  if(s=="add"){
    cin>>u>>val;
    ds.add(u,val);
  }

// out(par);
// out(sz);
// out(d);
// out(curr);
// cout<<"-----------\n";
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