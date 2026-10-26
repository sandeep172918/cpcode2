
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// ================= SHANNON-FANO =================

void shannonFano(vector<pair<string, ll>>& a, int l, int r,
                 string code, map<string, string>& ans) {
    if (l == r) {
        ans[a[l].first] = code.empty() ? "0" : code;
        return;
    }

    ll total = 0;
    for (int i = l; i <= r; i++)
        total += a[i].second;

    ll sum = 0, bestDiff = LLONG_MAX;
    int split = l;

    for (int i = l; i < r; i++) {
        sum += a[i].second;
        ll diff = abs(total - 2 * sum);

        if (diff < bestDiff) {
            bestDiff = diff;
            split = i;
        }
    }

    shannonFano(a, l, split, code + "0", ans);
    shannonFano(a, split + 1, r, code + "1", ans);
}

map<string, string> getShannonFano(
    vector<pair<string, ll>> a) {

    sort(a.begin(), a.end(),
         [](auto& x, auto& y) {
             return x.second > y.second;
         });

    map<string, string> ans;

    if (!a.empty())
        shannonFano(a, 0, (int)a.size() - 1, "", ans);

    return ans;
}

// ================= HUFFMAN =================

struct Node {
    string symbol;
    ll freq;
    Node *left, *right;

    Node(string s, ll f) {
        symbol = s;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void getCodes(Node* root, string code,
              map<string, string>& ans) {
    if (!root) return;

    if (!root->left && !root->right) {
        ans[root->symbol] = code.empty() ? "0" : code;
        return;
    }

    getCodes(root->left, code + "0", ans);
    getCodes(root->right, code + "1", ans);
}

map<string, string> getHuffman(
    vector<pair<string, ll>> a) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto& [symbol, freq] : a)
        pq.push(new Node(symbol, freq));

    while (pq.size() > 1) {
        Node* x = pq.top();
        pq.pop();

        Node* y = pq.top();
        pq.pop();

        Node* parent = new Node("", x->freq + y->freq);
        parent->left = x;
        parent->right = y;

        pq.push(parent);
    }

    map<string, string> ans;

    if (!pq.empty())
        getCodes(pq.top(), "", ans);

    return ans;
}

// ================= MAIN =================

int main() {
    int n;
    cin >> n;

    vector<pair<string, ll>> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    auto sf = getShannonFano(a);
    auto hf = getHuffman(a);

    cout << "\nShannon-Fano Codes:\n";
    for (auto& [symbol, freq] : a)
        cout << symbol << " : " << sf[symbol] << '\n';

    cout << "\nHuffman Codes:\n";
    for (auto& [symbol, freq] : a)
        cout << symbol << " : " << hf[symbol] << '\n';

    return 0;
}
