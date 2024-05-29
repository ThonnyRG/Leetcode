class Solution {
    public int numSteps(String s) {
        int x = 0;
        int y = 0;

        for(int i = s.length()-1; i >= 1; i--){
            int num = s.charAt(i) -'0';
            if(num == 0 && y == 0){
                x++;
            }else if(num == 1 && y == 1){
                x++;
                y = 1;
            }else{
                x += 2;
                y = 1;
            }
        }
        if(y == 1)x++;
        return x;
    }
}