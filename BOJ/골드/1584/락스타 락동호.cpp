#pragma warning(disable:4996)
#include <iostream>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int FF, FS, SF, SS;

    cin >> FF >> FS >> SF >> SS;

    if (FF == 0 && FS == 0) {
        if (SF == 0)
            cout << SS;
        else
            cout << SS + 1;
    }
    else if (FS == 0) {
        cout << FF;
    }
    else {
        if (FS <= SF)
            cout << FF + FS + FS + SS;
        else
            cout << FF + SF + SF + SS + 1;
    }


    return 0;

}
