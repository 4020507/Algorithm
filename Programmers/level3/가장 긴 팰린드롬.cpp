#include <string>

using namespace std;

bool checkPalin(string& s, int start, int end){
    
    while(start < end){
        if(s[start] == s[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    
    return true;
}
int solution(string s)
{
    int answer=1;

    int i,j;
    int len = s.size();
    for(i = 0;i<len;i++){
        for(j = i - 1;j>=0;j--){
            if(answer < i - j + 1){
                if(checkPalin(s,j,i)){
                    answer = max(answer,(i-j+1));
                }
            }
        }
    }
    return answer;
}
