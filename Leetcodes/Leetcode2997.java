class Solution {
    public int minOperations(int[] nums, int k) {
        int b = nums[0];
        for(int i=1; i<nums.length; i++) {
            b = nums[i] ^ b;
        }
        int res =0;
        while(b!=0 || k!=0) {
            int bit1 = b & 1;
            int bit2 = k & 1;
            if(bit1!=bit2) {
                res++;
            }
            b = b>>1;
            k = k>>1;
        }
        return res;
    }
}