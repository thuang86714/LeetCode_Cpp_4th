#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decrypt( const string& word ) 
{
  //TC O(n), SC O(n)-->Optimal
  //dnotq->crime
  vector<int> ascii(word.size());//asicc = {100, 0, 0, 0, 0};
  int combined_val = 1;
  for(int i = 0; i < word.size(); i++){//i = 1
    if(i == 0){
      int first = word[i] - 'a' + 97 -1;//d - 'a' 
      ascii[i] = first;//asicc[0] = 100
      continue;
    }
    int val = word[i] - 'a' + 97;//val = 110
    //find the range 97 *(i + 1) <= x <= 123*(i + )1
    int lower = 97 * (i + 1);//lower = 97*2 = 194
    int upper = 122* (i + 1);//uppper = 123*2 = 246
    int j = 1;//j = 1
    vector<int> candidate;// candidate = {214, 240}
    while(val + j*26 <= upper){//val = 110 + 26*j-->266
      if(val + j*26 >= lower){//240 >= 194
        candidate.push_back(val + j*26);
      }
      j++;
    }
    
    combined_val += ascii[i -1];//100
    
    for(int n: candidate){//214, 240
      n -= combined_val;//114, 140
      if(97 <= n && n <= 122){//114
        ascii[i] = n;//114
        break;
      }
    }
  }
  
  string res = "";
  //cout<< ascii.size();
  for(int num: ascii){// asicc = {100, 114, 105, 109, 101}
      res += (char)num;//res = crime
  }
  return res;
  
}

int main() {
  return 0;
}

