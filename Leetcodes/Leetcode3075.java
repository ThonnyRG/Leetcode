class Solution {
    public long maximumHappinessSum(int[] hap, int k) {
        Arrays.sort(hap);
        long ans=hap[hap.length-1];
        k--;
        int count=1;
        for(int i=hap.length-2;i>=0;i--){
            if(k>0){
                if(hap[i]-count<=0){
                    ans+=0;
                    break;
                }
                else
                ans+=hap[i]-count;
                count++;
                k--;
            }
        }
        return ans;
    }
}