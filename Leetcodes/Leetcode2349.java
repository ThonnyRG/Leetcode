class NumberContainers {
    public:
        unordered_map<int,int> mp;
        unordered_map<int,set<int>> m;
    
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if(this->mp[index] != number) {
                int prev_num = this->mp[index];
                auto it = this->m[prev_num].find(index);  
                this->m[prev_num].erase(*it); 
                this->mp[index] = number;
            }
    
            this->m[number].insert(index);
        }
        
        int find(int number) {
            if(this->m[number].size()==0) return -1;
            return *this->m[number].begin();
        }
    };
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */