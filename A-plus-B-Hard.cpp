#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  string a;
  string b;
  for (int i=0;i<N;i++){
    vector<int>output;
    cin >> a >> b;
    bool neg1 = false;
    bool neg2 = false;
    int len1 = 0;
    int len2 = 0;
    len1 = a.size();
    len2 = b.size();
    if ((char)a[0]=='-'){
      neg1 = true;
    }
    if ((char)b[0]=='-'){
      neg2 = true;
    }
    bool change = false;
    for (int j=0;j<len1;j++){
      if (a[0]=='0' && !neg1){
        a.erase(0,1);
      }
      else if (a[1]=='0'&&neg1){
        a.erase(1,1);
      }
      else{
        break;
      }
    }
    len1 = a.size();
    len2 = b.size();
    if (len1-neg1<len2-neg2){
      swap(len1,len2);
      swap(neg1,neg2);
      swap(a,b);
    }
    else if (len1-neg1==len2-neg2){
      if (neg1&&neg2){
        for (int j=1;j<len1;j++){
          if (a[j]<b[j]){
            change = true;
            break;
          }
          else if (a[j]>b[j]){
            break;
          }
        }
      }
      else if (neg1){
        for (int j=0;j<len2;j++){
          if (a[j+1]<b[j]){
            change = true;
            break;
          }
          else if (a[j+1]>b[j]){
            break;
          }
        }
      }
      else if (neg2){
        for (int j=0;j<len1;j++){
          if (a[j]<b[j+1]){
            change = true;
            break;
          }
          else if (a[j]>b[j+1]){
            break;
          }
        }
      }
      else{
        for (int j=0;j<len1;j++){
          if (a[j] < b[j]){
            change = true;
            break;
          }
          else if (a[j]>b[j]){
            break;
          }
        }
      }
    }
    if (change){
      swap(len1,len2);
      swap(neg1,neg2);
      swap(a,b);
    }
    int carry = 0;
    for (int j=1;j<=len1-neg1+1;j++){
      if (j > len1-neg1){
        output.push_back(abs(carry));
        break;
      }
      if (j > len2-neg2){
        output.push_back(abs((carry+(a[len1-j]-'0'))%10));
        if (carry+(a[len1-j]-'0')>9){
          carry = 1;
        }
        else{
          carry = 0;
        }
        continue;
      }
      if (neg1==neg2){
        output.push_back((carry+(a[len1-j]-'0')+(b[len2-j]-'0'))%10);
        if (carry+(a[len1-j]-'0')+(b[len2-j]-'0') > 9){
          carry = 1;
        }
        else{
          carry = 0;
        }
      }
      else{
        /*if (neg1){
          output.push_back(abs((carry-(a[len1-j]-'0')+(b[len2-j]-'0'))%10));
          if (carry-(a[len1-j]-'0')+(b[len2-j]-'0')<0){
            carry = -1;
          }
          else{
            carry = 0;
          }
        }*/
        //cout << carry << " " << a[len1-j]-'0' << " " << b[len2-j]-'0' << endl;
        if (carry+(a[len1-j]-'0')-(b[len2-j]-'0')<0){
          if (abs((carry+(a[len1-j]-'0')-(b[len2-j]-'0'))%10)==0){
            output.push_back(0);
          }
          else{
            output.push_back(10-abs((carry+(a[len1-j]-'0')-(b[len2-j]-'0'))%10));
            carry = -1;
          }
        }
        else{
          output.push_back(abs((carry+(a[len1-j]-'0')-(b[len2-j]-'0'))%10));
          carry = 0;
        }
      }
    }
    while (!output.empty()){
      if (output[output.size()-1]==0){
        output.erase(output.begin()+output.size()-1);
      }
      else{
        break;
      }
    }
    if (output.size()==0){
      cout << 0;
    }
    else if (neg1){
      cout << "-";
    }
    for (int j=output.size()-1;j>=0;j--){
      cout << output[j];
    }
    cout << endl;
  }
}
