class NumArray {
public:
    int* seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg = new int[4 * n];
        buildTree(0, nums, 0, n - 1);
    }

    void buildTree(int i, vector<int>& nums, int l, int r) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;

        buildTree(2 * i + 1, nums, l, mid);
        buildTree(2 * i + 2, nums, mid + 1, r);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void updateTree(int i, int l, int r, int index, int val) {
        if (l == r) {
            seg[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            updateTree(2 * i + 1, l, mid, index, val);
        } else {
            updateTree(2 * i + 2, mid + 1, r, index, val);
        }

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    int getSum(int i, int l, int r, int left, int right) {
        if (l > right || r < left) {
            return 0;
        } else if (left <= l && l <= right && left <= r && r <= right) {
            return seg[i];
        }

        int mid = l + (r - l) / 2;

        return getSum(2 * i + 1, l, mid, left, right) +
               getSum(2 * i + 2, mid + 1, r, left, right);
    }

    void update(int index, int val) { updateTree(0, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return getSum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */