class Solution {
    public int minSteps(int n) {
      int answer = 0;
        if (n == 0) {
            answer = 0;
        }else{
            for (int i = 2; n > 1; ++i) {
                while (n % i == 0) {
                    answer += i;
                    n /= i;
                }
            }
        }
        return answer;
    } 
}