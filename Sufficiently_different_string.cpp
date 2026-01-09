//Author: sandeep172918
//Date: 2025-12-13 15:31

#include <bits/stdc++.h>
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
void solve(){
string s;lli n,k;
cin>>s>>k;
n=s.size();
map<char,lli>m;
fr(i,n)m[s[i]]++;
string ans="";
char c='*';
bool bol=true;
fr(i,26){
    if(ans.size()==n)break;
    if(m.find('a'+i)!=m.end()){
        if(k){
            ans+=('a'+i);
            k--;
        }

    }else{
        if(bol){
            c='a'+i;
            bol=false;
        }
        ans+=('a'+i);
    }
}
if(ans.size()<n){
    cout<<"NOPE\n";
    return;
}
cout<<ans<<'\n';
}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}