#include <iostream>
#include <queue>
 
using namespace std;
//우선순위 큐 - 가장 적은 시간부터 우선순위
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> q;  // 누적 시간, 현재 위치
bool v[100001];  //들른 곳 표시
int result_time, n, k;
 
void hide_and_seek() {
    v[n] = 1;
    q.push(make_pair(0, n));
    result_time = 0;
 
    while (!q.empty()) {
        int pos = q.top().second;
        int time = q.top().first;
        q.pop();
 
        if (pos == k) {
            result_time = time;
            return;
        }
 
        if (pos * 2 <= 100000 && v[pos * 2] == 0) {
            q.push(make_pair(time, pos * 2));
            v[pos * 2] = 1;
        }
        if (pos - 1 >= 0 && v[pos - 1] == 0) {
            q.push(make_pair(time + 1, pos - 1));
            v[pos - 1] = 1;
        }
        if (pos + 1 <= 100000 && v[pos + 1] == 0) {
            q.push(make_pair(time + 1, pos + 1));
            v[pos + 1] = 1;
        }
    }
}
 
int main(void) {
    cin >> n >> k;
 
    for (int i = 0; i <= 100000; i++)
        v[i] = 0;
 
    hide_and_seek();
    cout << result_time << '\n';
}  