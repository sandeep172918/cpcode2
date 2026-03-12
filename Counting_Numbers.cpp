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
using namespace std;
const int MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


lli dp[20][11][2][2];

lli dppp(string s,lli pos,bool tight,lli prev,bool lead){ 
    if(pos==s.size()){
        return 1;
    }
    if(dp[pos][prev][tight][lead]!= -1)return dp[pos][prev][tight][lead];
    lli ub=tight ? (s[pos]-'0'):9;
    lli c=0;
    fr(i,ub+1){
        
        bool nt=tight&(i==ub);
        bool nld=lead&(i==0);
        
        if(!nld && i==prev)continue;

        c+=dppp(s,pos+1,nt,i,nld);
    }
    
    return dp[pos][prev][tight][lead]=c;
}

void solve(){
string r;lli l;cin>>l>>r;
l--;
string ll=to_string(l);
memset(dp,-1,sizeof(dp));
lli b=dppp(r,0,true,10,true);
memset(dp,-1,sizeof(dp));
lli a=dppp(ll,0,true,10,true);
cout<<b-a<<'\n';

}

int32_t main(){
fastio;
lli tt=1;
//cin>>tt;
while(tt--){
solve();
}
}