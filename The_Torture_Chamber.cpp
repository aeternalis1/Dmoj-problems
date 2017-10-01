#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,M;
  scanf("%lld %lld",&N,&M);
  int ans = 0;
  int size = ceil(sqrt(M));
  vector<long long>primes;
  bitset <20000001> sieve;
  sieve.set();
  for (int i=2;i<=size;i++){
    if (!sieve[i]){
      continue;
    }
    primes.push_back(i);
    for (int j=i;j<size;j+=i){
      sieve[j] = false;
    }
  }
  sieve.set();
  for (int i:primes){
    for (long long j=(M/i)*i;j>=N;j-=i){
      if (i==j) break;
      if (sieve[M-j]){
        sieve[M-j] = false;
      }
    }
  }
  for (int i=1;i<=M-N;i++){
    if (sieve[i]) ans += 1;
  }
  printf("%d",ans);
}
