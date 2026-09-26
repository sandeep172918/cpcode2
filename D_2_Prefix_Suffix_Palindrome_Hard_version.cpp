//Author:coding_with_alzheimer
//Date: 2026-09-26 11:07

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
    vll d;
    lli n;
    public:
     manacher(string a){
        s="+";
        fr(i,a.size()){
            s+=a[i];
            s+='+';
        }
        n=s.size();
        d.assign(n,1);
        build();
     }
     void build(){
        lli l=1,r=1;
        frs(i,1,n-1){
            d[i]=max(0ll,min(r-i,d[l+(r-i)]));
            while(i+d[i]<n && i+d[i]>=0 && s[i+d[i]]==s[i-d[i]])d[i]++;
            if(r<i+d[i]){
                r=i+d[i];
                l=i-d[i];
            }
        }
     }
     lli longp(lli cent,bool odd){
        lli i=2*cent+1+(!odd);
        return d[i]-1;
     }
     bool check(lli l,lli r){
        if((r-l+1)<=longp((l+r)/2,l%2==r%2))return 1;
        return 0;
     }
};

void solve(){
lli n=0,k=0;string s;
// cin>>n>>k;
//get(v,n);
cin>>s;
string a="",b="";
n=s.size();
lli l=0,r=n-1;
while(l<r){
    if(s[l]==s[r]){
        l++;
        r--;
    }else break;
}
if(l>=r){
    cout<<s<<'\n';
    return;
}
a=s.substr(0,l);
b=s.substr(r+1);
// if(b.size())reverse(all(b));
manacher mc(s);
lli ll=n-1,rr=0,c=0;
frs(i,l,r){
   if(mc.check(l,i)){
    if((i-l+1)>c){
        ll=i;
        c=(i-l+1);
    }
   }
}
lli c1=0;
rfr(i,r,l){
    if(mc.check(i,r)){
        if((r-i+1)>c1){
            rr=i;
            c1=(r-i+1);
        }
    }
}
string m="";
if(c>=c1){
  frs(i,l,ll){
    m+=s[i];
  }
}else{
    frs(i,rr,r){
        m+=s[i];
    }
}
cout<<a+m+b<<'\n';

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}