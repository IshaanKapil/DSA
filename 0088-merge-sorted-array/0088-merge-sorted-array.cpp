class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 1. Copy nums2 into the end of nums1
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }

        int totalLen = m + n;
        // 2. Initialize gap
        int gap = (totalLen + 1) / 2;

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < totalLen) {
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
                left++;
                right++;
            }

            if (gap == 1) {
                gap = 0;
            } else {
                gap = (gap + 1) / 2; // Ceil division
            }
        }
    }
};