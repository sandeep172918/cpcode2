
#include <bits/stdc++.h>
#define lli long long int
#define fr(i,n) for(lli i=0;i<n;i++)
#define frs(i,a,b) for(lli i=a;i<=b;i++)
#define rfr(i,b,a) for(lli i=b;i>=a;i--)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define vec(v,n,k) vector<lli>v(n,k)
#define vect(v) vector<lli>v
#define vec2(v,x,y) vector<vector<lli>>v(x,vector<lli>(y));
#define pr pair<lli,lli>
#define take(x) lli x;cin>>x
#define get(v,n) vec(v,n,0);frs(i,0,n-1)cin>>v[i]
#define out(v,n) frs(i,0,n-1)cout<<v[i]
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sq(x) sqrtl(x)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<
#define no cout<<
#define ff first
#define ss second
using namespace std;
const int MOD=1e9+7;

class FenwickTree{
private:
    vector<lli>bit;
    lli n;

public:
    FenwickTree(lli size){
        n=size+1;
        bit.assign(n,0);
    }

    void update(lli i,lli val){
        for(++i;i<n;i+=(i& -i))
            bit[i]+=val;
    } 

    lli query(lli i){
        lli sum=0;
        for (++i;i>0;i-=(i& -i))
            sum+=bit[i];
        return sum;
    }

    lli range_query(lli l,lli r) {
        return query(r)-query(l-1);
    }

    lli kth(lli k){ 
        lli idx=0, bitt=1;
        while((bitt<<1)<=n) bitt<<=1;
        for(lli step=bitt; step; step>>=1){
            lli nxt=idx+step;
            if(nxt<=n && bit[nxt]<k){ k-=bit[nxt]; idx=nxt; }
        }
        return idx+1;
    }
};


lli inversion(vector<lli>&v){
  lli n=v.size();
  FenwickTree ft(n);
  vector<lli>temp(n);
  temp=v;
  srt(temp);
  map<lli,lli>rank;
  fr(i,n){
    rank[temp[i]]=i;
  }
  lli ans=0;
  rfr(i,n-1,0){
    lli index=rank[v[i]];
    ans+=ft.query(index-1);  //counting number of eleemnt less than v[i]
    ft.update(index,1);  // increasing number of that index;
  }
  return ans;
}

void solve(){
 lli n;
 cin>>n;
 vector<lli>v(n);
 fr(i,n)cin>>v[i];
 cout<<inversion(v)<<'\n';
}


int32_t main(){
fastio;
solve();

}












lli lsb(lli n){
    lli k=0;
    while(n){
        if(n&(1LL<<k)){
            return (1LL<<k);
        }
        k++;
    }
    return 0;
}

//make bit(fenwick)
void bit(vector<lli>&v){
    lli x=v.size();

    frs(i,1,x){
    if(i+lsb(i)<=x){
        v[i+lsb(i)]+=v[i];
    }
   }
}
lli prefix_sum(lli i,vector<lli>&v){
    lli sum=0;

    while(i>0){
     sum+=v[i];
     i-=lsb(i);
    }
    return sum;
}

void update(vector<lli>&v,lli a,lli d){
    lli x=v.size();
    v[a]+=d;
    while(a+lsb(a)<=x){
        v[a+lsb(a)]+=d;
        a+=lsb(a);
    }
}
void solvee(){   //dynamic range sum querry  with basic
lli x,q;cin>>x>>q;
vec(orig,x+1,0);
frs(i,1,x)cin>>orig[i];
vec(v,x+1,0);
v=orig;
bit(v);
 // query solving
 while(q--){
    lli type,a,b;cin>>type>>a>>b;
    if(type==2){  //retrival range sum v[a] to v[b];
       cout<<prefix_sum(b,v)-prefix_sum(a-1,v)<<'\n';
    }
    else{ //update to v[a]=b;
         //fark to sirf parent pe hi padega
         lli delta=b-orig[a];
         orig[a]=b;
         update(v,a,delta);
    }
 }
}