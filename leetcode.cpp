//Author:coding_with_alzheimer
//Date: 2026-06-21 15:51

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


class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& f, string s, int k) {
        vector<vpr> adj(n);
        lli src=0;
        lli dst=n-1;
        fr(i,f.size()){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        map<pr,lli>vis,dis;
        priority_queue<pair<lli,pr>,vector<pair<lli,pr>,greater<pair<lli,pr>> > >pq; 
        pq.push({0,{src,1}});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            lli d=it.ff;
            lli node=it.ss.ff;
            lli kk=it.ss.ss;
            if(node==dst)return d;
            if(vis[{node,kk}])continue;
            vis[{node,kk}]=1;
            for(auto &it:adj[node]){
                lli v=it.ff;
                lli w=it.ss;
                lli nkk=s[node]==s[v]?kk+1:1;
                if(nkk>k)continue;
                pr p={v,nkk};
                if(dis.find(p)==dis.end() || d+w<dis[p]){
                    dis[p]=d+w;
                    pq.push({dis[p],p});
                }
            }

        }
        return -1;
        

    }
};

