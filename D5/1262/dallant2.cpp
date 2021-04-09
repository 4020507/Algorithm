#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    
    long long total, bundle;
    long long common, left,origin;
    long long result;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>total>>bundle;
        common = (int)(total/bundle);
        left = fmod(total,bundle);
        result = 1;
        vector<long long> mini;
        
        for(int i = 0;i<bundle;i++){
            mini.push_back(common);
        }
        
        for(int i = 0;i<left;i++)
            mini[i] += 1;
        
        for(int i = 0;i<mini.size();i++)
            result *= mini[i];
        
        cout<<"#"<<test_case<<" "<<result<<endl;
    }
}
