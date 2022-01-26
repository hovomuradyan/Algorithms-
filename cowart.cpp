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

int brr[101][101];
int grr[101][101];
int main() {
  freopen("cowart.in", "r", stdin);
  freopen("cowart.out", "w", stdout);
  int n, x, y,count = 0;
  cin >> n;
  char arr[101][101];
  for(int i = 0; i<n; i++){
    for(int l = 0; l<n; l++){
      cin >> arr[i][l];
    }
  }
  queue<pair<int , int> > q;
  for(int i = 0; i<n;i++) {
    for(int l = 0; l < n;l++) {
      if(brr[i][l] == 0) {
        q.push(make_pair(i,l));
        count++;
        while (!q.empty()) {
          x = q.front().first;
          y = q.front().second;
          q.pop();
          if (x - 1 >= 0 && arr[x - 1][y] == arr[x][y] && brr[x-1][y] == 0) {
            brr[x - 1][y] = count;
            q.push(make_pair(x - 1, y));
          }
          if (y + 1 < n && arr[x][y + 1] == arr[x][y] && brr[x][y+1] == 0) {
            brr[x][y + 1] = count;
            q.push(make_pair(x, y + 1));
          }
          if (x + 1 < n && arr[x + 1][y] == arr[x][y] && brr[x+1][y] == 0) {
            brr[x + 1][y] = count;
            q.push(make_pair(x + 1, y));
          }
          if (y - 1 >= 0 && arr[x][y - 1] == arr[x][y] && brr[x][y-1] == 0) {
            brr[x][y - 1] = count;
            q.push(make_pair(x, y - 1));
          }
        }
      }
    }
  }
  cout << count << " ";
  count = 0;
  for(int i = 0; i <n;i++){
    for(int l = 0; l<n;l++){
      if(arr[i][l] == 'G')
        arr[i][l] = 'R';
    }
  }
  for(int i = 0; i<n; i++){
    for(int l = 0; l<n; l++){
      if(grr[i][l] == 0) {
        q.push(make_pair(i,l));
        count++;
        while (!q.empty()) {
          x = q.front().first;
          y = q.front().second;
          q.pop();
          if (x - 1 >= 0 && arr[x - 1][y] == arr[x][y] && grr[x-1][y] == 0) {
            grr[x - 1][y] = count;
            q.push(make_pair(x - 1, y));
          }
          if (y + 1 < n && arr[x][y + 1] == arr[x][y] && grr[x][y+1] == 0) {
            grr[x][y + 1] = count;
            q.push(make_pair(x, y + 1));
          }
          if (x + 1 < n && arr[x + 1][y] == arr[x][y] && grr[x+1][y] == 0) {
            grr[x + 1][y] = count;
            q.push(make_pair(x + 1, y));
          }
          if (y - 1 >= 0 && arr[x][y - 1] == arr[x][y] && grr[x][y-1] == 0) {
            grr[x][y - 1] = count;
            q.push(make_pair(x, y - 1));
          }
        }
      }
    }
  }
  cout << count;
}
