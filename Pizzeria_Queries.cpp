//Author:coding_with_alzheimer
//Date: 2026-04-08 16:43

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
#define psb(a) // push_back(a)
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
//BSDK math snippet hai


class Segment_Tree{
   struct node{
    lli sum;
    lli lazy;
    node(){
        sum=1e18;
        lazy=0;
    }
   };
   bool left;
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
    Segment_Tree(vector<lli>&a,bool bol){
        left=bol;
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
        temp.sum=min(a.sum,b.sum);
        return temp;
    }


    void build(lli id,lli l,lli r){
        if(l==r){
            if(left) t[id].sum=v[l]-l;
            else t[id].sum=v[l]+l;
            return;
        }
        lli mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    
   
    void update(lli id,lli l,lli r,lli lq,lli rq,lli val){
      // push(id,l,r);
      if(rq<l || r<lq){
        return;
      }
      if(lq<=l && r<=rq){
         if(left) t[id].sum=val-l;
            else t[id].sum=val+l;
        return;
      }
      lli mid=(l+r)/2;
      update(2*id,l,mid,lq,rq,val);
      update(2*id+1,mid+1,r,lq,rq,val);
      t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    node query(lli id,lli l,lli r,lli lq,lli rq){
      // push(id,l,r);
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
    void upd(lli i,lli va){
        update(1,0,n-1,i,i,va);
    }
   
};



void solve(){
lli n=0,k=0;cin>>n>>k;
get(v,n);
Segment_Tree st(v,1),st2(v,0);
while(k--){
    lli t,id,val;
    cin>>t>>id;id--;
    if(t==1){
       cin>>val;
       st.upd(id,val);
       st2.upd(id,val);
    }else{
        cout<<min(st.quer(0,id)+id,st2.quer(id,n-1)-id)<<'\n';
    }
}


}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}