#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    struct Node {
        long long mn;     // minimum value in range
        long long lazyA;  // AP starting term
        long long lazyD;  // AP common diff
        bool lazy;
        Node() : mn(0), lazyA(0), lazyD(0), lazy(false) {}
    };

    int n;
    vector<Node> st;

    SegTree(int n) : n(n), st(4*n) {}

    // Build with initial array
    void build(int node, int l, int r, vector<long long> &arr) {
        if(l == r) {
            st[node].mn = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, arr);
        build(node*2+1, mid+1, r, arr);
        st[node].mn = min(st[node*2].mn, st[node*2+1].mn);
    }

    // Apply AP update to this node for segment [l, r]
    void apply(int node, int l, int r, long long a, long long d) {
        long long len = r - l + 1;

        long long last = a + (len - 1) * d;
        long long mn_add = min(a, last); // since AP can be increasing or decreasing
        st[node].mn += mn_add;

        // accumulate lazy
        st[node].lazyA += a;
        st[node].lazyD += d;
        st[node].lazy = true;
    }

    // Push lazy to children
    void push(int node, int l, int r) {
        if(!st[node].lazy) return;

        int mid = (l+r)/2;

        long long a = st[node].lazyA;
        long long d = st[node].lazyD;

        // left child receives AP starting at a
        apply(node*2, l, mid, a, d);

        // right child receives AP starting at a + (mid+1 - l)*d
        long long shift = (mid + 1 - l);
        apply(node*2+1, mid+1, r, a + shift * d, d);

        st[node].lazyA = st[node].lazyD = 0;
        st[node].lazy = false;
    }

    // Range update: add an AP to [L, R]
    void update(int node, int l, int r, int L, int R, long long a, long long d) {
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            long long offset = l - L; // how much AP shifted for this segment
            apply(node, l, r, a + offset*d, d);
            return;
        }

        push(node, l, r);
        int mid = (l+r)/2;

        update(node*2, l, mid, L, R, a, d);
        update(node*2+1, mid+1, r, L, R, a, d);
        st[node].mn = min(st[node*2].mn, st[node*2+1].mn);
    }

    // Range min query
    long long query(int node, int l, int r, int L, int R) {
        if(r < L || R < l) return LLONG_MAX;
        if(L <= l && r <= R) return st[node].mn;

        push(node, l, r);

        int mid = (l+r)/2;
        return min(query(node*2, l, mid, L, R),
                   query(node*2+1, mid+1, r, L, R));
    }
};

void solve(){
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
       
    }
}


int32_t main(){

int test=1;
while(test--){
solve();
}
}