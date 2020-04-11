#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define endl '\n';

int N;
char kingCol, stoneCol;
int kingRow, stoneRow;

bool isStone(char col, int row) {
    if (col == stoneCol && row == stoneRow) {
        return true;
    }
    return false;
}

bool isBoundary(char y, int x) {
    if ('A' <= y && y < 'A' + 8 && 1 <= x && x <= 8) {
        return true;
    }
    return false;
}

pair<char, int> nextStone(string s) {
    char col = stoneCol;
    int row = stoneRow;

    if (s == "R") {
        return {col + 1, row};
    } else if (s == "L") {
        return {col - 1, row};
    } else if (s == "B") {
        return {col, row - 1};
    } else if (s == "T") {
        return {col, row + 1};
    } else if (s == "RT") {
        return {col + 1, row + 1};
    } else if (s == "LT") {
        return {col - 1, row + 1};
    } else if (s == "RB") {
        return {col + 1, row - 1};
    } else {
        return {col - 1, row - 1};
    }
}

pair<char, int> nextKing(string s) {
    char col = kingCol;
    int row = kingRow;

    if (s == "R") {
        return {col + 1, row};
    } else if (s == "L") {
        return {col - 1, row};
    } else if (s == "B") {
        return {col, row - 1};
    } else if (s == "T") {
        return {col, row + 1};
    } else if (s == "RT") {
        return {col + 1, row + 1};
    } else if (s == "LT") {
        return {col - 1, row + 1};
    } else if (s == "RB") {
        return {col + 1, row - 1};
    } else {
        return {col - 1, row - 1};
    }
}

void move(string s) {
    pair<char, int> nKing = nextKing(s);
    pair<char, int> nStone = nextStone(s);

    if (isBoundary(nKing.first, nKing.second)) {
        if (isStone(nKing.first, nKing.second)) {
            if (isBoundary(nStone.first, nStone.second)) {
                stoneCol = nStone.first;
                stoneRow = nStone.second;
            } else {
                return;
            }
        }
        kingCol = nKing.first;
        kingRow = nKing.second;
    } else {
        return;
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> kingCol >> kingRow >> stoneCol >> stoneRow >> N;

    while (N--) {
        string command;
        cin >> command;

        move(command);
    }

    cout << kingCol << kingRow << '\n';
    cout << stoneCol << stoneRow << '\n';
}
