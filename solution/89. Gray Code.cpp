class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer{0};
        for(int i =0; i < n;i++)
        {
            for(int j =answer.size()-1;j >=0;--j)
            {
                answer.push_back(answer[j] | 1 << i);
            }
        }
        return answer;
    }
};