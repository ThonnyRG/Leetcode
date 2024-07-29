class Solution {
    public int numTeams(int[] rating) {
     int res = 0, n = rating.length;
    for (int i = 1; i < n - 1; i++) {
        int L_inc = 0,
        L_dec = 0,
        R_inc = 0,
        R_dec = 0;
        for (int j = 0; j < i; j++) {
            if (rating[j] < rating[i]) {
                L_inc ++;
            }else{
                L_dec ++;
            }
        }
        for (int k = i + 1; k < n; k++) {
            if (rating[i] < rating[k]) {
                R_inc ++;
            }else{
                R_dec ++;
            }  
        }
        res += (L_inc * R_inc) + (L_dec * R_dec)
    }
    return res;
    }

}