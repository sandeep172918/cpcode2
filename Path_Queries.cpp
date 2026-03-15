//Author:coding_with_alzheimer
//Date: 2026-03-14 23:25

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
 
/*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠤⠤⠤⠴⠶⠶⠒⠚⠋⠉⠉⠉⠉⣷⢀⣀⡤⠤⠶⠶⠒⠛⢶⡄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡀⠀⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣇⣾⠀⠀⠀⠀⣴⡄⢠⣿⣄⡀⣰⠏⠙⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⠶⠚⠉⠉⠙⢦⣄⣀⣀⡟⠙⠋⠁⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⢰⠋⢈⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀⠀⠀⠀⠀⠀⠀⠀⠠⣆⠀⠀⢿⠀⢸⡶⢿⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣤⣀⡼⠀⠀⠻⠀⠀⠙⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡖⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠳⣦⡀⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠇⣿⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⡟⢳⣄⠀⠀⠀⠀⠙⣇⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⡿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⢿⡀⠀⠀⠀⢀⡞⠁⠉⠓⠀⠀⠀⠀⣯⠴⠻⣆⠀⠀⠀⠀⢻⡆⠀⠀⠀⠻⠃⠀⠀⠀⠀⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⢸⡇⠀⠀⠀⠘⣧⠀⠖⠚⣷⠀⠀⠀⣧⠀⠀⠘⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⠀⠀⠘⡇⠀⠀⠀⠀⠘⠷⣤⣠⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⢀⡠⠞⠁⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠾⣦⠀⢸⡇⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣀⣠⡤⠔⠚⠉⠀⠀⠀⠀
⠀⠀⣴⢦⣄⠀⠀⢀⣰⠏⠀⠘⣧⣿⠀⠀⠀⠀⢠⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡤⠴⠶⠒⠋⢹⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡏⠀⠈⠛⠋⠉⢀⣴⣿⣟⢿⡏⠀⠀⢀⡴⠋⠀⣧⠀⠀⢀⣀⣠⣤⣤⠤⠴⠒⠚⠛⠉⠉⠀⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣧⢀⣴⣶⣶⡄⢾⣿⣿⡿⣸⠃⠀⢠⠞⠁⠀⠀⠈⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢿⣿⣿⣿⣿⣿⠘⢿⣭⡵⠋⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⠳⣬⣿⣭⠯⠖⠚⠁⠀⢀⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢠⠇⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣰⠏⠀⣀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡼⢃⡴⠚⡿⠀⠀⠀⣤⠀⠈⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⣾⠗⠋⠀⢠⡏⠀⠀⣸⠋⢷⡀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠋⠁⣄⠀⢠⡿⡇⠀⢰⡏⠀⠀⠻⣮⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠙⠛⠋⠀⡇⢠⡟⠀⠀⠀⠀⠈⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣧⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/

//BSDK math snippet hai

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
    lli query_bs(lli id,lli l,lli r,lli lq,lli x){ //first element greater than x in range lq till end
      push(id,l,r); 
      if(r<lq)return -1;
      if(t[id].sum<x)return -1;
      if(l==r)return l;
      lli mid=(l+r)/2;
      lli left=query_bs(2*id,l,mid,lq,x);
      if(left!=-1)return left;
      return query_bs(2*id+1,mid+1,r,lq,x);
    }
};

class HLD{
    lli n;
    vector<vector<lli>>g;
    vector<lli>parent,depth,heavy,head,pos,sz;
    vector<lli>val;
    lli timer;
    Segment_Tree seg;

public:

    HLD(lli n){
        this->n=n;
        g.resize(n+1);
        parent.resize(n+1);
        depth.resize(n+1);
        heavy.resize(n+1,-1);
        head.resize(n+1);
        pos.resize(n+1);
        sz.resize(n+1);
        val.resize(n+1);

        timer=0;
    }

    void add_edge(lli u,lli v){
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void set_val(lli i,lli x){
        val[i]=x;
    }

    lli dfs(lli v,lli p){
        parent[v]=p;
        sz[v]=1;
        lli mx=0;
        for(auto to:g[v]){
            if(to==p) continue;
            depth[to]=depth[v]+1;
            lli s=dfs(to,v);
            sz[v]+=s;
            if(s>mx){
                mx=s;
                heavy[v]=to;
            }
        }
        return sz[v];
    }

    void decompose(lli v,lli h){
        head[v]=h;
        pos[v]=timer++;
        if(heavy[v]!=-1)
            decompose(heavy[v],h);

        for(auto to:g[v]){
            if(to!=parent[v] && to!=heavy[v])
                decompose(to,to);
        }
    }

    void build(){
        dfs(1,0);
        decompose(1,1);
        vector<lli> base(n);
        for(int i=1;i<=n;i++)
            base[pos[i]]=val[i];
        seg.init(base);   // build segtree
    }

    lli query(lli a,lli b){
        lli ans=0;
        while(head[a]!=head[b]){
            if(depth[head[a]] < depth[head[b]])
                swap(a,b);

            ans += seg.quer(pos[head[a]],pos[a]); //yaha kalakari dikhana hai
            a = parent[head[a]];
        }

        if(depth[a]>depth[b])
            swap(a,b);

        ans += seg.quer(pos[a],pos[b]);  //yaha bhi

        return ans;
    }

    void update(lli a,lli b,lli val){ //add val to every node on the path from a to b.
        while(head[a]!=head[b]){
            if(depth[head[a]] < depth[head[b]])
                swap(a,b);

            seg.update(1,0,n-1,pos[head[a]],pos[a],val);
            a=parent[head[a]];
        }
        if(depth[a]>depth[b])
            swap(a,b);

        seg.update(1,0,n-1,pos[a],pos[b],val);
    }
    void point_set(lli id, lli x){
    lli cur = seg.quer(pos[id],pos[id]);
    seg.update(1,0,n-1,pos[id],pos[id],x-cur);
    }
};
void solve(){
lli n,k;cin>>n>>k;
HLD hld(n);
fr(i,n){
    lli x;cin>>x;
    hld.set_val(i+1,x);
}
fr(i,n-1){
    lli u,v;cin>>u>>v;
    hld.add_edge(u,v);
}
hld.build();
fr(i,k){
    lli t;cin>>t;
    if(t==1){
        lli id,v;
        cin>>id>>v;
        hld.point_set(id,v);
    }else{
        lli u;cin>>u;
        cout<<hld.query(1,u)<<'\n';
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