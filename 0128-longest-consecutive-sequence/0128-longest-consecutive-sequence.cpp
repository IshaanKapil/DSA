class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
        return 0;
    }

    unordered_set<int> numbers;

    // Insert all elements into the set
    for (int number : nums) {
        numbers.insert(number);
    }

    int longest = 0;

    for (int number : numbers) {

        /*
            Start counting only when number is the
            first element of a sequence.
        */
        if (numbers.find(number - 1) == numbers.end()) {
            int currentNumber = number;
            int currentLength = 1;

            // Search for the next consecutive numbers
            while (
                numbers.find(currentNumber + 1)
                != numbers.end()
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