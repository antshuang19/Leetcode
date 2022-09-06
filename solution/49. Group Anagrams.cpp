class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;
        vector<vector<string>> answer;
        
        for(const string temp : strs)
        {
            string tmp = temp;
            sort(begin(tmp), end(tmp));
            hashmap[tmp].push_back(temp);
        }
        for(auto member : hashmap)
        {
            answer.push_back(member.second);
        }
        return answer;
    }
};