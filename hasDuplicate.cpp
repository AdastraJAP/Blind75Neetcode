#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;




    /*
    //brute force method ,O(n^2)
  for(int i=0;i<nums.size();i++){
    for(int j=i+1;j<nums.size();j++){
        if(nums[i]==nums[j]){
            return true;
        }
    }
  }
 return false;
 }
};
*/
 // The optimal method: Hashset used to store elements we've already seen.
class Solution{
 public:
 bool hasDuplicate(vector<int>& nums){
    unordered_set<int>duplicated;
    for(int num:nums){
        if (duplicated.count(num)){
            return true;
        }
       
            duplicated.insert(num);
        
    }
    return false;

 }
};


int main(){
  Solution s;
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<nums.size();i++){
    cin>>nums[i];
  }
  cout<<boolalpha<<s.hasDuplicate(nums)<<endl;
    return 0;
}


