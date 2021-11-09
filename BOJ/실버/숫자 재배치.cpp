#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(int argc, const char* argv[]) {

    string A;
    int B;
    string C;
    
    cin >> A >> B;
    C = "0";

    sort(A.begin(), A.end());

    do
    {
        if (stoi(A) < B)
            C = A;
        else
            break;
    } while (next_permutation(A.begin(), A.end()));

    if (C == "0")
        cout << -1;
    else
    {
        if (C[0] == '0')
        {
            cout << -1;
        }
        else
        {
            cout << C;
        }
        
    }
    return 0;
}
