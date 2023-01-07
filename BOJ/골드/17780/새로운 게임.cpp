#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int board[12][12];
pair<int, pair<int, int>> piece[10];
vector<int> num[12][12];

int changeDir(int d) {

    switch (d) {
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 4;
    case 4:
        return 3;
    }
}
int move(int N, int K) {

    int step = 1;
    int x, y, d;
    int nx, ny;

    int i, j;
    int dx[5] = { 0,0,0,-1,1 };
    int dy[5] = { 0,1,-1,0,0 };

    while (1) {
        if (step > 1000) {
            return -1;
        }

        for (i = 0; i < K; i++) {
            x = piece[i].second.first;
            y = piece[i].second.second;
            d = piece[i].first;


           if (num[x][y][0] != i) {
               continue;
           }

           nx = x + dx[d];
           ny = y + dy[d];

           if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
               d = changeDir(d);

               nx = x + dx[d];
               ny = y + dy[d];
           }

           if (board[nx][ny] == 0) {
               for (j = 0; j < num[x][y].size(); j++) {
                   num[nx][ny].push_back(num[x][y][j]);

                   if (j == 0) {
                       piece[num[x][y][j]] = { d,{nx,ny} };
                   }
                   else {
                       piece[num[x][y][j]] = { piece[num[x][y][j]].first,{nx,ny} };
                   }
               }
           }
           else if (board[nx][ny] == 1) {
               for (j = num[x][y].size() - 1; j >= 0; j--) {
                   num[nx][ny].push_back(num[x][y][j]);
                   if (j == 0) {
                       piece[num[x][y][j]] = { d,{nx,ny} };
                   }
                   else {
                       piece[num[x][y][j]] = { piece[num[x][y][j]].first,{nx,ny} };
                   }
               }
           }
           else if (board[nx][ny] == 2) {
               d = changeDir(d);
               nx = x + dx[d];
               ny = y + dy[d];

               if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                   d = changeDir(d);

                   for (j = 0; j < num[x][y].size(); j++) {
                       if (j == 0) {
                           piece[num[x][y][j]] = { d,{x,y} };
                       }
                       else {
                           piece[num[x][y][j]] = { piece[num[x][y][j]].first,{x,y} };
                       }
                   }
                   continue;
               }
               else if (board[nx][ny] == 2) {
                   d = changeDir(d);
                   for (j = 0; j < num[x][y].size(); j++) {
                       if (j == 0) {
                           piece[num[x][y][j]] = { d,{x,y} };
                       }
                       else {
                           piece[num[x][y][j]] = { piece[num[x][y][j]].first,{x,y} };
                       }
                   }
                   continue;
               }
               else if (board[nx][ny] == 0) {
                   for (j = 0; j < num[x][y].size(); j++) {
                       num[nx][ny].push_back(num[x][y][j]);
                       if (j == 0) {
                           piece[num[x][y][j]] = { d,{nx,ny} };
                       }
                       else {
                           piece[num[x][y][j]] = { piece[num[x][y][j]].first,{nx,ny} };
                       }
                   }
               }
               else if (board[nx][ny] == 1) {
                   for (j = num[x][y].size()-1; j >= 0; j--) {
                       num[nx][ny].push_back(num[x][y][j]);
                       if (j == 0) {
                           piece[num[x][y][j]] = { d,{nx,ny} };
                       }
                       else {
                           piece[num[x][y][j]] = { piece[num[x][y][j]].first,{nx,ny} };
                       }
                   }
               }
           }

           num[x][y].clear();

           if (num[nx][ny].size() >= 4) {
               return step;
           }
        }
        step++;
    }


    return step;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K, i, j;

    cin >> N >> K;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    int x, y, d;

    for (i = 0; i < K; i++) {
        cin >> x >> y >> d;
        piece[i] = { d,{x - 1,y - 1} };
        num[x - 1][y - 1].push_back(i);
    }

    cout << move(N, K);

    return 0;
}
