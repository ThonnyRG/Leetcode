class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
            int countNumber = 0;
            int maxCountNumber = 0;

            for (int i = 0; i < n; ++i) {
                if (blocks[i] == 'B')
                  ++countNumber;
                if (i >= k && blocks[i - k] == 'B')
                  --countNumber;
                maxCountNumber = max(maxCountNumber, countNumber);
              }
          
              return k - maxCountNumber;
            }
    };