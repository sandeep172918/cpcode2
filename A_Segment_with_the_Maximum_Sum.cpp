//Author:coding_with_alzheimer
//Date: 2026-08-05 17:14

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


class Segment_Tree{
   struct node{
    lli sum;
    // lli lazy;
    lli ans;
    lli pref;
    lli suff;
    node(){
        sum=0;
        ans=-1e18;
        pref=-1e18;
        suff=-1e18;
        // lazy=0;
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
  
    node merge(node a,node b){ 
        node temp;
        temp.sum=a.sum+b.sum;
        temp.pref=max({a.sum+b.pref,a.pref});
        temp.suff=max({a.suff+b.sum,b.suff});
        temp.ans=max({a.ans,b.ans,a.suff+b.pref});
        return temp;
    }


    void build(lli id,lli l,lli r){
        if(l==r){
            t[id].sum=v[l];
            t[id].ans=v[l];
            t[id].pref=v[l];
            t[id].suff=v[l];
            // t[id].lazy=0;
            return;
        }
        lli mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    // void apply(lli id,lli l,lli r){
    //      t[id].sum+=((r-l+1)*t[id].lazy);
    //      return;
    // }

    // void push(lli id,lli l,lli r){
    //     if(t[id].lazy !=0){
    //        apply(id,l,r);
    //        if(l!=r){
    //        t[2*id].lazy+=t[id].lazy;
    //        t[2*id+1].lazy+=t[id].lazy;
    //        }
    //     }
    //     t[id].lazy=0;
    // }

    void update(lli id,lli l,lli r,lli lq,lli rq,lli val){
    //   push(id,l,r);
      if(rq<l || r<lq){
        return;
      }
      if(lq<=l && r<=rq){
        // t[id].lazy+=val;
        t[id].sum=val;
        t[id].pref=val;
        t[id].suff=val;
        t[id].ans=val;
        // push(id,l,r);
        return;
      }
      lli mid=(l+r)/2;
      update(2*id,l,mid,lq,rq,val);
      update(2*id+1,mid+1,r,lq,rq,val);
      t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    node query(lli id,lli l,lli r,lli lq,lli rq){
    //   push(id,l,r);
      if(rq<l || r<lq){
        return node();
      }
      if(lq<=l && r<=rq){
        return t[id];
      }
      lli mid=(l+r)/2;
      return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
    }
    lli quer(){
        node ans=query(1,0,n-1,0,n-1);
        return ans.ans;
    }
    // lli query_bs(lli id,lli l,lli r,lli lq,lli x){ //first element greater than x in range lq till end
    //   push(id,l,r); 
    //   if(r<lq)return -1;
    //   if(t[id].sum<x)return -1;
    //   if(l==r)return l;
    //   lli mid=(l+r)/2;
    //   lli left=query_bs(2*id,l,mid,lq,x);
    //   if(left!=-1)return left;
    //   return query_bs(2*id+1,mid+1,r,lq,x);
    // }
};



void solve(){
lli n=0,k=0;string s;
cin>>n>>k;
get(v,n);
v.psb(0);
n++;
Segment_Tree st(v);
cout<<st.quer()<<'\n';
fr(i,k){
    lli j,val;
    cin>>j>>val;
    st.update(1,0,n-1,j,j,val);
    cout<<st.quer()<<'\n';
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