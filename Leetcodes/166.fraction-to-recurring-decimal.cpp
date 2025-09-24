/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string res;

        if ((numerator < 0) ^ (denominator < 0))
            res += '-';

        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));

        res += to_string(num / den);

        num %= den;

        if (num == 0)
            return res;

        res += '.';

        unordered_map<long long, int> mp;

        while (num != 0)
        {
            mp[num] = res.size();
            num *= 10;
            res += to_string(num / den);
            num %= den;
            if (mp.count(num))
            {
                res.insert(mp[num], "(");
                res += ')';
                break;
            }
        }
        return res;
    }
};
// @lc code=end
