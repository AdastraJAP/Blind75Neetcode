#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        unordered_map<int, int> mp;
        int difference = 0;
        for (int i = 0; i < nums.size(); i++) {
            difference = target - nums[i];
            if (mp.count(difference)) {
                return {mp[difference], i}; 
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};  
    }
};

int main() {
    Solution s;
    int target, n;
    cin >> target >> n;

    vector<int> nums(n);  
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = s.twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;  

    return 0;
}