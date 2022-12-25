#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int left = 0;
    int right = B.size()-1;
    
    for(int i = right;i>=0;i--){
        if(B[right] > A[i]){
            answer++;
            right--;
        }
        else{
            left++;
        }
    }
    return answer;
}
