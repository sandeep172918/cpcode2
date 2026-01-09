// //Author: sandeep172918
// //Date: 2025-12-10 15:47

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
// const int MOD=1e9+7;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// vll con(lli x){
//     vll t;
//     while(x){
//         t.psb(x%2);
//         x/=2;
//     }
//   //  reverse(all(t));
//     return t;
// }


// void solve(){
// lli n,k;cin>>n>>k;
// vll nn=con(n);
// vll kk=con(k);

// while(nn.size()<kk.size())nn.psb(0);
// // reverse(all(nn));
// // reverse(all(kk));
// lli x=kk.size();

// lli lsb=-1;
// fr(i,x){
//  if(kk[i]){
//     lsb=i;
//     break;
//  }
// }
// //lsb tk hi change kr skte hai
// //aur uske bad sb same hona chiye
// if(lsb!=-1){ //k>0
//  fr(i,x){
//     if(i<lsb){
//     if(kk[i] && !nn[i]){
//         no1;
//         return;
//     }
//     }else{
//         if(kk[i]!=nn[i]){
//             no1;
//             return;
//         }
//     }
//  }

//  lli low=n;
//  lli high=0;
//  lli c=1;
//  fr(i,nn.size()){
//     if(i<lsb){
//      high+=c;
//     }else high=nn[i]*c;
//     c<<1LL;
//  } 





// }





// }

// int32_t main(){
// fastio;
// lli test=1;
// cin>>test;
// while(test--){
// solve();
// }
// }

//Author: sandeep172918
//Date: 2025-12-10 16:25

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
lli n,k;cin>>n>>k;
vll v(61);

fr(i,61){
    if(n>>i&1LL){ // ineed first element to be here 0 after n
      v[i]=(n&(~((1LL<<i)-1)))+(1LL<<i); //clear all below bits then add 1LL<<i
    }else{
        v[i]=n;
    }
}

lli ans=n;
fr(i,61){
    if((k>>i&1LL)==0LL){
      ans=max(ans,v[i]);
    }
}
fr(i,61){
    if(k>>i&1LL){
        if(ans>=v[i]){
            no1;
            return;
        }
    }
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