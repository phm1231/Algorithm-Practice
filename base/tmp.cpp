#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Rotate(int y, int x, int siz, vector<vector<int> >& bd){
    vector<vector<int> > tmp = bd;

    for(int i=0; i<siz; i++){
        for(int j=0; j<siz; j++){
            tmp[j][siz-1-i] = bd[i][j];
        }
    }
    for(int i=0; i<siz; i++){
        for(int j=0; j<siz; j++){
            bd[i][j] = tmp[i][j];
        }
    }
}

int main(){
    int n = 4;
    vector<vector<int> > bd(4, vector<int>(4, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bd[i][j] = i*4+j;
        }
    }
    cout << "Before" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << bd[i][j] << ' ';
        }
        cout << endl;
    }
    Rotate(0, 0, 4, bd);
    cout << "After" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << bd[i][j] << ' ';
        }
        cout << endl;
    }
}