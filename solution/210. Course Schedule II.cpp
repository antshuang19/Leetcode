class Solution {
public:
    vector<int>answer;
    enum class state{init,visiting,finish};
    bool dfs_cycle(vector<vector<int>> &graph, int start,vector<state>&status)
    {
        if(status[start]== state::visiting)
        {
            return true;
        }
        if(status[start]==state::finish)
        {
            return false;
        }
        status[start]= state::visiting;
        for(auto u : graph[start])
        {
            if(dfs_cycle(graph,u,status))
            {
                return true;
            }
        }
        status[start]= state::finish;
        answer.push_back(start);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<state> status(numCourses);
        vector<vector<int>> graph(numCourses);
        for(auto temp :prerequisites)
        {
            graph[temp[1]].push_back(temp[0]);
        }
        
        for(int i =0; i < numCourses;i++)
        {
            if(dfs_cycle(graph,i,status))
                return {};
        }
        reverse(begin(answer),end(answer));
        return answer;
    }
};