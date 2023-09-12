#include <iostream>

using namespace std;

// p는 pi의 주솟값
// q는 pj의 주솟값
void foo(int** p, int** q) {
   int* t = *p; // int* t = pi = &i
   *p = *q; // pi = pj
   *q = t;
   **p = 3;
}

int main() {
   cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

   int i = 1;
   int j = -1;
   int* pi = &i;
   int* pj = &j;
   foo(&pi, &pj);

   cout << *pi << ' ' << *pj;

   return 0;
}