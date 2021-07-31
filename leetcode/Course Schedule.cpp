class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> v(numCourses, vector<int>());
        vector<int> count(numCourses,0);
        
        for(int i = 0;i<prerequisites.size();i++)
        {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
            count[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++)
        {
            if(count[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            numCourses--;
            for(int i = 0;i<v[a].size();i++)
            {
                if(count[v[a][i]]-- == 1)
                {
                    q.push(v[a][i]);
                }
            }
        }
        
        return numCourses == 0;
        
    }
};
