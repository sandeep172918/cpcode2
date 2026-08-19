//Author:coding_with_alzheimer
//Date: 2026-08-19 23:04

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


class Segment_Tree{
   struct node{
    lli sum;
    lli lazy;
    node(){
        sum=0;
        lazy=0;
    }
   };

   vector<vector<node>>t;
   vector<vector<lli>>v;
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
       v.resize(n,vll(15));
       fr(i,n){
        v[i][0]=a[i];
       }
       t.resize(4*n+1,vector<node>(15));
       build(1,0,n-1,0);

    }
  
    node merge(node a,node b){ //isme lazy nhi sochna hota
        node temp;
        temp.sum=a.sum+b.sum;
        return temp;
    }

    void build(lli id,lli l,lli r,lli j){
        if(l==r){
            t[id][j].sum=v[l][j];
            // t[id].lazy=0;
            return;
        }
        lli mid=(l+r)/2;
        build(2*id,l,mid,j);
        build(2*id+1,mid+1,r,j);
        t[id][j]=merge(t[2*id][j],t[2*id+1][j]);
    }
   
    void update(lli id,lli l,lli r,lli lq,lli rq,lli j,lli val){
    //   push(id,l,r);
      if(rq<l || r<lq){
        return;
      }
      if(lq<=l && r<=rq){
        t[id][j].sum+=val;
        // push(id,l,r);
        return;
      }
      lli mid=(l+r)/2;
      update(2*id,l,mid,lq,rq,j,val);
      update(2*id+1,mid+1,r,lq,rq,j,val);
      t[id][j]=merge(t[2*id][j],t[2*id+1][j]);
    }
    
    node query(lli id,lli l,lli r,lli lq,lli rq,lli j){
    //   push(id,l,r);
      if(rq<l || r<lq){
        return node();
      }
      if(lq<=l && r<=rq){
        return t[id][j];
      }
      lli mid=(l+r)/2;
      return merge(query(2*id,l,mid,lq,rq,j),query(2*id+1,mid+1,r,lq,rq,j));
    }
    
};


void solve(){
lli n=0,m,k=0;string s;
cin>>n>>k;
k++;
get(v,n);
Segment_Tree st(n+1);
lli ans=0;
fr(i,n){
    st.update(1,0,n,v[i],v[i],1,1);
  frs(j,1,k){
    st.update(1,0,n,v[i],v[i],j,st.query(1,0,n,0,v[i]-1,j-1).sum);
  }
}
cout<<st.query(1,0,n,0,n,k).sum<<'\n';
}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}