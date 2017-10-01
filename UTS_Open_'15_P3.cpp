#include <bits/stdc++.h>
using namespace std;

// Explanation to solution here: https://dmoj.ca/problem/utso15p3/editorial

#define MOD 1000000007
#define MAXN 100001

unsigned long long funcA(int n);
unsigned long long funcB(int n);
unsigned long long funcC1(int n);
unsigned long long funcC2(int n);
unsigned long long funcD(int n);
int dp[MAXN];
unsigned long long dpA[MAXN];
unsigned long long dpB[MAXN];
unsigned long long dpC1[MAXN];
unsigned long long dpC2[MAXN];
unsigned long long dpD[MAXN];

int func(int n){
  if (dp[n]){
    return dp[n];
  }
  if (n<=0){
    return 0;
  }
  else if (n==1){
    return 1;
  }
  else{
    dp[n] = (func(n-1)+func(n-3))%MOD;
    return dp[n];
  }
}

unsigned long long funcA(int n){
  if (n<=0){
    return 0;
  }
  else if (n==1){
    return 1;
  }
  if (dpA[n]){
    return dpA[n];
  }
  else{
    dpA[n] = (funcA(n-1)%MOD+funcB(n-2)%MOD+funcC1(n-3)%MOD)%MOD;
    return dpA[n];
  }
}

unsigned long long funcB(int n){
  if (n<=0){
    return 0;
  }
  if (dpB[n]){
    return dpB[n];
  }
  else{
    dpB[n] = (funcA(n-2)%MOD+funcC2(n-3)%MOD+funcD(n-1)%MOD+funcD(n-3)%MOD)%MOD;
    return dpB[n];
  }
}

unsigned long long funcC1(int n){
  if (n<=0){
    return 0;
  }
  if (dpC1[n]){
    return dpC1[n];
  }
  else{
    dpC1[n] = (funcA(n-2)%MOD+funcC2(n)%MOD)%MOD;
    return dpC1[n];
  }
}

unsigned long long funcC2(int n){
  if (n<=0){
    return 0;
  }
  if (dpC2[n]){
    return dpC2[n];
  }
  else{
    dpC2[n] = (funcA(n-1)%MOD+funcA(n-2)%MOD+funcC2(n-3)%MOD+funcD(n-1)%MOD+funcD(n-3)%MOD)%MOD;
    return dpC2[n];
  }
}

unsigned long long funcD(int n){
  if (n<=0){
    return 0;
  }
  if (dpD[n]){
    return dpD[n];
  }
  else{
    dpD[n] = (funcA(n)%MOD+funcB(n-1)%MOD)%MOD;
    return dpD[n];
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  if (M==1){
    cout << 1;
  }
  else if (M==2){
    cout << func(N);
  }
  else {
    cout << funcA(N);
  }
  return 0;
}
