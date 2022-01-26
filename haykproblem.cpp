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
 
using namespace std;
 
//unsigned char da[3] = {132, 128, 0};
//unsigned char net[4] = {141, 133, 146, 0};
 
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
    // Check from 2 to sqrt n
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
 
int main()
{
    //freopen("lineup.in", "r", stdin);
    //freopen("lineup.out", "w", stdout);
    long long n; cin >> n;
    n/=6;
    string arr[100];
    vector<int> brr;
    vector<int> brr1;
    for(long long l = 0; l<n;l++) {
        for (long long i = 0; i < 6; i++)
            cin >> arr[i];
        sort(arr, arr + 6);
        long long minsum = 1000000000;
        do {
            if (abs(stoi(arr[0] + arr[1] + arr[2]) - stoi(arr[3] + arr[4] + arr[5])) < minsum)
                minsum = abs(stoi(arr[0] + arr[1] + arr[2]) - stoi(arr[3] + arr[4] + arr[5]));
        } while (next_permutation(arr, arr + 6));
        brr.push_back(minsum);
    }
    for(long long i = 0; i<brr.size(); i++){
        brr1.push_back(brr[i]);
    }
    for(long long i = 0; i<brr.size(); i++){
        brr1.push_back(brr[i]);
    }
    sort(brr.begin(), brr.end());
    for(long long i = 0; i < brr.size();i++){
        for(long long l = 0; l < brr1.size(); l++){
            if(brr[i] == brr1[l]){
                cout<<l +1<< " ";
                brr1[l] = -1;
                brr[i] = -1;
                break;
            }
        }
    }
    //cout.setf(ios::fixed);
    //cout.precision(6);
} 
