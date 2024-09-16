class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;

        // Convert each time in "HH:MM" format to total minutes and add to the list
        vector<int> minutes;
        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }

        // Sort the list of minutes
        sort(minutes.begin(), minutes.end());

        // Calculate the minimum difference between adjacent time points
        for (int i = 1; i < minutes.size(); i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }

        // Consider the wrap-around case between the last and the first time points
        ans = min(ans, 1440 + minutes[0] - minutes.back());

        return ans;
    }

private:
    // Helper function to convert time "HH:MM" to total minutes
    int timeToMinutes(const string& time) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 5));
        return hour * 60 + minute;
    }
};