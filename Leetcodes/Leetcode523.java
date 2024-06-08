class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
       
        HashMap<Integer,Integer> rem = new HashMap<>();
        rem.put(0,-1);
         int sum=0;
        for(int i = 0;i < nums.length ; i++){
            sum+=nums[i];
            sum=sum%k;
            if(rem.containsKey(sum)){
                if(i-rem.get(sum)>=2)return true;
            }else{
                rem.put(sum , i);
            }
        }
       return false;
    }
}