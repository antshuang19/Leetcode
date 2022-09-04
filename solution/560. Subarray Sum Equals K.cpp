class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int sum =0, res =0;
        map[sum]=1;
        for(auto itr : nums)
        {
            sum = sum + itr;
            int find = sum - k;
            if(map.find(find) != map.end())
            {
                res = res + map[find];
            }
            map[sum]++;
        }
        return res;
    }
};