
//Author: sandeep172918
//Date: 2026-01-17 22:44

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
const int MOD=998244353;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pr dp[107][107][4];
string s;
pr nn={-1,-1};

pr ccc(lli i,lli bal,lli c){
    if(bal<0)return{0,0};
    if(i==s.size()){
        if(bal==0 && c==3){
            return {1,0-2};
        }else return {0,0};
    }
    if(dp[i][bal][c]!=nn)return dp[i][bal][c];
    

    lli w=0;
    lli l=0;

    //no take
    pr nt=ccc(i+1,bal,c);
    w=(w+nt.ff)%MOD;
    l=(l+nt.ss+0)%MOD;

    //take

    if(s[i]=='('){
        //if(c==1 || c==2)c++;
        lli nc=c;
        if(c==1 ||c==2)nc++;
        pr t=ccc(i+1,bal+1,nc);
         w=(w+t.ff)%MOD;
         l=(l+t.ss+t.ff)%MOD;

    }else{
        if(bal>0){
          //if(c==0)c++;
          lli nc=c;
          if(c==0)nc++;
          pr t=ccc(i+1,bal-1,nc);
           w=(w+t.ff)%MOD;
           l=(l+t.ss+t.ff)%MOD;

        }
    }
    return dp[i][bal][c]={w,l};
}

void solve(){
lli n,k;cin>>n;
fr(i,107){
    fr(j,107){
        fr(k,4){
            dp[i][j][k]={-1,-1};
        }
    }
}
s.clear();
cin>>s;

pr res=ccc(0,0,0);
cout<<res.ss<<'\n';

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}
