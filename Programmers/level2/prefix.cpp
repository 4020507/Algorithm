#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end());
    int len = phone_book.size();
    for(int i = 0;i<len-1;i++)
    {
        int size = phone_book[i].size();
        if(phone_book[i] == phone_book[i+1].substr(0,size))
        {
            return false;
        }
    }
    return answer;
}
