#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    
    int N,K,c;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>K;
        
        vector <int> distance;
        vector <int> camera;
        for(int i = 0;i<N;i++){
            int a;
            cin>>a;
            camera.push_back(a + 1000010);
        }
        
		
        sort(camera.begin(),camera.end());
        
        for(int i = 1;i<camera.size();i++)
        {
            distance.push_back(camera[i] - camera[i-1]);
        }
        sort(distance.begin(),distance.end());
        
        int sum = 0;
        int size = distance.size();
        for(int i = 0;i<size - (K - 1);i++)
            sum += distance[i];
        
        cout<<"#"<<test_case<<" "<<sum<<endl;
        
    }
}
