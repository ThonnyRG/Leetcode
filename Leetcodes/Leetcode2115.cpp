class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            map<string,int>indegree;
            map<string, vector<string>> adj;
            int n = ingredients.size();
            for(int i=0; i<n; i++){
                for(auto&s : ingredients[i]){
                    adj[s].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
            vector<string>ans;
            queue<string>q;
            for(auto&x : supplies) q.push(x);
            while(!q.empty()){
                string node =q.front();
                q.pop();
                for(auto&newnode : adj[node]){
                    indegree[newnode]--;
                    if(indegree[newnode]==0){
                        q.push(newnode);
                        ans.push_back(newnode);
                    }
                }
            }
            return ans; 
        }
    };