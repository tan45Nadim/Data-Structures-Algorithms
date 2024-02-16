#include <iostream>
using namespace std;

void lcsLength(string x, string y, int m, int n, int **c, char **b) {
    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (int j = 1; j <= n; j++) {
        c[0][j] = 0;
    }
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

void printLcs(char **b, string x, int i, int j) {
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

    int lenStr1 = str1.size();
    int lenStr2 = str2.size();

    // Dynamically Allocate
    int **c = new int*[lenStr1 + 1];
    char **b = new char*[lenStr1 + 1];
    for (int i = 0; i <= lenStr1; i++) {
        c[i] = new int[lenStr2 + 1];
        b[i] = new char[lenStr2 + 1];
    }

    lcsLength(str1, str2, lenStr1, lenStr2, c, b);
    cout << "Length of LCS: " << c[lenStr1][lenStr2] << endl;
    cout << "LCS = ";
    printLcs(b, str1, lenStr1, lenStr2);

    // Delete the array
    for (int i = 0; i <= lenStr1; i++) {
        delete[] c[i]; delete[] b[i];
    }
    delete[] c; delete[] b;
}


// INPUT

// AGGTAB GXTXAYB
// abcbdab bdcaba
