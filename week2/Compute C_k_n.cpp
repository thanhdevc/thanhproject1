#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const int MOD = (int) 1e9 + 7;

/*ll kCn(int k, int n){
    if ( k == 0 || k == n ){
        return 1;
    }
    else return (kCn(k-1, n-1) + kCn(k, n-1)) % MOD;
}
*/

long long C[1001][1001];

void kCn(){
    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || i == j){
                C[i][j] = 1; 
            }
            else{
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                C[i][j] %= MOD;
            }
        }
    }
}


int main(){
    kCn();
    int n,k; 
    cin >> k >> n;
    cout << C[n][k] << endl;
    return 0;
}
