class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numbers(
            nums.begin(),
            nums.end()
        );

        int longest = 0;

        for (int number : numbers) {

            // Check whether number starts a sequence
            if (numbers.count(number - 1) == 0) {
                int currentNumber = number;
                int currentLength = 1;

                while (
                    numbers.count(currentNumber + 1) > 0
                ) {
                    currentNumber++;
                    currentLength++;
                }

                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};