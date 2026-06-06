//OPTIMAL
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int col0 = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(mat[i][j] == 0) {

                mat[i][0] = 0;

                if(j != 0)
                    mat[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {

            if(mat[i][0] == 0 || mat[0][j] == 0)
                mat[i][j] = 0;
        }
    }

    if(mat[0][0] == 0) {
        for(int j = 0; j < m; j++)
            mat[0][j] = 0;
    }

    if(col0 == 0) {
        for(int i = 0; i < n; i++)
            mat[i][0] = 0;
    }

    for(auto row : mat) {
        for(auto x : row)
            cout << x << " ";
        cout << endl;
    }
}



//BETTER
/*#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(row[i] || col[j])
                mat[i][j] = 0;
        }
    }

    for(auto rowVec : mat) {
        for(auto x : rowVec)
            cout << x << " ";
        cout << endl;
    }
}*/



//BRUTE
/*#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int mark = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {

                for(int k = 0; k < m; k++) {
                    if(mat[i][k] != 0)
                        mat[i][k] = mark;
                }

                for(int k = 0; k < n; k++) {
                    if(mat[k][j] != 0)
                        mat[k][j] = mark;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == mark)
                mat[i][j] = 0;
        }
    }

    for(auto row : mat) {
        for(auto x : row)
            cout << x << " ";
        cout << endl;
    }
}*/