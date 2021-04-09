#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int>b)
{
        return a.second > b.second;
}
int main(int argc, char** argv)
{
        int bag;
        int grocery;
        
        vector<pair<int,int>> weight;

        cin>>bag>>grocery;

        int a,b;
        for(int i = 0;i<grocery;i++){
                cin>>a>>b;
                weight.push_back(make_pair(a,b));
        }
        sort(weight.begin(),weight.end(),cmp);

        int count = 0;
        int size = weight.size();
        int ans = 0;

        while(bag != 0)
        {
                if(count > size)
                        break;
                if(bag > weight[count].first){
                        bag = bag - weight[count].first;
                        ans = ans + weight[count].first * weight[count].second;
                }
                else
                {
                        ans = ans + weight[count].second * bag;
                        bag = 0;
                }

                count++;
        }
        cout<<ans<<endl;
 return 0;
}
