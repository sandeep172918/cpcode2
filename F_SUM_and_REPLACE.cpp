//Author:coding_with_alzheimer
//Date: 2026-08-22 20:14

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
vll d;


class Segment_Tree{
   struct node{
    lli sum;
    array<lli,8>ver;
    lli lazy;
    node(){
        sum=0;
        lazy=0;
    }
   };

   vector<node>t;
   vector<lli>v;
   lli n;
   public:
    Segment_Tree(){

    }
    Segment_Tree(lli a){
      vll temp(a);
      init(temp);
    }
    Segment_Tree(vector<lli>&a){
       init(a);
    }
    void init(vector<lli>&a){
       n=a.size(); 
       v=a;
       t.resize(4*n+1);
       build(1,0,n-1);

    }
  
    node merge(node a,node b){ //isme lazy nhi sochna hota
        node temp;
        temp.sum=a.sum+b.sum;
        fr(i,8){
            temp.ver[i]=a.ver[i]+b.ver[i];
        }
        return temp;
    }


    void build(lli id,lli l,lli r){
        if(l==r){
            t[id].sum=v[l];
            t[id].lazy=0;
            t[id].ver[0]=v[l];
            frs(i,1,7){
                t[id].ver[i]=d[t[id].ver[i-1]];
            }
            return;
        }
        lli mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    void apply(lli id,lli l,lli r){
        lli x=t[id].lazy;
        if(x>7)x=7;
        array<lli,8>c;
        fr(i,8){
            c[i]=t[id].ver[min(7ll,i+x)];
        }
        t[id].ver=c;
        t[id].sum=t[id].ver[0];
        return;
    }

    void push(lli id,lli l,lli r){
        if(t[id].lazy !=0){
           apply(id,l,r);
           if(l!=r){
           t[2*id].lazy+=t[id].lazy;
           t[2*id+1].lazy+=t[id].lazy;
           }
        }
        t[id].lazy=0;
    }

    void update(lli id,lli l,lli r,lli lq,lli rq,lli val){
      push(id,l,r);
      if(rq<l || r<lq){
        return;
      }
      if(lq<=l && r<=rq){
        t[id].lazy+=val;
        push(id,l,r);
        return;
      }
      lli mid=(l+r)/2;
      update(2*id,l,mid,lq,rq,val);
      update(2*id+1,mid+1,r,lq,rq,val);
      t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    node query(lli id,lli l,lli r,lli lq,lli rq){
      push(id,l,r);
      if(rq<l || r<lq){
        return node();
      }
      if(lq<=l && r<=rq){
        return t[id];
      }
      lli mid=(l+r)/2;
      return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
    }
    lli quer(lli l,lli r){
        node ans=query(1,0,n-1,l,r);
        return ans.sum;
    }
  
};

vll divisors(lli lmt){ // divisors with sieve style divisor of all upto lmt
        vll div(lmt+1);
        for(lli i=1;i<=lmt;i++){
            for(lli j=i;j<=lmt;j+=i){
                div[j]++;
            }
        }
        return div;
}

void solve(){
lli n=0,m,k=0;string s;
cin>>n>>k;
get(v,n);
//cin>>s;
d=divisors(mxe(v));
Segment_Tree st(v);
fr(i,k){
    lli t,l,r;
    cin>>t>>l>>r;
    l--;
    r--;
    if(t==1){
        st.update(1,0,n-1,l,r,1);
    }else{
        cout<<st.quer(l,r)<<'\n';
    }
}

}

int32_t main(){
fastio;
lli test=1;
// return 1;
// cin>>test;0
// return 1;
// lli ans=1;
// lli k=0;
// frs(i,2,1e6){
//     if(i==1e6){
//         cout<<i<<'\n';
//     }
//     lli c=0;
//     lli j=i;
//    while(j!=2){
//     j=v[j].size();
//     c++;
//    }
//    if(c>ans){
//     cout<<i<<'\n';
//     ans=c;
//    }
// }
// cout<<v[5040].size();

// cout<<ans<<'\n';
while(test--){
solve();
}
}