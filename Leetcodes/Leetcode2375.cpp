class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size();
            string ans;
            stack<char> st;

            for (int i = 0; i <= n; i++)
            {
                st.push('1'+i);
                if (i == n || pattern[i] == 'I')
                {
                    while(!st.empty()){
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
                
            }
            
            return ans;

        }
    };