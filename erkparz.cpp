#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
 
using namespace std;
 
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
}
 
vector<int> brr;
vector <bool> dp[1000];
int main() 
{
  //freopen("pageant.in", "r", stdin);
  //freopen("pageant.out", "w", stdout);
  int a1 , b;
  cin >> a1 >> b;
  int qanak = 0;
  int n = b+1;
  int *a = new int[n + 1];
  for (int i = 0; i <= n; i++)
    a[i] = i;
  for (int i = 2; i * i <= n; i++){
    if (a[i])
      for (int j = i*i; j <= n; j += i)
        a[j] = 0;
  }
  for (int i = 2; i < n; i++) {
    if (a[i]) {
      brr.push_back(a[i]);
    }
  }
  for(int i = a1 ; i <= b; i++){
    if(i % 2 == 0) {
      qanak++;
    }
    else {
      for(int l = 0; l <= brr.size(); l++){
        if(i-2 == brr[l]) {
          qanak++;
          break;
        }
        else if(brr[l] > i-2)
          break;
      }
    }
  }
  if(a1 != 2)
    cout << qanak;
  else
    cout << qanak-1;
} 
