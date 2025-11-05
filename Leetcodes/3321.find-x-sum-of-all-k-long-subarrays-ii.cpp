/*
 * @lc app=leetcode id=3321 lang=cpp
 *
 * [3321] Find X-Sum of All K-Long Subarrays II
 */

// @lc code=start
class Solution {
public:
    int n;
    set<pair<long long, long long>> tx, ntx;
    map<long long, long long> mp;
    long long sum = 0;

    void balance() {
        while (!tx.empty() && !ntx.empty()) {
            auto txe = *tx.begin();
            auto ntxe = *prev(ntx.end());

            if ((ntxe.first > txe.first) ||
                (ntxe.first == txe.first && ntxe.second > txe.second)) {
                sum -= txe.first * txe.second;
                sum += ntxe.first * ntxe.second;
                tx.erase(txe);
                ntx.erase(ntxe);
                tx.insert(ntxe);
                ntx.insert(txe);
            } else break;
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ans;
        n = nums.size();
        mp.clear(); tx.clear(); ntx.clear(); sum = 0;

        for (int i = 0; i < k; i++) mp[nums[i]]++;

        for (auto it : mp) {
            tx.insert({it.second, it.first});
            if (tx.size() > x) {
                ntx.insert(*tx.begin());
                tx.erase(tx.begin());
            }
        }

        for (auto it : tx)
            sum += it.first * it.second;

        ans.push_back(sum);

        int i = 0, j = k;

        while (j < n) {
            if (ntx.find({mp[nums[i]], nums[i]}) != ntx.end()) {
                ntx.erase({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if (mp[nums[i]] > 0)
                    ntx.insert({mp[nums[i]], nums[i]});
            } else {
                sum -= mp[nums[i]] * nums[i];
                tx.erase({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if (mp[nums[i]] > 0) {
                    tx.insert({mp[nums[i]], nums[i]});
                    sum += mp[nums[i]] * nums[i];
                }
                balance();
            }

            while ((int)tx.size() < x && !ntx.empty()) {
                auto best = *prev(ntx.end());
                ntx.erase(prev(ntx.end()));
                tx.insert(best);
                sum += best.first * best.second;
            }


            if (tx.size() < x) {
                if (tx.find({mp[nums[j]], nums[j]}) != tx.end()) {
                    tx.erase({mp[nums[j]], nums[j]});
                    mp[nums[j]]++;
                    tx.insert({mp[nums[j]], nums[j]});
                    sum += nums[j];
                } else {
                    mp[nums[j]]++;
                    tx.insert({mp[nums[j]], nums[j]});
                    sum += mp[nums[j]] * nums[j];
                }
            } else {
                if (tx.find({mp[nums[j]], nums[j]}) != tx.end()) {
                    tx.erase({mp[nums[j]], nums[j]});
                    mp[nums[j]]++;
                    tx.insert({mp[nums[j]], nums[j]});
                    sum += nums[j];
                } else {
                    ntx.erase({mp[nums[j]], nums[j]});
                    mp[nums[j]]++;
                    ntx.insert({mp[nums[j]], nums[j]});
                    balance();
                }
            }

            ans.push_back(sum);
            i++;
            j++;
        }

        return ans;
    }
};
// @lc code=end

