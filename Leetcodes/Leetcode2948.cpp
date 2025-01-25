class Solution {
public:
    vector<int> groups[100005];
    pair<int, int> elementIndexPairs[100005];
    int groupMapping[100005];
    vector<int> lexicographicallySmallestArray(vector<int>& nums,int maxDifference) {
        int arraySize = nums.size(), groupCount = 0;

        for (int i = 0; i < arraySize; i++) {
            elementIndexPairs[i + 1] = make_pair(nums[i], i);
        }
        sort(elementIndexPairs + 1, elementIndexPairs + 1 + arraySize);

        for (int i = 1; i <= arraySize; i++) {
            int endIndex = i + 1;

            while (endIndex <= arraySize &&
                   elementIndexPairs[endIndex].first -
                           elementIndexPairs[endIndex - 1].first <=
                       maxDifference) {
                ++endIndex;
            }
            --endIndex;

            ++groupCount;
            groups[groupCount].clear();

            for (int j = endIndex; j >= i; j--) {
                groupMapping[elementIndexPairs[j].second] = groupCount;
                groups[groupCount].push_back(elementIndexPairs[j].first);
            }

            i = endIndex;
        }

        vector<int> result;
        for (int i = 0; i < arraySize; i++) {
            int currentGroup = groupMapping[i];
            result.push_back(groups[currentGroup].back());
            groups[currentGroup].pop_back();
        }

        return result;
    }
};