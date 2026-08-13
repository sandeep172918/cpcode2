//Author:coding_with_alzheimer
//Date: 2026-08-13 21:09

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
const lli MOD=5e9;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

lli n;
lli x;
vll s;
vll ss;
vll b;
vvll v;
map<lli,pr>m;
lli sum;
lli ms;
void up(lli id,lli msk){
    if(id==x){
        lli hash=(s[0]-s[2])*MOD+s[1]-s[2];
        auto it=m.find(hash);
        if(it==m.end() || it->ss.ff<s[0]){ 
          m[hash]={s[0],msk};
        }
        return;
    }
    fr(i,3){
        fr(j,3){
            if(i!=j){
                s[j]+=v[id][j];
            }
        }
        up(id+1,msk+b[id]*i);  
        fr(j,3){
            if(i!=j){
                s[j]-=v[id][j];
            }
        }
    }
}
void down(lli id,lli msk){
    if(id==n){
        lli hash=(ss[2]-ss[0])*MOD+ss[2]-ss[1];
        auto it=m.find(hash);
        if(it!=m.end() && it->ss.ff+ss[0]>sum){
           sum=it->ss.ff+ss[0];
           ms=msk+it->ss.ss;
        }
        return;
    }
    fr(i,3){
        fr(j,3){
            if(i!=j){
              ss[j]+=v[id][j];
            }
        }
        down(id+1,msk+b[id]*i);
        fr(j,3){
            if(i!=j){
                ss[j]-=v[id][j];
            }
        }
    }
}

void solve(){
cin>>n;
s=vll(3);
ss=vll(3);
v=vvll(n,vll(3));
b=vll(27,1);
x=n/2;
sum=-1e18;
//lmw
vector<string>ans={"MW","LW","LM"};
fr(i,n){
    fr(j,3){
        cin>>v[i][j];
    }
}
frs(i,1,26){
    b[i]=b[i-1]*3;
}
up(0,0);
down(x,0);

if(sum==-1e18){
    cout<<"Impossible\n";
    return;
}

fr(i,n){
    cout<<ans[ms%3]<<'\n';
    ms/=3;
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
