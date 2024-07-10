class Solution {
    public int minOperations(String[] logs) {
        int pivot = 0;
        for (int i = 0; i < logs.length; i++) {
            if(pivot > 0 && logs[i].contains("../")){
            pivot --;
            }else if (logs[i].contains("/") && !logs[i].contains("./")){
            pivot ++;
            }
        }
        return pivot;
    }
}