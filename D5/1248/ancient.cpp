#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    int V,E,c1,c2;
    int a,b;

    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>V>>E>>c1>>c2;
        vector <int> v1[10001];
        vector<int>v2[10001];

        for(int i = 0;i<E;i++)
        {
            cin>>a>>b;
            v1[a].push_back(b);
            v2[b].push_back(a);
        }
        
        queue <int> q1;
        q1.push(c1);
        int count1 = 1;
        int save1[1001];
        save1[0] = c1;

        while(!q1.empty()){
            int temp = q1.front();
            q1.pop();
            for(int i = 0;i<v2[temp].size();i++)
            {
                q1.push(v2[temp][i]);
                save1[count1] = v2[temp][i];
                count1++;
            }
        }

        queue <int> q2;
        q2.push(c2);
        int count2 = 1;
        int save2[1001];
        save2[0] = c2;

        while(!q2.empty())
        {
            int temp = q2.front();
            q2.pop();
            for(int i = 0;i<v2[temp].size();i++)
            {
                q2.push(v2[temp][i]);
                save2[count2] = v2[temp][i];
                count2++;
            }
        }
        int ans;
        int count3 = 0;
        for(int i = 0;i<count1;i++)
        {
            for(int j = 0;j<count2;j++)
            {
                if(save1[i] == save2[j])
                {
                    ans = save1[i];
                    count3++;
                    break;
                }
            }
            if(count3 == 1)
                break;
        }
        
        int depth = 1;
        int temp = 0;
        queue <int> q3;
        q3.push(ans);
        vector <int> v3;
        v3.push_back(ans);
        int count = 1;
        while(!v3.empty())
        {
            int size = v3.size();
            for(int i = 0;i<v3.size();i++)
            {
                for(int j = 0;j<v1[v3[i]].size();j++)
                {
                    v3.push_back(v1[v3[i]][j]);
                    depth++;
                }
                v3.erase(v3.begin());
                i--;
            }
             
        }

        cout<<"#"<<test_case<<" "<<ans<<" "<<depth<<endl;
    }
}
