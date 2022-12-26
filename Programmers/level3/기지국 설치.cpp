#include <iostream>
#include <vector>
using namespace std;

int calDistance(int start, int end, int W){
    
    if(start > end){
        return 0;
    }
    
    int dist = 1 + W * 2;
    int base = (end-start+1)/dist;
    int remainder = (end-start+1)%dist;
    
    if(remainder > 0){
        return base+1;
    }
    else{
        return base;
    }
}
int solution(int n, vector<int> stations, int w)
{
    int answer = calDistance(1,stations[0]-w-1,w);
    
    for(int i = 0;i<stations.size()-1;i++){
        answer += calDistance(stations[i]+w+1,stations[i+1]-w-1,w);
    }
    
    answer += calDistance(stations[stations.size()-1]+w+1,n,w);
    
    return answer;
}
