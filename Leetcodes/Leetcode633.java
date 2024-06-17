class Solution {
    public boolean judgeSquareSum(int c) {
        long a = 0, b = (long)Math.sqrt(c);
        while (a <= b){
            long sq = (a * a) + (b * b);
            if (sq == c)
                return true;
            else if (sq < c)
                a++;
            else
                b--;
        }
        return false;
    }
}