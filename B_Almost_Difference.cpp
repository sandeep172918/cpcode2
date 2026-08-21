//Author:coding_with_alzheimer
//Date: 2026-08-19 19:32

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

void print128(__int128_t n) {
    if (n == 0) { cout << 0 << '\n'; return; }
    if (n < 0) { cout << '-'; n = -n; }
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

class FenwickTreec{
private:
    vector<lli>bit;
    lli n;

public:
    FenwickTreec(lli size){
        n=size+1;
        bit.assign(n,0);
        // a.assign(size,0);
    }

    void update(lli i,lli val){
        for(++i;i<n;i+=(i& -i))
            bit[i]+=val;
    } 

    lli query(lli i){
        lli sum=0;
        for (++i;i>0;i-=(i& -i))
            sum+=bit[i];
        return sum;
    }

    lli range_query(lli l,lli r) {
        return query(r)-query(l-1);
    }
};
class FenwickTrees{
private:
    vector<lli>bit;
    lli n;

public:
    FenwickTrees(lli size){
        n=size+1;
        bit.assign(n,0);
    }

    void update(lli i,lli val){
        for(++i;i<n;i+=(i& -i))
            bit[i]+=val;
    } 

    lli query(lli i){
        lli sum=0;
        for (++i;i>0;i-=(i& -i))
            sum+=bit[i];
        return sum;
    }

    lli range_query(lli l,lli r) {
        return query(r)-query(l-1);
    }
};



void solve(){
lli n=0,m,k=0;
cin>>n;
get(v,n);
__int128_t ans = 0;
map<lli,lli>mp;
fr(i,n){
    mp[v[i]]++;
}
k=mp.size();
vll p;
for(auto &it:mp)p.psb(it.ff);
vll pc=p;
fr(i,k)pc[i]*=-1;
srt(pc);
FenwickTreec ft(k);
FenwickTrees ftt(k);
rfr(i,n-1,0){
   lli it=upper_bound(all(p),v[i]+1)-p.begin();
   lli j=lower_bound(all(p),v[i])-p.begin();
   lli c=ft.range_query(it,k-1);
   lli s=ftt.range_query(it,k-1);
   ans+=s-c*v[i];
   it=upper_bound(all(pc),-v[i]+1)-pc.begin();
   it=k-it-1;
   c=ft.range_query(0,it);
   s=ftt.range_query(0,it);
   ans+=s-c*v[i];
   ft.update(j,1);
   ftt.update(j,v[i]);

}
print128(ans);
}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}
// //Author:coding_with_alzheimer
// //Date: 2026-08-20 18:56

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define lli long long int
// #define fr(i,n) for(lli i=0;i<n;i++)
// #define frs(i,a,b) for(lli i=a;i<=b;i++)
// #define rfr(i,b,a) for(lli i=b;i>=a;i--)
// #define srt(v) sort(v.begin(),v.end())
// #define rsrt(v) sort(v.rbegin(),v.rend())
// #define pr pair<lli,lli>
// #define vll vector<lli>
// #define vbl vector<bool>
// #define vpr vector<pr>
// #define vvll vector<vector<lli>>
// #define get(v,n) vll v(n);fr(i,n)cin>>v[i]
// #define ff first
// #define ss second
// #define tr true
// #define fs false
// #define bitc(x) __builtin_popcountll(x)
// #define mxe(v)  *max_element(v.begin(),v.end())
// #define mne(v)  *min_element(v.begin(),v.end())
// #define psb(a) push_back(a)
// #define ppb pop_back()
// #define all(v) v.begin(),v.end()
// #define rall(v) v.rbegin(),v.rend()
// #define sq(x) sqrtl(x)
// #define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
// #define yes cout<<"YES\n"
// #define no cout<<"NO\n"
// #define no1 cout<<"-1\n"
// #define nl cout<<"\n"
// #define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
// #define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
// using namespace std;
// const lli MOD=1e9+7;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// void print128(__int128_t n) {
//     if (n == 0) { cout << 0 << '\n'; return; }
//     if (n < 0) { cout << '-'; n = -n; }
//     string s;
//     while (n > 0) {
//         s += (char)('0' + (n % 10));
//         n /= 10;
//     }
//     reverse(s.begin(), s.end());
//     cout << s << '\n';
// }

void solve(){
lli n=0,m,k=0;string s;
cin>>n;
get(v,n);
map<lli,lli>mp;
 __int128_t ans = 0;
fr(i,n){
  ans+=v[i]*(2*i-n+1);
  if(mp[v[i]-1])ans-=mp[v[i]-1];
  if(mp[v[i]+1])ans+=mp[v[i]+1];
  mp[v[i]]++;
}
print128(ans);
}

// int32_t main(){
// fastio;
// lli test=1;
// // cin>>test;
// while(test--){
// solve();
// }
// }