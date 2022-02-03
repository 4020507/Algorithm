#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {

    string origin;
    string explode;

    cin >> origin >> explode;

    
    string answer = "";
    int len = explode.length()-1;

    for (int i = 0;i < origin.length();i++)
    {
        answer += origin[i];

        if (answer[answer.length()-1] == explode[len] && answer.length() >= len + 1)
        {
            int k = len;
            int len2 = answer.length() - 1;
            for (int i = len2;i >= len2 - len;i--)
            {
                if (answer[i] != explode[k--])
                    break;
            }

            if (k == -1 && explode[0] == answer[len2 - len])
            {
                for (int i = 0;i <= len;i++)
                    answer.pop_back();
            }
        }
    }

    if (answer.empty())
        cout << "FRULA";
    else
        cout << answer;
    return 0;
}
