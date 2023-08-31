#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;


void init();
void input();
void solve();

int n, k;
vector<int> v;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;

    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve()
{

    int answer = 0;
    vector<bool> flaged(101, false);
    vector<pair<int, int> > flug;

    for(int i=0; i<v.size(); i++){
        int item = v[i];
        int next = 101;

        for(int j=i+1; j<v.size(); j++){
            if(item == v[j]){
                next = j;
                break;
            }
        }
        // 이미 콘센트에 꽂혀 있음
        if(flaged[item]){
            // 콘센트를 순회하며 똑같은 것 업데이트
            for(int j=0; j<flug.size(); j++){
                if(flug[j].first == item){
                    flug[j].second = next;
                    break;
                }
            }
        }
        // 자리가 있음
        else if(flug.size() < n){
            flug.push_back(make_pair(item, next));
            flaged[item] = true;
        }
        // 콘센트에 꽂혀 있지 않음
        else{
            answer++;
            int targetNext = -1; // next가 가장 많으 놈
            int targetItem, targetIdx;

            // 콘센트를 순회하며 next가 가장 큰 놈 찾기
            for(int j=0; j<flug.size(); j++){
                if(targetNext < flug[j].second){
                    targetNext = flug[j].second;
                    targetItem = flug[j].first;
                    targetIdx = j;
                }
            }

            // 뽑기
            flaged[targetItem] = false;
            flug[targetIdx].first = item;
            flug[targetIdx].second = next;
            flaged[item] = true;

        }
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