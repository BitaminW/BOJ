#include <bits/stdc++.h>

using namespace std;

string word, ans;
int cnt;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 공백까지 포합해서 입력 받는다.
    getline(cin, word);
    getline(cin, ans);


    int len = word.length();    // 총 단어의 길이
    int len2 = ans.length();    // 찾을 단어의 길이

    // 총 단어의 길이 - 찾을 단어의 길이까지만 반복하면 된다.
    for(int i = 0; i <= len - len2;){
        string pattern = word.substr(i, len2);  // 잘라낸다

        if(pattern == ans){     
            cnt++;          
            i += len2;              // 패턴이 일치하다면 i + 패턴 길이만큼 넘어간다.
        }else{  
            i++;                    // 아니라면 다음문자부터 다시 시작한다.
        }

    } 

    cout << cnt;
    
    return 0;
}
