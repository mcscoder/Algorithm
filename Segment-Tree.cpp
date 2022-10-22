// Sum queries range with update node

#include <iostream>

#define int long long

using namespace std;

// to build tree
void buildTree(int *tree, int *a, int index, int s, int e) {
    // base case
    if (s > e) return;
    // reached leaf node
    if (s == e) {
        tree[index] = a[s];
        return;
    }
    // build the tree in bottom up manner
    int m = (s + e) / 2;
    buildTree(tree, a, index * 2    , s    , m);
    buildTree(tree, a, index * 2 + 1, m + 1, e);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
    return;
}

// to query 
int query(int *tree, int index, int s, int e, int qs, int qe) {
    // base case: when query range is outside the node range
    if (e < qs || qe < s) return 0;
    // when query range is inside the node range
    if (qs <= s && e <= qe) return tree[index];
    
    int m = (s + e) / 2;
    int leftSum =  query(tree, index * 2    , s    , m, qs, qe);
    int rightSum = query(tree, index * 2 + 1, m + 1, e, qs, qe);
    return (leftSum + rightSum);
}

// to update node
void update(int *tree, int index, int s, int e, int pos, int val) {
    if (pos < s || e < pos) return;
    if (s == e) {
        tree[index] = val;
        return;
    }
    int m = (s + e) / 2;    
    update(tree, index * 2    , s    , m, pos, val);
    update(tree, index * 2 + 1, m + 1, e, pos, val);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    int a[n]; for(int &i : a) cin >> i;

    int *tree = new int[n * 4 + 1];
    int index = 1, s = 0, e = n - 1;
    buildTree(tree, a, index, s, e);

    while (q--) {
        int type; cin >> type;
        if (type == 2) {
            int qs, qe; cin >> qs >> qe;
            cout << query(tree, index, s, e, qs - 1, qe - 1) << endl;
        } else {
            int pos, val; cin >> pos >> val;
            update(tree, index, s, e, pos - 1, val);
        }
    }
    return 0;
}
