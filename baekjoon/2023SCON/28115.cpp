// based problem:
#include <vector>
#include <iostream>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int n;
vector<int> seq;

void init()
{
    FAST
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }
}

void solve()
{
    // 0으로 이루어진 수열은 등차수열이다.
    if(seq.size() == 1){
        cout << "YES" << endl;
        cout << seq[0] << endl;
        cout << 0 << endl;
    }
    else{
        bool isSequential = true;
        int d = seq[1] - seq[0];
        for(int i=2; i<n; i++){
            if(seq[i] - seq[i-1] != d){
                isSequential = false;
                break;
            }
        }
        if(!isSequential) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for(int i=0; i<n; i++) cout << seq[i] << ' ';
            cout << endl;
            for(int i=0; i<n; i++) cout << 0 << ' ';
            cout << endl;
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}