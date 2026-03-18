#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//O(n)

class Solution{
public:
    vector<int> topkFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for(auto& [num, freq] : mp){
            buckets[freq].push_back(num);
        }

        vector<int> result;

        for(int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }

        return result;
    }
};

int main(){
    Solution s;

    int n, k;


    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }


    cout << "Enter k: ";
    cin >> k;

    vector<int> result = s.topkFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}