#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Atom {
public:
    int x;
    int y;
    int m;
    int s;
    int d;
};

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<int> matrix[51][51];
int n;
vector<Atom> v;

pair<int, int> dirCheck(int x, int y) {

    if (x <= 0) {
        x = n;
    }
    else if (x > n) {
        x = 1;
    }

    if (y <= 0) {
        y = n;
    }
    else if (y > n) {
        y = 1;
    }

    return { x,y };
}

void move() {
    int j;
    pair<int, int> temp;
    Atom atom;

    for (int i = 0; i < v.size(); i++) {
        atom = v[i];
        for (j = 0; j < atom.s; j++) {
            temp = dirCheck(atom.x + dx[atom.d], atom.y + dy[atom.d]);
            atom.x = temp.first;
            atom.y = temp.second;
        }
        matrix[atom.x][atom.y].push_back(i);
        v[i] = atom;
    }
}

int nonDiagonalDir(int num) {
    if (num == 0) {
        return 0;
    }
    else if (num == 1) {
        return 2;
    }
    else if (num == 2) {
        return 4;
    }
    else if (num == 3) {
        return 6;
    }
}

int diagonalDir(int num) {
    if (num == 0) {
        return 1;
    }
    else if (num == 1) {
        return 3;
    }
    else if (num == 2) {
        return 5;
    }
    else if (num == 3) {
        return 7;
    }
}

void compound() {
    int i, j, k;
    int m, s, d;
    bool diagonal;
    bool nonDiagonal;
    vector<Atom> tempA;
    Atom tempAtom;
    int idx;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (matrix[i][j].size() > 1) {
                m = s = 0;
                diagonal = false;
                nonDiagonal = false;

                for (k = 0; k < matrix[i][j].size(); k++) {
                    idx = matrix[i][j][k];
                    m += v[idx].m;
                    s += v[idx].s;

                    if (v[idx].d == 0 || v[idx].d == 2 || v[idx].d == 4 || v[idx].d == 6) {
                        nonDiagonal = true;
                    }
                    else {
                        diagonal = true;
                    }
                }

                m = m / 5;
                s = s / matrix[i][j].size();
                if (m == 0) {
                    matrix[i][j].clear();
                    continue;
                }

                tempAtom.x = i;
                tempAtom.y = j;
                tempAtom.m = m;
                tempAtom.s = s;

                if (nonDiagonal == true && diagonal == true) {
                    for (k = 0; k < 4; k++) {
                        tempAtom.d = diagonalDir(k);
                        tempA.push_back(tempAtom);
                    }
                }
                else {
                    for (k = 0; k < 4; k++) {
                        tempAtom.d = nonDiagonalDir(k);
                        tempA.push_back(tempAtom);
                    }
                }

                matrix[i][j].clear();
            }
            else if (matrix[i][j].size() == 1) {
                tempA.push_back(v[matrix[i][j][0]]);
                matrix[i][j].clear();
            }
        }
    }

    v = tempA;
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, k;

    cin >> n >> m >> k;

    int i;
    int x, y, mass, s, d;
    Atom atom;

    for (i = 0; i < m; i++) {
        cin >> x >> y >> mass >> s >> d;
        atom.x = x;
        atom.y = y;
        atom.m = mass;
        atom.s = s;
        atom.d = d;

        v.push_back(atom);
    }

    for (i = 0; i < k; i++) {
        move();
        compound();
    }

    mass = 0;

    for (i = 0; i < v.size(); i++) {
        mass += v[i].m;
    }

    cout << mass;

    return 0;
}
