#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 51

using namespace std;
int N, maxCandy = 0;
vector<string> candy;

void check();

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        candy.push_back(tmp);
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            swap(candy[i][j], candy[i][j + 1]);
            check();
            swap(candy[i][j], candy[i][j + 1]);
        }
    }

    for(int j = 0; j < N; j++) {
        for(int i = 0; i < N - 1; i++) {
            swap(candy[i][j], candy[i + 1][j]);
            check();
            swap(candy[i][j], candy[i + 1][j]);
        }
    }

    cout << maxCandy << '\n';

    return 0;
}

void check() {

    for(int i = 0; i < N; i++) {
        int count = 1;
        for(int j = 0; j < N; j++) {
            if(candy[i][j] == candy[i][j + 1]) {
                count++;
            }
            else {
                if(maxCandy < count) maxCandy = count;
                count = 1;
            }
        }
    }

    for(int j = 0; j < N; j++) {
        int count = 1;
        for(int i = 0; i < N; i++) {
            if(candy[i][j] == candy[i + 1][j]) {
                count++;
            }
            else {
                if(maxCandy < count) maxCandy = count;
                count = 1;
            }
        }
    }
}