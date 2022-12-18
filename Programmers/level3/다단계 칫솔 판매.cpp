#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> index;
int profit[10000];
int recommender[10000];

void init(vector<string>& enroll, vector<int>& amount, vector<string>& referral){
    
    int i;
    
    //실제 값
    for(i = 0;i<amount.size();i++){
        amount[i] *= 100;
    }
    
    //string -> index
    for(i = 0;i<enroll.size();i++){
        index[enroll[i]] = i;
    }
    
    //추천인
    for(int i = 0;i<referral.size();i++){
        if(referral[i] != "-"){
            recommender[i] = index[referral[i]];
        }
        else{
            recommender[i] = -1;
        }
    }
}

void calculateProfit(int idx, int distribute){
    
    if(idx == -1){
        return;
    }
    
    int d = distribute * 0.1;
    
    if(d >= 1){
        profit[idx] += (distribute - d);
        calculateProfit(recommender[idx], d);
    }
    else{
        profit[idx] += distribute;
    }
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    init(enroll, amount, referral);
    
    for(int i = 0;i< seller.size();i++){
        calculateProfit(index[seller[i]], amount[i]);
    }
    
    for(int i = 0;i<enroll.size();i++){
        answer.push_back(profit[i]);
    }
    return answer;
}
