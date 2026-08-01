class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();

    int candidate1 = 0;
    int candidate2 = 1;

    int count1 = 0;
    int count2 = 0;

    // Step 1: Find the two possible candidates
    for (int number : arr) {
        if (number == candidate1) {
            count1++;
        }
        else if (number == candidate2) {
            count2++;
        }
        else if (count1 == 0) {
            candidate1 = number;
            count1 = 1;
        }
        else if (count2 == 0) {
            candidate2 = number;
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify the candidates
    count1 = 0;
    count2 = 0;

    for (int number : arr) {
        if (number == candidate1) {
            count1++;
        }
        else if (number == candidate2) {
            count2++;
        }
    }

    vector<int> answer;

    if (count1 > n / 3) {
        answer.push_back(candidate1);
    }

    if (count2 > n / 3) {
        answer.push_back(candidate2);
    }

    return answer;
    }
};