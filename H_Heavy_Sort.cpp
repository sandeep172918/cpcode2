//Author:coding_with_alzheimer
//Date: 2026-04-06 17:15

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


class FenwickTree{
private:
    vector<lli>bit;
    lli n;

public:
    FenwickTree(lli size){
        n=size+1;
        bit.assign(n,0);
    }

    void update(lli i,lli val){
        for(++i;i<n;i+=(i& -i))
            bit[i]+=val;
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
    
     lli kth(lli k){ 
        lli idx=0, bitt=1;
        while((bitt<<1)<=n) bitt<<=1;
        for(lli step=bitt; step; step>>=1){
            lli nxt=idx+step;
            if(nxt<=n && bit[nxt]<k){ k-=bit[nxt]; idx=nxt; }
        }
        return idx+1;
    }
};

void solve(){
lli n=0,k=0,m=0,x=0;cin>>n;
FenwickTree ft(n);
get(h,n);
get(w,n);
vvll v(n);
fr(i,n){
    v[i]={h[i],i,w[i]};
}
srt(v);
lli ans=0;
fr(i,n){
  lli wt=v[i][2];
  lli id=v[i][1];
  ans+=ft.range_query(id,n-1)*wt;
  ft.update(id,wt);
}
cout<<ans<<'\n';

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}