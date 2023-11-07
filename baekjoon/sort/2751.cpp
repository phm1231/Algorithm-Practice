#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

void bubbleSort();
void selecionSort();
void insertionSort();
void mergeSort(int left, int right);
void merge(int left, int right);
void quickSort(int left, int right);

int n;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    // bubbleSort();
    // selecionSort();
    // insertionSort();
    // mergeSort(0, n-1);
    quickSort(0, n-1);
    for(int item: v) cout << item << "\n";
}

// 인접한 두 원소를 반복적으로 비교한다.
void bubbleSort(){
    for(int i=0; i<v.size() - 1; i++){
        for(int j=0; j<v.size() - 1 - i; j++){
            if(v[j] > v[j+1]){
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

void insertionSort(){
    // 0번 값은 정렬이 되어있다.
    for(int i=1; i<n; i++){
        int value = v[i];
        int j;
        // 정렬된
        for(j=i-1; j>=0 && v[j] > value; j--){
            v[j+1] = v[j];
        }
        v[j+1] = value;
    }
}

void selecionSort(){
    for(int i=0; i<v.size(); i++){
        int minIdx = i;
        // 정렬되지 않은 데이터들에 대해 가장 작은 데이터를 찾는다.
        for(int j = i+1; j<v.size(); j++){
            if(v[minIdx] > v[j]){
                minIdx = j;
            }
        }
        // 가장 앞의 데이터와 교환한다.
        int tmp = v[minIdx];
        v[minIdx] = v[i];
        v[i] = tmp;
    }
}

void mergeSort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        // 배열을 둘로 나눈다.
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        // 합친다.
        merge(left, right);
    }
}

void merge(int left, int right){
    int mid = (left + right) / 2;
    int i = left; // 좌측 배열의 시작 인덱스
    int j = mid + 1; // 우측 배열의 시작 인덱스
    int k = left; // 결과 전용 인덱스

    // 정렬 결과를 임시 저장
    vector<int> tmp(right + 1, 0);

    // 두 개의 배열을 합치면서 정렬한다.
    while(i <= mid && j <= right){
        if(v[i] > v[j]) tmp[k++] = v[j++];
        else tmp[k++] = v[i++];
    }

    // 잔여 값 처리
    while(i <= mid) tmp[k++] = v[i++];
    while(j <= right) tmp[k++] = v[j++];

    // 정렬 결과를 본 배열에 복사
    for(int idx=left; idx<=right; idx++) v[idx] = tmp[idx];
}

void quickSort(int left, int right){
    if(left >= right) return;

    int pivot = left;
    int i = pivot + 1; // 왼쪽 출발
    int j = right; // 오른쪽 출발

    while(i <= j){
        // i의 좌측은 전부 Pivot보다 작은 값으로 만든다.
        while(i <= right && v[i] <= v[pivot]) i++;
        // j의 우측은 전부 Pivot보다 큰 값으로 만든다.
        while(j > left && v[j] >= v[pivot]) j--;

        if(i > j){
            int tmp = v[j];
            v[j] = v[pivot];
            v[pivot] = tmp;
        }
        else{
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    }
    quickSort(left, j-1);
    quickSort(j+1, right);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}