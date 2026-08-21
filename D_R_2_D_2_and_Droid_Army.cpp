//Author:coding_with_alzheimer
//Date: 2026-08-21 23:13

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
class SparseTable {

private:
    vector<vector<lli>> st;
    vector<lli> lg;
    lli n, LOG;

public:

    SparseTable() {}

    SparseTable(const vector<lli>& a) {

        n = a.size();
        LOG = __lg(n) + 1;

        st.assign(LOG, vector<lli>(n));
        lg.assign(n + 1, 0);

        for(lli i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        for(lli i = 0; i < n; i++)
            st[0][i] = a[i];

        for(lli j = 1; j < LOG; j++) {
            for(lli i = 0; i + (1LL << j) <= n; i++) {

                st[j][i] = max(
                    st[j - 1][i],
                    st[j - 1][i + (1LL << (j - 1))]
                );
            }
        }
    }

    lli query(lli l, lli r) {

        lli len = r - l + 1;
        lli j = lg[len];

        return max(
            st[j][l],
            st[j][r - (1LL << j) + 1]
        );
    }
};

vector<SparseTable>st;
lli n=0,m,k=0;
vll check(lli len){
   if(len==0) return vll(m,0);
   vll t(m);
   fr(l,n){
    lli r=l+len-1;
    if(r>=n)break;
    lli sum=0;
    vll curr(m);
    fr(j,m){
        curr[j]=st[j].query(l,r);
        sum+=curr[j];
        if(sum>k)break;

    }
    if(sum<=k){
        return curr;
    }
   }
   return vll(m,k+1);
}

void solve(){
cin>>n>>m>>k;
st=vector<SparseTable>(m);
vvll v(m,vll(n));
fr(i,n){
    fr(j,m){
        cin>>v[j][i];
    }
}
fr(i,m){
    st[i]=SparseTable(v[i]);
}
lli low=0,high=n;
lli ans=0;
while(low<=high){
    lli mid=(low+high)/2;
    vll p=check(mid);
    lli pp=accumulate(all(p),0ll);
    if(pp<=k){
        ans=mid;
        low=mid+1;
    }else{
        high=mid-1;
    }
}
out(check(low-1));

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}