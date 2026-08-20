class Solution {
    public int[] resultArray(int[] nums) {
        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();
        arr1.add(nums[0]);
        arr2.add(nums[1]);
        int n = nums.length;

        for (int i = 2; i < n; i++) {
            int backA1 = arr1.getLast();
            int backA2 = arr2.getLast();
            if (backA1 > backA2) {
                arr1.add(nums[i]);
            } else {
                arr2.add(nums[i]);
            }
        }

        int[] ans = new int[n];

        int idx = 0;

        for (int x : arr1) {
            ans[idx] = x;
            idx++;
        }

        for (int x : arr2) {
            ans[idx] = x;
            idx++;
        }

        return ans;

    }
}