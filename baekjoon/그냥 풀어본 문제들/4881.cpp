// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void go(int, int);
int getSquareNumber(int);

vector<int> A, B;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        A.push_back(a);
        B.push_back(b);
    }
}

void solve()
{
    int siz = A.size();

    for(int i=0; i<siz; i++){
        go(A[i], B[i]);
    }
}

void go(int p, int q){
    vector<int> vp, vq;
    vp.push_back(p);
    vq.push_back(q);

    while(1){
        int np = getSquareNumber(vp.back());

        // 중복 검사
        bool duplication = false;
        for(int i=0; i<vp.size(); i++){
            if(vp[i] == np){
                duplication = true;
                break;
            }
        }
        if(duplication) break;
        else vp.push_back(np);
    }

    while(1){
        int nq = getSquareNumber(vq.back());

        // 중복 검사
        bool duplication = false;
        for(int i=0; i<vq.size(); i++){
            if(vq[i] == nq){
                duplication = true;
                break;
            }
        }
        if(duplication) break;
        else vq.push_back(nq);
    }

    int answer = 987654321;
    for(int i=0; i<vp.size(); i++){
        for(int j=0; j<vq.size(); j++){
            if(vp[i] == vq[j]) answer = min(answer, i+j+2);
        }
    }
    if(answer == 987654321) cout << p << " " << q << " 0\n";
    else cout << p << " " << q << " " << answer << "\n";
    return;
}

int getSquareNumber(int num){
    int answer = 0;
    while(num != 0){
        answer += ((num % 10) * (num % 10));
        num /= 10;
    }
    return answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}