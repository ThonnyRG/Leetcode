class Solution {
    public int numRescueBoats(int[] arr, int n) {
        int res = 0,bl;
        Arrays.sort(arr);
        int l=0,r=arr.length-1;
        while(l<=r){
            if(arr[l]+arr[r]<=n){
                l++;
                r--;
                res++;
            }
            else{
                r--;
                res++;
            }
        }
        return res;
    }
}