#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

        

        //O(m*nlogn)
 /*
        for(const string& s : strs){
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> r;
        for(auto& [key, group] : mp){
            r.push_back(group);
        }

        return r;
    }
};
*/

class Solution{
public:
    vector<vector<string>> groupAnagram(vector<string>& strs){
        unordered_map<string, vector<string>> mp;
        for(const string&s: strs){
            int count[26]={0};
            for(char c:s){
                count[c-'a']++;
            }
                string key="";
                for(int i=0;i<26;i++){
            key += to_string(count[i]) + "#";
                }
            mp[key].push_back(s);
            }
        vector<vector<string>> r;
        for(auto& [key, group] : mp){
            r.push_back(group);
        }

        return r;
        
        
    }
};

int main(){
    Solution sol;

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings:\n";
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }

    vector<vector<string>> result = sol.groupAnagram(strs);

    cout << "\nGrouped Anagrams:\n";
    for(auto& group : result){
        cout << "[ ";
        for(auto& s : group)
            cout << s << " ";
        cout << "]\n";
    }

    return 0;
}
