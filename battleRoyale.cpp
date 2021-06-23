#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nax=105,mod=1e9+7;
int mul(int x,int y)
{
    return x*y%mod;
}
int expo(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
        res=mul(res,a);
        a=mul(a,a);
        b>>=1;
    }
    return res;
}
int inv(int x)
{
    return expo(x,mod-2);
}
const int N = 1e2+5;
vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
vector<vector<vector<bool>>> vis(N, vector<vector<bool>>(N, vector<bool>(N, 0)));
int n = 100;
int doit(int i=n, int j=0, int k=n){
    if(vis[i][j][k] == 0){
        dp[i][j][k] = 0;
        if(i == 1){

        }
        else if(k == 0 and j > 0){
            doit(j, 0, j);
            (dp[i][j][k] = (dp[j][0][j]+1)%mod)%=mod;
        }
        else {
            if(i - j - k > 0){
                doit(i, j+1, k-1);
                (dp[i][j][k] += (i-j-k)*dp[i][j+1][k-1]%mod*inv(i-1)%mod)%=mod;
            }
            if(j > 0){
                doit(i, j, k-1);
                (dp[i][j][k] += (j)*dp[i][j][k-1]%mod*inv(i-1)%mod)%=mod;
            }
            if(k-1 > 0){
                doit(i, j+1, k-2);
                (dp[i][j][k] += (k-1)*dp[i][j+1][k-2]%mod*inv(i-1)%mod)%=mod;
            }
        }
        vis[i][j][k] = 1;
    }
    return dp[i][j][k];
}

void solve(){
    cin >> n;
    cout << doit(n, 0, n) << "\n";
    return ;
}

main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int c=1; c <= T; c++){
        solve();
    }
    return 0;
}
