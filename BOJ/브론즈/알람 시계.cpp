#include <iostream>
#include <algorithm>

using namespace std;

int hour, miniute;
int main(int argc, const char* argv[]) {
    
    cin >> hour >> miniute;

    if (miniute >= 45)
    {
        miniute -= 45;
    }
    else
    {
        miniute = miniute - 45 + 60;
        hour--;

        if (hour == -1)
            hour = 23;
    }

    cout << hour << ' ' << miniute;

    return 0;
}
