#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;
int startm, startd, endm, endd;
int start = 300;
int end2 = 301;
int result, max_end, max_index;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> startm >> startd >> endm >> endd;

		if ((startm * 100 + startd) < 301) {
			startm = 3;
			startd = 1;
		}

		if ((endm * 100 + endd) > 1130) {
			endm = 12;
			endd = 1;
		}

		v.push_back({ startm * 100 + startd, endm * 100 + endd });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i].first > start && v[i].first <= end2) {
			if (max_end < v[i].second) {
				max_end = v[i].second;
				max_index = i;
			}
			if (v[i].second == 1201) {
				++result;
				end2 = max_end;
				break;
			}
			continue;
		}
		else {
			if (end2 >= max_end) break;

			++result;
			start = end2;
			end2 = max_end;
			--i;
		}
	}

	if (end2 == 1201)
		cout << result << "\n";
	else
		cout << 0 << "\n";

}

