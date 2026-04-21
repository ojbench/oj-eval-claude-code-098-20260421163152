#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
    explicit Node(int v) : val(v) {}
};

void insertNode(unique_ptr<Node>& root, int v) {
    if (!root) {
        root = make_unique<Node>(v);
        return;
    }
    if (v < root->val) insertNode(root->left, v);
    else insertNode(root->right, v);
}

bool kthLargest(const unique_ptr<Node>& root, int& k, int& ans) {
    if (!root) return false;
    if (kthLargest(root->right, k, ans)) return true;
    if (--k == 0) {
        ans = root->val;
        return true;
    }
    return kthLargest(root->left, k, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> nums;
    nums.reserve(8);
    long long x;
    while (nums.size() < 8 && (cin >> x)) nums.push_back(x);
    if (nums.size() != 8) return 0;

    unique_ptr<Node> root;
    for (int i = 0; i < 7; i++) insertNode(root, static_cast<int>(nums[i]));
    int k = static_cast<int>(nums[7]);
    int ans = 0;
    kthLargest(root, k, ans);
    cout << ans << '\n';
    return 0;
}
