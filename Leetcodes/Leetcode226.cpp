class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int minimun = 0;
            int max = 1e7;

            while (minimun < max)
            {
                int medium = (minimun + max + 1) >> 1;

                long long count = 0;

                for (int candie: candies)
                {
                    count += candie / medium;
                }
                
                if(count >= k){
                    minimun = medium;
                } else {
                    max = medium -1;
                }

            }
            return minimun;
        }
    };