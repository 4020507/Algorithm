#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.rbegin(),routes.rend());
    int dist = 300001;

    for(auto r:routes)
    {
        if(dist > r[1])
        {
            dist = r[0];
            answer++;
        }
    }
    return answer;
}
