class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        if (arr.empty())
            return {};
        vector<int> sortedArr = arr;

        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr)
        {

            if (rankMap.find(num) == rankMap.end())
            {
                rankMap[num] = rank++;
            }
        }

        vector<int> result;
        for (inf num: arr)
        {
            result.push_back(rankMap[num]);
        }
        return result;
    }
};