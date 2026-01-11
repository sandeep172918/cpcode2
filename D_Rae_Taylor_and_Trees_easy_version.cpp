// //Author: sandeep172918
// //Date: 2026-01-10 22:52

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
// const int MOD=1e9+7;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// lli op(lli a,lli b){
//     return min(a,b);
// }

// vector<lli>par;
// vector<lli>sz;
// class UnionFind
// {

 
// public:
//     UnionFind(lli n)
//     {
//         par = vector<lli>(n);
//         iota(par.begin(), par.end(), 0);
//         sz = vector<lli>(n, 1);
//     }
 
//     lli find(lli u)
//     {
//         // this optimisation was good.
//         if (par[u] != par[par[u]])
//             par[u] = find(par[par[u]]);
//         return par[u];
//     }
 
//     bool connected(lli u, lli v)
//     {
//         u = find(u);
//         v = find(v);
//         if (u == v)
//             return true;
//         return false;
//     }
//     bool join(lli u, lli v)
//     {
//         u = find(u);
//         v = find(v);
//         if (u == v)
//             return false;
//         if (sz[u] <= sz[v])
//         {
//             sz[v] += sz[u];
//             par[u] = v;
//         }
//         else
//         {
//             sz[u] += sz[v];
//             par[v] = u;
//         }
//         return true;
//     }
    
// };

void solve(){
lli n,k;cin>>n;
get(v,n);

map<lli,lli>m,mm;
fr(i,n)m[v[i]]=i;
fr(i,n)v[i]--;
UnionFind u(n);
vll pref(n);
vll suff(n);
partial_sum(all(v),pref.begin(),op);
suff[n-1]=v[n-1];
rfr(i,n-2,0){
  suff[i]=max(suff[i+1],v[i]);
}
// out(pref);out(suff);
frs(i,1,n-1){
    if(pref[i-1]<v[i])u.join(pref[i-1],v[i]);
}
rfr(i,n-2,0){
    if(suff[i+1]>v[i])u.join(suff[i+1],v[i]);
}
// // out(par);
// // lli cnt=count(all(par),par[0]);
// // if(cnt==n)yes;
// // else no;

// fr(i,n)mm[par[i]]++;
// if(mm.size()>2)no;
// else{
//   if(mm.size()==2){
//    vll t;
//    for(auto &it:mm){
//     t.psb(it.ff);
//    }
//    lli x=m[t[0]];
//    lli y=m[t[1]];
//    if(x<y)yes;
//    else no;

//   }else yes;
// }

// }

// int32_t main(){
// fastio;
// lli test=1;
// cin>>test;
// while(test--){
// solve();
// }
// }

//   !


#include<bits/stdc++.h>
using namespace std;
#define ll long long

class UnionFind
{
private:
    vector<int> par;
    vector<int> sz;
 
public:
    UnionFind(int n)
    {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }
 
    int find(int u)
    {
        // this optimisation was good.
        if (par[u] != par[par[u]])
            par[u] = find(par[par[u]]);
        return par[u];
    }
 
    bool connected(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return true;
        return false;
    }
    bool join(int u, int v)
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

int main(){
    int t9; 
    cin >> t9;
    while(t9--){
    ll a,b,c,d;
    cin>>a;
    // string s;
    // cin>>s;
    vector<ll> v(a);
    vector<ll> prmn(a);
    vector<ll> sfmx(a);
    // map<ll,ll>m;
    for(int i=0;i<a;i++){
      cin>>v[i];
      v[i]--;
    }
    prmn[0]=v[0];
    ll sm=v[0];
    for(int i=0;i<a-1;i++){
       sm=min(sm,v[i]);
        prmn[i+1]=sm;
    }
     sfmx[a-1]=v[a-1];
    sm=v[a-1];
    for(int i=a-1;i>0;i--){
       sm=max(v[i],sm);
       sfmx[i-1]=sm;
    }
// for(auto it:sfmx){
//     cout<<it<<" ";
// }
    vector<pair<int,int>>an;
    int f=0;
    for(int i=1;i<a;i++){
        if(prmn[i]<v[i]){
            an.push_back({prmn[i],v[i]});
        }else if(sfmx[i]>prmn[i]&&sfmx[i]>v[i]){
            an.push_back({v[i],sfmx[i]});
            an.push_back({prmn[i],sfmx[i]});
        }else{
            f=1;
            break;
        }
    }
    if(f==1){
        cout<<"NO"<<endl;
    }else{
         cout<<"YES"<<endl;
        //  UnionFind uf(a);
        //  vector<pair<int,int>>p;
        //  for(auto &it:an){
        //     if(uf.join(it.first,it.second)){
        //       p.push_back({it.first,it.second});
        //     }
        //  }
        //  for(auto &it:p){
        //     cout<<it.first+1<<' '<<it.second+1<<'\n';
        //  }
    }


    // cout<<<<endl;
}}