class Solution {
public:
    struct Node {
        int prod;
        vector<long long> cnt;

        Node() {}

        Node(int k) {
            prod = 1;
            cnt.assign(k, 0);
        }
    };

    int k;
    vector<Node> seg;

    Node merge(Node &a, Node &b) {
        Node res(k);

        res.prod = (1LL * a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int rem = (1LL * a.prod * r) % k;
            res.cnt[rem] += b.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            seg[node] = Node(k);
            int rem = nums[l] % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = Node(k);
            int rem = val % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();

        seg.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> result;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node ans = query(1, 0, n - 1, start, n - 1);

            result.push_back(ans.cnt[x]);
        }

        return result;
    }
};