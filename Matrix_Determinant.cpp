#include <bits/stdc++.h>
using namespace std;

/*
Most of my solution was based off of the following website:
http://www.sosmath.com/matrix/determ1/determ1.html

The insight to use Fermat's little theorem to determine the pivot by which to modify each element in the row was provided and clarified by jeffreyxiao (many thanks to him)
*/

#define maxn 501
long long mod = 1000000007;

long long pow(long long a, long long b){
  if (b==0) return 1;
  if (b==1) return a;
  if (b%2==0) return pow(a*a%mod,b/2);
  return a*pow(a*a%mod,b/2)%mod;
}

int main(){
  int N;
  long long mat[maxn][maxn];
  scanf("%d",&N);
  bool neg = false;
  int curr = 0;
  long long sub;
  long long ans = 1;
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      scanf("%lld",&mat[i][j]);
      mat[i][j] += mod;
      mat[i][j] %= mod;
    }
  }
  for (int i=0;i<N;i++){
    if (mat[i][0]>mat[curr][0]){
      curr = i;
    }
  }
  if (curr){
    swap(mat[curr],mat[0]);
    neg = neg^1;
  }
  for (int i=1;i<N;i++){
    curr = i;
    for (int j=i+1;j<N;j++){
      if (mat[j][i] > mat[curr][i]) curr=j;
    }
    if (curr != i){
      swap(mat[curr],mat[i]);
      neg = neg^1;
    }
    for (int j=i;j<N;j++){
      sub = (mat[j][i-1]*pow(mat[i-1][i-1],mod-2))%mod;
      for (int k=i-1;k<N;k++){
        mat[j][k] = (mat[j][k]-sub*mat[i-1][k])%mod;
      }
    }
  }
  for (int i=0;i<N;i++){
    ans = ans*mat[i][i]%mod;
  }
  if (neg) ans = -ans;
  printf("%lld",(ans+mod)%mod);
}

