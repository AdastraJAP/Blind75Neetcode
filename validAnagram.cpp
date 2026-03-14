#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;
/*

if(s.length()!=t.length()){
    return false;
}
sort(s.begin(),s.end());
sort(t.begin(),t.end());
 return s==t;
}

*/
class Solution{
public:
bool isAnagram(string s, string t){
unordered_map<char,int>mp;
if(s.length()!=t.length()){
    return false;
}
for(char c: s){
    mp[c]++;
}
for(char c: t){
    mp[c]--;
}
for(auto& pair:mp){
    if(pair.second!=0)
     return false;
}
return true;
}
};


int main(){
Solution sol;
string s,t;
cin >> s >> t;
cout<<boolalpha<<sol.isAnagram(s,t)<<endl;


    return 0;
}