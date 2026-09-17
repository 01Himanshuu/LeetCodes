class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), ans = INT_MAX, sum = 0, best = INT_MAX;
        vector<int> dp(n, INT_MAX);

        for (int l = 0, r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > target)
                sum -= arr[l++];

            if (sum == target) {
                int len = r - l + 1;
                if (l > 0 && dp[l - 1] != INT_MAX)
                    ans = min(ans, len + dp[l - 1]);
                best = min(best, len);
            }

            dp[r] = best;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};