class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int indegree[2001];
        vector<int> course[2001];
        
        memset(indegree,0,sizeof(indegree));
        
        int maxi = 0;
        for(int i = 0;i<prerequisites.size();i++)
        {
            course[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
            
        }
        
        queue<int> q;
        
        for(int i = 0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> result;
        
        while(!q.empty())
        {
            int a = q.front();
            result.push_back(a);
            q.pop();
            
            for(int i = 0;i<course[a].size();i++)
            {
                indegree[course[a][i]]--;
                
                if(indegree[course[a][i]] == 0)
                    q.push(course[a][i]);
            }
        }
        
        if(result.size() == numCourses)
            return result;

        return vector<int>();
    }
    

};
