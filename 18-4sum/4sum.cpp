class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    // Fix the first element
    for (int i = 0; i < n; i++) {

        // Skip duplicate values of nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        // Fix the second element
        for (int j = i + 1; j < n; j++) {

            // Skip duplicate values of nums[j]
            if (j > i + 1 &&
                nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right) {

                long long sum =
                    1LL * nums[i] +
                    nums[j] +
                    nums[left] +
                    nums[right];

                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    answer.push_back({
                        nums[i],
                        nums[j],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (
                        left < right &&
                        nums[left] == nums[left  -1]
                    ) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (
                        left < right &&
                        nums[right] == nums[right + 1]
                    ) {
                        right--;
                    }
                }
            }
        }
    }

    return answer;
}
};