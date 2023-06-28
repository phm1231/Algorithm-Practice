// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, k; // 구멍의 개수, 사용 횟수
vector<int> v;
vector<int> plugs;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    v.resize(k+1, 0);
    plugs.resize(n, 0);

    for(int i=1; i<=k; i++){
        cin >> v[i];
    }
}

void solve()
{
    int answer = 0;
    // 플러그가 충분할 경우
    if(n >= k){
        cout << 0;
        return;
    }

    for(int i=1; i<=k; i++){
        int tool = v[i];
        // 이미 사용 중인 전자기기인지 검사
        bool isUsing = false;
        for(int j=0; j<plugs.size(); j++){
            if(plugs[j] == tool){
                isUsing = true;
                break;
            }
        }
        // 이미 사용 중이라면 다음으로.
        if(isUsing) continue;

        // 빈 플러그가 있다면
        bool isEmptyPlug = false;
        for(int j=0; j<plugs.size(); j++){
            if(plugs[j] == 0){
                isEmptyPlug = true;
                plugs[j] = tool;
                break;
            }
        }
        if(isEmptyPlug){
            continue;
        }

        // 플러그를 제거해야 한다면
        // 현재 꽂혀있는 플러그 중에서 가장 나중에 사용할 플러그 제거
        int targetIdx = 0;
        int time = -1;
        for(int j=0; j<plugs.size(); j++){
            int tmp = plugs[j]; // 현재 꽂혀있는 플러그 중
            bool isFined = false;
            for(int m=i+1; m<=k; m++){ // 가장 나중에 사용할 플러그 검색
                if(tmp == v[m]){
                    isFined = true;
                    if(time < m){
                        time = m;
                        targetIdx = j;
                    }
                    break;
                }
            }
            // 다음에는 다시 사용하지 않을 플러그라면
            if(!isFined){
                targetIdx = j;
                break;
            }
        }

        plugs[targetIdx] = tool;
        answer++;
/*
        cout << "PRINT: ";
        for(int plug: plugs){
            if(plug != 0)
                cout << plug << ' ';
        }
        cout << endl;
*/
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}