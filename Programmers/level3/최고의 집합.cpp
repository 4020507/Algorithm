#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s){
        answer.push_back(-1);
    }
    else{
        int quotient = s/n;
        int remainder = s%n;
        
        for(int i = 0;i<n;i++){
            if(remainder > 0){
                answer.push_back(quotient+1);
                remainder--;
            }
            else{
                answer.push_back(quotient);
            }
        }
        
        sort(answer.begin(),answer.end());
    }
    return answer;
}
