//Author:coding_with_alzheimer
//Date: 2026-03-27 18:20

#include <bits/stdc++.h>
#define lli long long int
#define fr(i,n) for(lli i=0;i<n;i++)
#define frs(i,a,b) for(lli i=a;i<=b;i++)
#define rfr(i,b,a) for(lli i=b;i>=a;i--)
#define pr pair<lli,lli>
#define vll vector<lli>
#define vbl vector<bool>
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
const lli MOD=1e9+7;
lli dp[1000001][2];
void pre(){
  dp[0][0]=1;
  dp[0][1]=1;
  frs(i,1,1e6){
    dp[i][0]=2*dp[i-1][0]+dp[i-1][1];
    dp[i][0]%=MOD;
    dp[i][1]=4*dp[i-1][1]+dp[i-1][0];
    dp[i][1]%=MOD;
  }

}
void solve(){
lli n,k;cin>>n;
//get(v,n);
n--;
cout<<(dp[n][0]+dp[n][1]) %MOD<<'\n';
}

int32_t main(){
fastio;
pre();
lli test=1;
cin>>test;
while(test--){
solve();
}
}
/*
. . . . .
.       .   0
. . . . .
.       .   0
. . . . .

. . . . .
.       .  0
.       .
.       .  0
. . . . .

. . . . .
.   .   .  1
. . . . .
.       .  0
. . . . .

. . . . .
.   .   .  1
. . . . .
.   .   .  1
. . . . .

. . . . .
.       .  0
. . . . .
.   .   .  1
. . . . .

. . . . .
.   .   .  1
.   .   .
.   .   .  1
. . . . .

. . . . .
.   .   .  1
.   . . .
.   .   .  1
. . . . .

. . . . .
.   .   .  1
. . .   .
.   .   .  1
. . . . .


*/