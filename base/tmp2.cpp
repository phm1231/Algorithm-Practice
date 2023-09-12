#include <iostream>
#include <ctime>

using namespace std;

int a[1000][1000];
int b[1000][1000];
int c[1000][1000];

int main(){
   for(int i=0; i<1000; i++){
      for(int j=0; j<1000; j++){
         a[i][j] = i + j;
         b[i][j] = i - j;
         c[i][j] = i * j;
      }
   }

   volatile long long answer = 0;
   clock_t start = clock();
   for(int i=0; i<1000; i++){
      for(int k=0; k<1000; k++){
         for(int j=0; j<1000; j++){
            answer += b[i][k] * c[k][j];
         }
      }
   }
   clock_t end = clock();
   cout << "i, k, j time: " << (double)(end - start) - CLOCKS_PER_SEC << endl;
}