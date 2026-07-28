class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
         unordered_map<long long, int> prefixFrequency;

    /*
        Before the array starts, the prefix sum is 0.
        It has appeared once.
    */
    prefixFrequency[0] = 1;

    long long prefixSum = 0;
    int totalCount = 0;

    for (int number : arr) {
        // Prefix sum up to the current position
        prefixSum += number;

        // Prefix sum required to form a subarray of sum k
        long long requiredPrefix = prefixSum - k;

        /*
            Every previous occurrence of requiredPrefix
            produces one valid subarray ending here.
        */
        if (prefixFrequency.find(requiredPrefix)
            != prefixFrequency.end()) {

            totalCount += prefixFrequency[requiredPrefix];
        }

        // Record the current prefix sum
        prefixFrequency[prefixSum]++;
    }

    return totalCount;
}
        
    
};