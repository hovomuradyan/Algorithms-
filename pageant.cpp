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

//Global arrays
int arr[51][51];
char brr[51][51];
int grr[51][51];

int main()
{
  //freopen("pageant.in", "r", stdin);
  //freopen("pageant.out", "w", stdout);
  int n , m, x, y;
  char count = '0';
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int l = 0; l < m; l++){
      cin >> brr[i][l];
    }
  }
  queue<pair<int,int> > q;
  for(int i = 0; i < n; i++){
    for(int l = 0; l < m;l++){
      if(brr[i][l] == 'X') {
        count++;
        q.push(make_pair(i,l));
        while(!q.empty()){
          x = q.front().first;
          y = q.front().second;
          q.pop();
          brr[x][y] = count;
          if(x-1 >= 0 && brr[x-1][y] == 'X') {
            brr[x - 1][y] = count;
            q.push(make_pair(x-1,y));
          }
          if(y+1 <m && brr[x][y+1] == 'X') {
            brr[x][y + 1] = count;
            q.push(make_pair(x,y+1));
          }
          if(x+1 < n && brr[x+1][y] == 'X') {
            brr[x + 1][y] = count;
            q.push(make_pair(x+1,y));
          }
          if(y-1 >=0 && brr[x][y-1] == 'X') {
            brr[x][y - 1] = count;
            q.push(make_pair(x,y-1));
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int l = 0; l < m; l++){
      if(brr[i][l] == '1') {
        q.push(make_pair(i,l));
        while(!q.empty()){
          x = q.front().first;
          y = q.front().second;
          q.pop();
          if(y-1 >= 0 && brr[x][y-1] == '.' && (arr[x][y-1] > arr[x][y]+1 || arr[x][y-1] == 0)){
            arr[x][y-1] = arr[x][y]+ 1;
            q.push(make_pair(x,y-1));
          }
          if(x-1 >= 0 && brr[x-1][y] == '.' && (arr[x-1][y] > arr[x][y]+1 || arr[x-1][y] == 0)){
            arr[x-1][y] = arr[x][y]+1;
            q.push(make_pair(x-1,y));
          }
          if(y+1 < m && brr[x][y+1] == '.' && (arr[x][y+1] > arr[x][y]+1 || arr[x][y+1] == 0)) {
            arr[x][y+1] = arr[x][y]+1;
            q.push(make_pair(x,y+1));
          }
          if(x+1 < n && brr[x+1][y] == '.' && (arr[x+1][y] > arr[x][y]+1 || arr[x+1][y] == 0)) {
            arr[x+1][y] = arr[x][y]+1;
            q.push(make_pair(x+1,y));
          }
          if(arr[x][y] > 2*m){
            while(!q.empty())
              q.pop();
          }
          count++;
        }
      }
    }
  }
  int patasxan = 2 * m;
  for(int i = 0; i < n; i++) {
    for(int l = 0; l < m;l++) {
      if(arr[i][l] == 0 && brr[i][l] == '.'){
        arr[i][l] = 511;
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int l = 0; l < m; l++){
      if(brr[i][l] == '2'){
        if(l-1 >= 0 && arr[i][l-1] < patasxan && brr[i][l-1] == '.') {
          patasxan = arr[i][l-1];
        }
        if(i-1 >= 0 && arr[i-1][l] < patasxan && brr[i-1][l] == '.') {
          patasxan = arr[i-1][l];
        }
        if(l+1 < m && arr[i][l+1] < patasxan && brr[i][l+1] == '.') {
          patasxan = arr[i][l + 1];
        }
        if(i+1 < n && arr[i+1][l] < patasxan && brr[i+1][l] == '.') {
          patasxan = arr[i + 1][l];
        }
      }
    }
  }
  /* // Code debuging
  for(int i = 0; i<n;i++){
    for(int l = 0; l <m;l++){
      cout << brr[i][l];
    }
    cout << endl;
  }
   */
  cout << patasxan;
}
