#include <string>
#include <vector>

using namespace std;

int left[1000000];
int right[1000000];

int solution(vector<int> a) {
    int answer = 0;
    left[0] = a[0];
    int i;
    
    for(i = 1;i<a.size();i++){
        left[i] = min(left[i-1],a[i]);
    }
    
    right[a.size()-1] = a[a.size()-1];
    
    for(i = a.size()-2;i>=0;i--){
        right[i] = min(right[i+1],a[i]);
    }
    
    for(i = 0;i<a.size();i++){
        if(i == 0 || i == a.size()-1){
            answer++;
        }
        else if(a[i] <= left[i] || a[i] <= right[i]){
            answer++;
        }
    }
    return answer;
}
