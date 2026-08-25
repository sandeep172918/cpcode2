//Author:coding_with_alzheimer
//Date: 2026-08-22 23:55

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
const lli MOD=1e9+9;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vll f;

class Segment_Tree{
   struct node{
    lli sum;
    lli lazy1;
    lli lazy2;
    node(){
        sum=0;
        lazy1=0;
        lazy2=0;
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
        temp.sum=(a.sum+b.sum)%MOD;
        return temp;
    }


    void build(lli id,lli l,lli r){
        if(l==r){
            t[id].sum=v[l];
            t[id].lazy1=0;
            t[id].lazy2=0;
            return;
        }
        lli mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    
    void apply(lli id,lli l,lli r){
       lli len=r-l+1;
       lli x=t[id].lazy1*f[len];
       x%=MOD;
       lli y=t[id].lazy2*(f[len+1]-1);
       y%=MOD;
       t[id].sum=(t[id].sum+x+y)%MOD;
    }

    void push(lli id,lli l,lli r){
        if(t[id].lazy1==0 && t[id].lazy2==0)return;
        apply(id,l,r);
        if(l!=r){
            lli mid=(l+r)/2;
            lli len=mid-l+1;
            lli a=t[id].lazy1;
            lli b=t[id].lazy2;
            lli aa=(a*f[len-1])%MOD+(b*f[len])%MOD;
            lli bb=(a*f[len])%MOD+(b*f[len+1]%MOD);
            aa%=MOD;
            bb%=MOD;
            t[2*id].lazy1+=a;
            t[2*id].lazy2+=b;
            t[2*id+1].lazy1+=aa;
            t[2*id+1].lazy2+=bb;
            t[2*id].lazy1%=MOD;
            t[2*id].lazy2%=MOD;
            t[2*id+1].lazy1%=MOD;
            t[2*id+1].lazy2%=MOD;
        }
        t[id].lazy1=0;
        t[id].lazy2=0;
    }

    void update(lli id,lli l,lli r,lli lq,lli rq,bool val){
      push(id,l,r);
      if(rq<l || r<lq){
        return;
      }
      if(lq<=l && r<=rq){
        lli k=l-lq+1;
        t[id].lazy1+=f[k];
        t[id].lazy2+=f[k+1];
        t[id].lazy1%=MOD;
        t[id].lazy2%=MOD;
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


// if hmko kisi subsegment of fibonacci ka sum chahiye toh all we need is its first two term and its len L

// sum= first_term * f[L] + second_term * (f[L+1] - 1)     

//  ye f precalculate krlo aur global rahega fibo wala hi mtlb f[3] hamesh 2 hi rahega first term second term change ho skte hai accordingly

// kth term = first_term * f[k-2] + second_term * f[k-1]




void solve(){
lli n=0,m,k=0;string s;
cin>>n>>k;
f=vll(n+10);
f[1]=1;
f[2]=1;
frs(i,3,n+9){
    f[i]=f[i-1]+f[i-2];
    f[i]%=MOD;
}
get(v,n);
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
// cin>>test;
while(test--){
solve();
}
}