class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> answer;

    int n = nums.size();

    // Sorting is necessary for two pointers
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {

        // Skip duplicate fixed elements
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            long long sum =
                1LL * nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                // We need a larger sum
                j++;
            }
            else if (sum > 0) {
                // We need a smaller sum
                k--;
            }
            else {
                // Valid triplet found
                answer.push_back({
                    nums[i],
                    nums[j],
                    nums[k]
                });

                j++;
                k--;

                // Skip duplicate values at j
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }

                // Skip duplicate values at k
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }
    }

    return answer;
}
};
    