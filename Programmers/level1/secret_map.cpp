#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0;i<n;i++)
    {
        int a = arr1[i];
        int b = arr2[i];
        string ans = "";
        while(a>0 || b > 0)
        {
            if(a%2 == 1 || b%2 == 1)
                ans += "#";
            else
                ans += " ";
            a /= 2;
            b /= 2;
        }
        while(ans.size() < n)
            ans += " ";
        reverse(ans.begin(),ans.end());
        answer.push_back(ans);
    }
    return answer;
}
