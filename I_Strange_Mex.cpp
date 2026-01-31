//Author: sandeep172918
//Date: 2026-01-22 23:41

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
        temp.sum=a.sum+b.sum;
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
    
    void apply(lli id,lli l,lli r){
         t[id].sum+=((r-l+1)*t[id].lazy);
         return;
    }

    void push(lli id,lli l,lli r){
        if(t[id].lazy !=0){
           apply(id,l,r);
           t[2*id].lazy+=t[id].lazy;
           t[2*id+1].lazy+=t[id].lazy;
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

    lli max_right_from(lli l, lli target){
    return max_right_util(1, 0, n-1, l, target);
    }

   lli max_right_util(lli id, lli l, lli r, lli ql, lli &target){
    push(id, l, r);

    if(r < ql) return -1;

    if(l >= ql){
        if(t[id].sum < target){
            target -= t[id].sum;
            return -1;
        }
        if(l == r){
            return l;
        }
    }

    lli mid = (l + r) / 2;

    lli left = max_right_util(2*id, l, mid, ql, target);
    if(left != -1) return left;

    return max_right_util(2*id+1, mid+1, r, ql, target);
   }

};

void solve(){
lli n,k;cin>>n;
lli N=1e6+2;
vll f(N,-1);
Segment_Tree s(f);
while(n--){
    lli t,x;cin>>t>>x;
    
     if(t==1){
        s.update(1,0,N-1,x,x,1);
     }else{
         s.update(1,0,N-1,x,x,-1);
     }
     lli ans=s.max_right_from(0,-1);
      cout<<ans<<'\n';
}

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}