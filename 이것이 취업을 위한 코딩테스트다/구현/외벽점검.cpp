#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    
    int len = weak.size();
    
    for(int i = 0;i<len;i++)
    {
        weak.push_back(weak[i] + n);
    }
    
    for(int i = 0;i<len;i++)
    {
        do
        {
            int count = 1;
            int pos = weak[i] + dist[count - 1];
            
            for(int j = i;j<i+len;j++)
            {
                if(pos < weak[j])
                {
                    count++;
                    if(count >dist.size())
                        break;
                    pos = weak[j] + dist[count - 1];
                }
            }
            answer = min(answer,count);
        }while(next_permutation(dist.begin(),dist.end()));
    }
    return answer;
}
