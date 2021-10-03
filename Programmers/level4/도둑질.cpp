#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer1 = 0;
    int answer2 = 0;
    int prev = 0;
    int prev2 = 0;
    
    for(int i = 1;i<money.size();i++)
    {
        int temp = answer1;
        answer1 = max(answer1,prev + money[i]);
        prev = temp;      
    }
    
    for(int i = 0;i<money.size() - 1;i++)
    {
        int temp = answer2;
        answer2 = max(answer2,prev2 + money[i]);
        prev2 = temp;
    }
    
    return max(answer1,answer2);
}
