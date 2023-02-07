#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue <int, vector<int>, greater<int>> min_q;       //  제일 작은게 top
priority_queue <int, vector<int>> max_q;                      // 큰게 top

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp, size;
        cin >> temp;
        if (max_q.size() == min_q.size())
            max_q.push(temp);
        else
            min_q.push(temp);

        // 둘다 비어있지 않고 max_q 값이 더 크다면
        if (!max_q.empty() && !min_q.empty() && max_q.top() > min_q.top()) {
            int max_var = max_q.top();  max_q.pop();
            int min_var = min_q.top();  min_q.pop();
            // 서로 스왑
            max_q.push(min_var);
            min_q.push(max_var);
        }

        cout << max_q.top() << "\n";
    }
    return 0;
}
