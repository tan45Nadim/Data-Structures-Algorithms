#include <iostream>
using namespace std;

void EDlength(string x, string y, int m, int n, int **c, char **b) {
    c[0][0] = 0; b[0][0] = ' ';
    for (int i = 1; i <= m; i++) {
        c[i][0] = i;
        b[i][0] = 'd';
    }
    for (int j = 1; j <= n; j++) {
        c[0][j] = j;
        b[0][j] = 'i';
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1];
                b[i][j] = 'n';
            } else if ((c[i - 1][j - 1] <= c[i - 1][j]) && (c[i - 1][j - 1] <= c[i][j - 1])) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'r';
            } else if (c[i - 1][j] <= c[i][j - 1]) {
                c[i][j] = c[i - 1][j] + 1;
                b[i][j] = 'd';
            } else {
                c[i][j] = c[i][j - 1] + 1;
                b[i][j] = 'i';
            }
        }
    }
}

void EDstatus(char **b, string x, string y, int i, int j) {
    if (i == 0 && j == 0) return;

    if (b[i][j] == 'n') {
        EDstatus(b, x, y, i - 1, j - 1);
//        cout << "No Change " << x[i - 1] << endl;
    } else if (b[i][j] == 'r') {
        EDstatus(b, x, y, i - 1, j - 1);
        cout << "Replace " << x[i - 1] << " by " << y[j - 1] << endl;
    } else if (b[i][j] == 'd') {
        EDstatus(b, x, y, i - 1, j);
        cout << "Delete " << x[i - 1] << endl;
    } else {
        EDstatus(b, x, y, i, j - 1);
        cout << "Insert " << y[j - 1] << endl;
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

    EDlength(str1, str2, lenStr1, lenStr2, c, b);
    cout << "Edit Distance: " << c[lenStr1][lenStr2] << endl << endl;
    cout << "Sequence of edit operations needed to convert " << str1 <<  " to " << str2 << " :"<< endl;
    EDstatus(b, str1,str2, lenStr1, lenStr2);

    // Delete the Array
    for (int i = 0; i <= lenStr1; i++) {
        delete[] c[i]; delete[] b[i];
    }
    delete[] c; delete[] b;
}


// INPUT

// heater speak
// speak heater
// algorithm altruistic
// altruistic algorithm
// aeroplane apple
