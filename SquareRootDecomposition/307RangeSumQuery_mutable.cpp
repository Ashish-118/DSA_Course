// Approach - (We can easliy solve this using Cumulative sum, segment tree but
// this is just to practice Square Root Decomposition T.C : O(Q * sqrt(n)) S.C :
// O(sqrt(n))
class NumArray
{
public:
    vector<int> nums;
    vector<int> blocks;
    int n;
    int blockSize;

    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        n = nums.size();

        blockSize = ceil(sqrt(n));
        blocks.resize(blockSize, 0);

        // build the blocks array
        for (int i = 0; i < n; i++)
        {
            int blockIndex = i / blockSize;
            blocks[blockIndex] += nums[i];
        }
    }

    void update(int index, int val)
    {
        int blockIndex = index / blockSize;

        blocks[blockIndex] -= nums[index];
        blocks[blockIndex] += val;
        nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        int sum = 0;

        int startBlock = left / blockSize;
        int endBlock = right / blockSize;

        // case - 1
        if (startBlock == endBlock)
        {
            for (int i = left; i <= right; i++)
            {
                sum += nums[i];
            }
            return sum;
        }

        // Case - 2 (left and right are in different blocks)
        // left partial sum -> left to end of startBlock
        int endIndexOfStartBlock = ((startBlock + 1) * blockSize) - 1;
        for (int i = left; i <= endIndexOfStartBlock; i++)
        {
            sum += nums[i];
        }

        // Middle full blocks
        for (int b = startBlock + 1; b <= endBlock - 1; b++)
        {
            sum += blocks[b];
        }

        // Right partial
        int startIndexOfEndBlock = endBlock * blockSize;
        for (int i = startIndexOfEndBlock; i <= right; i++)
        {
            sum += nums[i];
        }

        return sum;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */