class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int[] pos = new int[31]; // stores last seen index for each bit

        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            for (int bit = 0; bit < 31; bit++) {
                if ((nums[i] & (1 << bit)) == 0) {
                    j = Math.max(j, pos[bit]); // extend j if bit was seen later
                } else {
                    pos[bit] = i; // update position for bit
                }
            }
            ans[i] = j - i + 1; // length of subarray
        }

        return ans;
    }
}