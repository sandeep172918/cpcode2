//Author:coding_with_alzheimer
//Date: 2026-08-12 01:00

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
lli n=0,k=0,m,x,y;string s;
cin>>n>>m>>x>>y;
set<lli>a,b,c;
fr(i,x){
 cin>>k;
 k=-k;
 a.insert(k);
 c.insert(k);
}
fr(i,y){
 cin>>k;
 k=-k;
 b.insert(k);
 c.insert(k);
}
lli aa=0,bb=0,tot=0;
lli sum=0;
for(auto &it:c){
    if(tot==(n+m-1))break;
    if(a.count(it) && b.count(it)){
        tot++;
        sum+=it;
    }else if(a.count(it)){
        if(aa<n){
            sum+=it;
            tot++;
            aa++;
        }
    }else{
        if(bb<m){
            sum+=it;
            tot++;
            bb++;
        }
    }
}
cout<<(-sum)<<'\n';
// rsrt(a);
// rsrt(b);
// vll aa,bb;
// lli i=0,j=0;
// set<lli>st;
// lli c=0;
// while(i<x || j<y){
//    if(i<x && j<y && a[i]>b[j]){
//       if(st.find(a[i])==st.end()){
//           if(aa.size()<(n-1)){
//       st.insert(a[i]);
//           aa.psb(a[i]);
//           }else c=max(c,a[i]);
         
//       }
//       i++;
//    }else if(i<x && j<y && a[i]<b[j]){
//      if(st.find(b[j])==st.end()){
//         if(bb.size()<(m-1)){
//    st.insert(b[j]);
//         bb.psb(b[j]);
//         }else c=max(c,b[j]);
     
//      }
//      j++;
//    }else if(i<x && j<y && a[i]==b[j]){
//     if(st.find(a[i])==st.end()){
//         if(aa.size()<n-1 || bb.size()<m-1){
//             if(n-1-aa.size()>=m-1-bb.size()){
//                 aa.psb(a[i]);
//             }else{
//                 bb.psb(b[j]);
//             }
//             st.insert(a[i]);
//         }else c=max(c,a[i]);
//     }
//     i++;
//     j++;
//    }else if(i<x){
//      if(st.find(a[i])==st.end()){
//          if(aa.size()<(n-1)){
//   st.insert(a[i]);
//           aa.psb(a[i]);
//          }else c=max(c,a[i]);
        
//       }
//       i++;
//    }else if(j<y){
//      if(st.find(b[j])==st.end()){
//        if(bb.size()<(m-1)){
//    st.insert(b[j]);
//         bb.psb(b[j]);
//         }else c=max(c,b[j]);
//      }
//      j++;
//    }
  
// }


// while(i<x || j<y){
//   if(i<x && j<y && a[i]>b[j]){
//      if(st.find(a[i])==st.end())
//         c=max(c,a[i]);
//      i++;
//   }else if(i<x && j<y && a[i]<b[j]){
//      if(st.find(a[i])==st.end())
//         c=max(c,b[j]);
//      j++;
//   }else if(i<x && j<y && a[i]==b[j]){
//      if(st.find(a[i])==st.end())
//        c=max(c,a[i]);
//      i++;
//      j++;  
//   }else if(i<x){
//     if(st.find(a[i])==st.end())
//         c=max(c,a[i]);
//     i++;
//   }else if(j<y){
//     if(st.find(b[j])==st.end())
//         c=max(c,b[j]);
//      j++;
//   }
// }
// cout<<accumulate(all(aa),0ll)+accumulate(all(bb),0ll)+c<<'\n';
// lli r=n;
// lli c=m-1;
// if(x<r && y<c){
//     lli ans=0;
//     fr(i,x)ans+=a[i];
//     fr(i,y)ans+=b[i];
//     cout<<ans<<'\n';
//     return;
// }
// if(x<r){
//     swap(a,b);
//     swap(x,y);
//     swap(r,c);
// }
// lli ans=0;
// vll v(r);
// reverse(all(a));
// reverse(all(b));
// set<lli>st;
// fr(i,r){
//     v[i]=a[i];
//     ans+=a[i];
//     st.insert(a[i]);
// }
// lli j=0;
// fr(i,c){
//     while(j<y && st.find(b[j])!=st.end()){
//         j++;
//     }
//     if(j>=y)break;
//     ans+=b[j];
//     j++;
// }
// rfr(i,r-1,0){
//     while(j<y && st.find(b[j])!=st.end()){
//         j++;
//     }
//     if(j>=y)break;
//     if(v[i]>=b[j])break;
//     ans-=v[i];
//     ans+=b[j];
//     j++;
// }
// cout<<ans<<'\n';





}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}