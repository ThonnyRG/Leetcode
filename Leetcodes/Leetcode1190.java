class Solution {
    public String reverseParentheses(String s) {
        Deque<String> stack = new ArrayDeque<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stack.push("(");
            } else if (c == ')') {
                StringBuilder rev = new StringBuilder();
                while (!stack.isEmpty() && !stack.peek().equals("(")) {
                    rev.append(new StringBuilder(stack.pop()).reverse());
                }
                stack.pop(); // Remove the '('
                stack.push(rev.toString());
            } else {
                stack.push(String.valueOf(c));
            }
        }
        
        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.insert(0, stack.pop());
        }
        
        return result.toString();
    }
}