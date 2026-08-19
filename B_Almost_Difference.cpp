//Author:coding_with_alzheimer
//Date: 2026-08-19 19:32

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
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class FenwickTree{
private:
    vector<lli>bit,a;
    lli n;

public:
    FenwickTree(lli size){
        n=size+1;
        bit.assign(n,0);
        a.assign(size,0);
    }

    void update(lli i,lli val){
        lli diff=val-a[i];
        a[i]=val;
        for(++i;i<n;i+=(i& -i))
            bit[i]+=diff;
    } 

    lli query(lli i){
        lli sum=0;
        for (++i;i>0;i-=(i& -i))
            sum+=bit[i];
        return sum;
    }

    lli range_query(lli l,lli r) {
        return query(r)-query(l-1);
    }
};

void solve(){
lli n=0,m,k=0;string s;
cin>>n;
get(v,n);
lli ans=0;
map<lli,lli>mp;
fr(i,n){
    mp[v[i]]++;
}
k=mp.size();
vll p;
for(auto &it:mp)p.psb(it.ff);
vll pp(k+1);
frs(i,1,k){
    pp[i]+=pp[i-1]+p[i-1]*(mp[p[i-1]]);
}
vll pc=p;
fr(i,k)pc[i]*=-1;
srt(pc);
FenwickTree ft(k);
rfr(i,n-1,0){
   lli it=upper_bound(all(p),v[i]+1)-p.begin();
   lli j=lower_bound(all(p),v[i])-p.begin();
   ft.update(j,1);
   lli c=ft.range_query(it,k-1);
   ans+=(pp[k]-pp[k-c])-c*v[i];
   it=upper_bound(all(pc),-v[i]+1)-pc.begin();
   it=k-it-1;
   c=ft.range_query(0,it);
   ans+=pp[c]-c*v[i];
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