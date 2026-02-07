//Author: sandeep172918
//Date: 2026-02-06 02:20

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
#define out(v) fr(i,v.size())cout<<v[i]<<'\n';
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const int MOD=1e9+7;
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
    Segment_Tree(vector<lli>&a){
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
            t[id].sum=v[l];
            t[id].lazy=0;
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
    //        t[2*id].lazy+=t[id].lazy;
    //        t[2*id+1].lazy+=t[id].lazy;
    //     }
    //     t[id].lazy=0;
    // }

    void update(lli id,lli l,lli r,lli lq,lli rq,lli val){
      //push(id,l,r);
      if(rq<l || r<lq){
        return;
      }
      if(lq<=l && r<=rq){
        t[id].sum=val;
       // push(id,l,r);
        return;
      }
      lli mid=(l+r)/2;
      update(2*id,l,mid,lq,rq,val);
      update(2*id+1,mid+1,r,lq,rq,val);
      t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    lli query(lli id,lli l,lli r,lli ll){
     if(t[id].sum>=ll)return -1;
     if(l==r)return l;
     lli mid=(l+r)/2;
     lli left=query(2*id,l,mid,ll);
     if(left!=-1)return left;
     return query(2*id+1,mid+1,r,ll);
      
    }

    lli quer(lli l){
        lli ans=query(1,0,n-1,l);
        return ans;
    }
    void updat(lli pos,lli val){
        update(1,0,n-1,pos,pos,val);
    }
};

void solve(){
lli n,k;cin>>n>>k;
get(v,n);
fr(i,n)v[i]--;
vll last(n,-1);
vll f(n,0);
fr(i,n)f[v[i]]++;
fr(i,n){
    if(!f[i])last[i]=1e18;
}
vector<pair<pr,lli>>q(k);
fr(i,k){
   lli l,r;cin>>l>>r;
    l--;
    r--;
    q[i]={{r,l},i}; 
}
srt(q);
Segment_Tree s(last);
lli curr=0;
vll ans(k);
fr(i,k){
  lli r=q[i].ff.ff;
  lli l=q[i].ff.ss;
  lli id=q[i].ss;
  while(curr<=r){
    s.updat(v[curr],curr);
    curr++;
  }
  ans[id]=s.quer(l)+1;

}
out(ans);

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}