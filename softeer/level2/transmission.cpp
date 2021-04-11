#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
        int num[8];

        for(int i = 0;i<8;i++)
                cin>>num[i];
        int start = num[0];

        if(start != 1 && start != 8){
                cout<<"mixed"<<endl;
                return 0;
        }

        bool check = true;
        int identify;
        if(start == 1){
                identify = 1;
                for(int i = 1;i<8;i++)
                {
                        if(num[i] == start + 1)
                        {
                                start = start +1;
                        }
                        else{
                                check = false;
                                break;
                        }
                }
        }
        else if(start == 8)
        {
                identify = 8;
                for(int i = 1;i<8;i++)
                {
                        if(num[i] == start -1)
                        {
                                start = start -1;
                        }
                        else{
                                check = false;
                                break;
                        }
                }
        }

        if(check && identify == 1)
                cout<<"ascending"<<endl;
        else if(check && identify == 8)
                cout<<"descending"<<endl;
        else if(!check)
                cout<<"mixed"<<endl;
 return 0;
}
