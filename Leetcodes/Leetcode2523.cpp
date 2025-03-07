class Solution {
    public:
        bool isPrime(int n){
            if(n < 2)
                return false;
            int nSqrt = sqrt(n);
            for(int i = 2;i < nSqrt + 1; i++){
                if(n%i == 0)
                    return false;
            }
            return true;
        }
        vector<int> closestPrimes(int left, int right) {
            vector<int> res;
            int prev = -1;
            for(int i = left; i <= right; i++){
                if(isPrime(i)){
                    if(res.size()<2)
                        res.push_back(i);
                    else if(i - prev < res[1] - res[0])
                        res = {prev, i};
                    prev = i;
                }
            }
            if(res.size() < 2)
                return {-1, -1};
            return res;
        }
    };