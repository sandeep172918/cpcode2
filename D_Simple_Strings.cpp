//Author: sandeep172918
//Date: 2025-12-04 09:37

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
 
char find(char a,char b){
char put;

        fr(l,26){
            char check=97+l;
            if(check != a && check != b)put=check;
        }
        return put;
}
char find(char a,char b,char c){
  char put;

        fr(l,26){
            char check=97+l;
            if(check!=c && check != a && check != b)put=check;
        }
        return put;
        
}


void solve(){
string s;cin>>s;
lli n=s.size();
vvll v;
lli i=0;
while(i<n){
    lli check=s[i];
    vll temp;
     lli j=i;
     while(j<n){
        if(s[j]==check){
            temp.psb(j);
            j++;
            
        }else break;
     }
     i=j;
     v.psb(temp);


}
// for(auto &it:v){
//     out(it);
// }
lli kk=v.size();
fr(i,kk){
    lli k=v[i].size();
    if(i==0){
      if(k&1 && k>1){
        for(lli j=1;j<k;j+=2){
            if(s[v[i][j]]=='z')s[v[i][j]]='y';
            else s[v[i][j]]+=1;
        }
      }else if(k%2==0){
          char c=s[v[i][0]];
          
          char put;
          if(kk>=2){
            char ccc=s[v[i+1][0]];
            put=find(ccc,c);
          }else{
            if(c=='z')put='y';
            else put=c+1;
          }
          for(lli j=0;j<k;j+=2){
             s[v[i][j]]=put;
          }

          }
      
      continue;
    }
    if(i==(kk-1)){
     if(k&1 && k>1){
        for(lli j=1;j<k;j+=2){
            if(s[v[i][j]]=='z')s[v[i][j]]='y';
            else s[v[i][j]]+=1;
        }
      }else if(k%2==0){
          char c=s[v[i][0]];
          
          char put;
          if(kk>=2){
            char ccc=s[v[i-1][0]];
            put=find(ccc,c);
          }else{
            if(c=='z')put='y';
            else put=c+1;
          }
          for(lli j=1;j<k;j+=2){
             s[v[i][j]]=put;
          }

          }
      
      continue;
    }

    if(k&1 && k>1){
        for(lli j=1;j<k;j+=2){
            if(s[v[i][j]]=='z')s[v[i][j]]='y';
            else s[v[i][j]]+=1;
        }
      }else if(k%2==0){
        char c=s[v[i][0]];
        char cc=s[v[i-1][0]];
        char ccc=s[v[i+1][0]];

        char put=find(c,cc,ccc);

         for(lli j=1;j<k;j+=2){
            s[v[i][j]]=put;
         }
      
      }
}
cout<<s<<'\n';

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}