import java.util.PriorityQueue;

class KthLargest {
    private final PriorityQueue<Integer> topElements;
    private final int limit;

    public KthLargest(int k, int[] nums) {
        this.limit = k;
        this.topElements = new PriorityQueue<>(k);
        
        for (int num : nums) {
            addElement(num);
        }
    }
    
    public int add(int val) {
        return addElement(val);
    }

    private int addElement(int newVal) {
        if (topElements.size() < limit) {
            topElements.offer(newVal);
        } else if (newVal > topElements.peek()) {
            topElements.poll();
            topElements.offer(newVal);
        }
        
        return topElements.peek() != null ? topElements.peek() : 0;
    }
}
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */