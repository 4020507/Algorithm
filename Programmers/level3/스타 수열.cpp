#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(std::vector<int> a) {
    int answer = 0;
    unordered_map<int, int> m;
    int i,temp;

    for(i = 0;i<a.size();i++){
        m[a[i]]++;
    }

    for(auto mp:m){

        if(mp.second *2 <= answer){
            continue;
        }
        temp = 0;

        for(i = 0;i<a.size()-1;i++){
            if(a[i] == a[i+1]){
                continue;
            }

            if(a[i] != mp.first && a[i+1] != mp.first){
                continue;
            }

            temp += 2;
            i++;
        }

        answer = max(answer,temp);
    }
    return answer;
}
