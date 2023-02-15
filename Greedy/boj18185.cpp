#include <bits/stdc++.h>

using namespace std;

int a[10004];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 1; i < n; i++){
        cin >> a[i];
    }


    return 0;
}

/*
    i번 공장에서 라면하나 3원
    i 공장 , i + 1 공장에서 라면 5원
    i 공장, i + 1 , i + 2 공장에서 라면 7원

    n = 3
    1 0 1 = 6

    n = 5
    1 1 1 0 2 = 13

    1 1 0 1 1 = 10
    1 1 1 1 0 = 10
    1 1 2 1 1 1 1 1  17

    
*/
