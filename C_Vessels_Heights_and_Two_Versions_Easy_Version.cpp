//Author:coding_with_alzheimer
//Date: 2026-06-07 21:02

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



void solve(){
lli n=0,k=0;string s;
cin>>n;
get(v,n);
//cin>>s;
lli id=-1;

fr(i,n){
if(k<v[i]){
    k=v[i];
    id=i;
}
}
vll a(n);
vll ans(n);

fr(i,n){
    a[i]=v[(i+id+1)%n];
}
// out(a);
// return;
stack<pr>st,st2;
lli curr=0;
vll l(n),r(n);
frs(i,1,n-1){
    k=a[i-1];
    lli c=1;
    while(!st.empty() && st.top().ff<=k){
        curr-=st.top().ff*st.top().ss;
        c+=st.top().ss;
        st.pop();
    }
    st.push({k,c});
    curr+=k*c;
    l[i]=curr;
}
// return;
curr=0;
rfr(i,n-2,0){
    k=a[i];
    lli c=1;
    while(!st2.empty() && st2.top().ff<=k){
        curr-=st2.top().ff*st2.top().ss;
        c+=st2.top().ss;
        st2.pop();
    }
    st2.push({k,c});
    curr+=k*c;
    r[i]=curr;
}
// return;
// fr(i,n){
//     cout<<l[i]+r[i]<<' ';
// }
// nl;
fr(i,n){
   ans[i]=l[i]+r[i];
}
fr(i,n){
    cout<<ans[(i-id+n-1)%n]<<' ';
}
nl;
}


int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}