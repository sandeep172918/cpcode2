//Author: sandeep172918
//Date: 2026-01-16 15:21

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
#define vvpr vector<vector<pr>>
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
 vector<lli> sz;
 vector<lli> par;

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
class UnionFind
{
private:
    
   
 
public:
    UnionFind(lli n)
    {
        par = vector<lli>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<lli>(n, 1);
    }
 
    lli find(lli u)
    {
        // this optimisation was good.
        if (par[u] != par[par[u]])
            par[u] = find(par[par[u]]);
        return par[u];
    }
 
    bool connected(lli u, lli v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return true;
        return false;
    }
    bool join(lli u, lli v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] <= sz[v])
        {
            sz[v] += sz[u];
            par[u] = v;
        }
        else
        {
            sz[u] += sz[v];
            par[v] = u;
        }
        return true;
    }
    
};


void solve(){
lli n,k;cin>>n>>k;

UnionFind uf(n);
fr(i,n-1){
    lli u,v,c;cin>>u>>v>>c;
    if(!c){
        uf.join(u-1,v-1); 
    }
}

// out(sz);
// out(par);
map<lli,lli>m;
fr(i,n){
    lli p=uf.find(i);
    m[p]=sz[p];
}
lli tot=(mod_pow(n,k)-n+MOD)%MOD;
//cout<<tot<<' ';
for(auto &it:m){
  //  cout<<it.ss<<'\n';
    lli curr=(mod_pow(it.ss,k)-it.ss+MOD)%MOD;
  //  cout<<curr<<' ';
    tot=(tot-curr+MOD)%MOD;
}
cout<<tot<<'\n';
}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}