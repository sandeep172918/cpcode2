//Author:coding_with_alzheimer
//Date: 2026-09-08 22:42

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
        return temp;
    }


    void build(lli id,lli l,lli r){
        if(l==r){
            t[id].sum=(v[l]==0);
            t[id].lazy=0;
            return;
        }
        lli mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    void apply(lli id,lli l,lli r){
         t[id].sum+=((r-l+1)*t[id].lazy);
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
    //   push(id,l,r);
      if(rq<l || r<lq){
        return;
      }
      if(lq<=l && r<=rq){
        // t[id].lazy+=val;
        t[id].sum=(val==0);
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
    lli quer(lli l,lli r){
        node ans=query(1,0,n-1,l,r);
        return ans.sum;
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
lli n=0,m,k=0;string s;
cin>>n;
get(v,n);
vll ans(n);
Segment_Tree st(v);
if(count(all(v),-1)==n){
    cout<<"1";
    fr(i,n-1)cout<<"0";
    nl;
    return;
}

fr(i,n){
    if(v[i]==0){
       ans[i]=1;
    }else if(v[i]>0){
      k=st.quer(max(0ll,i-v[i]+1),min(n-1,i+v[i]-1));
      if(k>0){
        no1;
        return;
      }
      lli bol=0;
      if(i-v[i]<0)bol++;
      if(i+v[i]>=n)bol++;
      if(i-v[i]>=0){
        if(v[i-v[i]]<=0){ 
            ans[i-v[i]]=1;
            v[i-v[i]]=0;
            st.update(1,0,n-1,i-v[i],i-v[i],0);
        }
        else bol++;
      }else if(i+v[i]<n){
        if(v[i+v[i]]<=0) {
            ans[i+v[i]]=1;
            v[i+v[i]]=0;
            st.update(1,0,n-1,i+v[i],i+v[i],0);
        }
        else bol++;
      }
      if(bol>=2){
        no1;
        return;
      }
    }
}
bool bol=0;
fr(i,n){
    if(ans[i]==1)bol=1;
}
if(bol){
    fr(i,n)cout<<ans[i];
    nl;
    return;
}
no1;

}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}