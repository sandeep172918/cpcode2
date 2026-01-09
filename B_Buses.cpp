
//Author: sandeep172918
//Date: 2025-12-04 17:19

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long int
#define db  double
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
 int n, m, l, x, y;
    cin >> n >> m >> l >> x >> y;
    map<int, db> mpp;
    for(int i=0; i<n; i++){
        int s, t;
        cin >> s >> t;
        db time = (db)(t-s)/(db)x + (db)(l-t)/(db)y;
        // cout << time << " ";
        if(mpp.find(s) == mpp.end()){
            mpp[s] = time;
        } else{
            mpp[s] = min(mpp[s], time);
        }
    }
    vector<int> larr;
    vector<db> tarr;
    for(auto it : mpp){
        larr.push_back(it.first);
        tarr.push_back(it.second);
    }
    int sz = tarr.size();
    for(int i=1; i<sz; i++){
        tarr[i] = min(tarr[i], tarr[i-1]);
    }
     for(int i=0; i<m; i++){
        int p;
        cin >> p;
        int pos = upper_bound(larr.begin(), larr.end(), p) - larr.begin();
        db ans = (db)(l-p)/(db)y;
        if(pos==0){
            if(larr[pos]<=p){
                ans=min(ans,tarr[pos]);
            }
        }else{
            ans=min(tarr[pos-1],ans);
        }
        
        cout <<fixed<<setprecision(6)<< ans << endl;
    }
    


}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}