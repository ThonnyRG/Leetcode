/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
class ProductOfNumbers {
public:
vector<int> res;
    ProductOfNumbers() {
        res.push_back(1);  
    }
    
    void add(int num) 
    {
        if(num!=0)
        {
            res.push_back(res.back()*num);
        }
        else
        {
            res.clear();
            res.push_back(1);
        }
    }
    
    int getProduct(int k) 
    {
        if(k>=res.size()) return 0;
        else
        return res.back() / res[res.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

