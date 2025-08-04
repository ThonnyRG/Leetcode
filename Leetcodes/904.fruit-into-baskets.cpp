/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */


 
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int last_num=-1,last_num_starting_index=-1;
        int ans=0,num1=-1,num2=-1;
        while(j<fruits.size()){

            if(num1==-1)num1=fruits[i];
            else if(num2==-1 and fruits[j]!=num1)num2=fruits[j];
            else if(fruits[j]!=num1 and fruits[j]!=num2){
                i=last_num_starting_index;
                num1=(last_num==num1)?num1:num2;
                num2=fruits[j];
                last_num=fruits[j];
                last_num_starting_index=j;
            }

            if(last_num!=fruits[j]){
                last_num=fruits[j];
                last_num_starting_index=j;
            }

            ans=max(ans,j-i+1);

            j++;
        }

        return ans;
    }
};
// @lc code=end

