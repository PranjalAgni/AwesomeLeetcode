#include <bits/stdc++.h>
using namespace std;

void showTree(int tree[], int N) {
    cout << endl;
    for (int i = 1; i < 2 * N; i++) {
        cout << tree[i] << "  ";
    }
    cout << endl;
}
void build(int tree[], int arr[], int N) {
    //insert leafs
    for (int i = 0; i < N; i++) {
        tree[N + i] = arr[i];
    }

    //build the tree
    for (int i = N - 1; i > 0; i--) {
        tree[i] = max(tree[i << 1], tree[(i << 1) | 1]);
    }
}

int range(int l, int r, int tree[], int N) {
    int res = -10;
    int compr = 1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        // cout << "RANGE: " << l << "  " << r << endl;
        cout << "Comparison: " << compr << " b/w nodes " << l << " " << r << endl;
        if (l & 1) {
            res = max(res, tree[l++]);
        }
        if (r & 1) {
            res = max(res, tree[--r]);
        }
        compr += 1;
    }
    return res;
}
int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int tree[2 * N];

    build(tree, arr, N);
    showTree(tree, N);
    int res = range(3, 9, tree, N);
    cout << res << endl;
    return 0;
}