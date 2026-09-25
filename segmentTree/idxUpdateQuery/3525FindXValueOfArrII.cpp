class Solution {
public:
   
    struct Node {
        int prod;
        vector<int> count;

        Node(int k) {
            prod = 1;
            count.resize(k);
        }
    };

     vector<Node*> segTree;

   

    void buildSegTree(int i, int idx, int val, int l, int r, int k) {
        if (l == r) {
            fill(segTree[i]->count.begin(), segTree[i]->count.end(), 0);
            int p = val % k;
            segTree[i]->prod = p;
            segTree[i]->count[p]=1;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            buildSegTree(2 * i + 1, idx, val, l, mid, k);
        } else {
            buildSegTree(2 * i + 2, idx, val, mid + 1, r, k);
        }

        Node* left = segTree[2 * i + 1];
        Node* right = segTree[2 * i + 2];

        Node* root = segTree[i];

        fill(root->count.begin(),root->count.end(),0);

        root->prod = (left->prod * right->prod) % k;

        for (int r = 0; r < k; r++) {

            root->count[r] += left->count[r]; // from left subtree

            // from right subTree
            int newProd = (left->prod * r) % k;

            root->count[newProd] += right->count[r];
        }
    }

    Node* findAns(int i, int l, int r, int s, int e, int k) {
        if (l > e || r < s) {
            return NULL;
        } else if (l >= s && r <= e) {
            return segTree[i];
        }

        int mid = l + (r - l) / 2;

        Node* left = findAns(2 * i + 1, l, mid, s, e, k);
        Node* right = findAns(2 * i + 2, mid + 1, r, s, e, k);

        if (!left) {
            return right;
        } else if (!right) {
            return left;
        }

        Node* root = new Node(k);

        root->prod = (left->prod * right->prod) % k;

        for (int r = 0; r < k; r++) {

            root->count[r] += left->count[r]; // from left subtree

            // from right subTree
            int newProd = (left->prod * r) % k;

            root->count[newProd] += right->count[r];
        }

        return root;
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        int n = nums.size();
        segTree.resize(4 * n);

        for (int i = 0; i < 4 * n; i++) {
            segTree[i] = new Node(k);
        }

        for (int i = 0; i < n; i++) {
            buildSegTree(0, i, nums[i], 0, n - 1, k);
        }

        int q = queries.size();

        vector<int> ans(q);

        for (int i = 0; i < q; i++) {
            auto query = queries[i];
            buildSegTree(0, query[0], query[1], 0, n - 1, k);

            Node* RES = findAns(0, 0, n - 1, query[2], n - 1, k);
            ans[i] = RES->count[query[3]];
        }

        return ans;
    }
};