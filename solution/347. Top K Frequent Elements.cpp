class Solution
{
public:
    bool static compare(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> answer;
        unordered_map<int, int> hashmap;
        vector<pair<int, int>> map;
        for (int i = 0; i < nums.size(); i++)
        {
            hashmap[nums[i]]++;
        }
        for (auto itr : hashmap)
            map.push_back(itr);
        sort(begin(map), end(map), compare);
        for (auto itr = begin(map); itr != end(map); itr++)
        {
            if (k == 0)
                break;
            answer.push_back(itr->first);
            k--;
        }
        return answer;
    }
};