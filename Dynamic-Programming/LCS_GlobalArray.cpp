#include <iostream>
using namespace std;

int c[100][100]; char b[100][100];

void lcsLength(string x, string y, int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
}

void printLcs(char b[100][100], string x, int i, int j) {
    if (i == 0 || j == 0) return;

    if (b[i][j] == 'd') {
        printLcs(b, x, i - 1, j - 1);
        cout << x[i - 1];
    } else if (b[i][j] == 'u') {
        printLcs(b, x, i - 1, j);
    } else {
        printLcs(b, x, i, j - 1);
    }
}

int main () {
    cout << "Enter Two String: ";
    string str1, str2; cin >> str1 >> str2;

    int lenStr1 = str1.size(); //cout << lenStr1 << endl;
    int lenStr2 = str2.size(); //cout << lenStr2 << endl;

    lcsLength(str1, str2, lenStr1, lenStr2);
    cout << "Length of LCS: " << c[lenStr1][lenStr2] << endl;

    cout << "LCS = ";
    printLcs(b, str1, lenStr1, lenStr2);
    
}

// INPUT

//AGGTAB GXTXAYB

//abcbdab bdcaba
