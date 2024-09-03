class Solution {
private:
    int sum(int num){
        int ans=0;
        while(num){
            ans+=num%10;
            num/=10;
        }
        return ans;
    }

public:
    int getLucky(string s, int k) {
        int n=s.length();
        vector<int> number;
        for(int i=0; i<n; i++){
             int x=(int)s[i];
             int rem=x-96;
             if(rem>9){
                    
                    number.push_back(rem/10);
                    number.push_back(rem%10);
                
             }else{
                number.push_back(rem);
             }
             
        }
        int sum_=0;
        for(int i=0; i<number.size(); i++){
                sum_+=number[i];
            }
        if(k==1){
            
            return sum_;
        }else{
            int w=2;
            while(w<=k){
                sum_=sum(sum_);
                w++;
            }
        }
        
        return sum_;
    }
};