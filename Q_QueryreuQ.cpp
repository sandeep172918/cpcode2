//Author:coding_with_alzheimer
//Date: 2026-09-26 12:04

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
class manacher{
    private:
    string s;
    string a;
    vll d;
    lli n;
    public:
    manacher(const string &a){
    }
    void update(const string &a){
       s="%";
       fr(i,a.size()){
         s+=a[i];
         s+='%';
       }
       n=s.size();
       d.assign(n,1);
       build();
    }
    void build(){
        lli l=1,r=1;
        frs(i,1,n-1){
            d[i]=max(0ll,min(r-i,d[l+(r-i)]));
            while(i+d[i]<n && i-d[i]>=0 && s[i+d[i]]==s[i-d[i]])d[i]++;
            if(r<i+d[i]){
                r=i+d[i];
                l=i-d[i];
            }
        }
    }
    lli longp(lli c,bool odd){
        lli i=2*c+1+(!odd);
        return d[i]-1;
    }
    lli tot(lli l,lli r){
        lli ans=0;
        frs(i,l,r){
            lli x=longp(i,1);
            lli y=min({x,(i-l)*2+1,(r-i)*2+1});
            ans+=(y+1)/2;
        }
        frs(i,l,r-1){
           lli x=longp(i,0);
           lli y=min({x,(i-l)*2+2,(r-i-1)*2+2});
           ans+=y/2;
        }
        return ans;
    }


};



void solve(){
lli n=0,k=0;string s;
cin>>n;
//get(v,n);
cin>>s;
string c="";
manacher mc(c);
vll ans(n+1);
fr(i,n){
  if(s[i]=='-'){
    c.ppb;
  }
  else {
    c+=s[i];
    mc.update(c);
    ans[c.size()]=mc.tot(0,c.size()-1);
  }
  cout<<ans[c.size()]<<' ';
}

}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}