#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

bool cmp(const point& a, const point& b) {

	if (a.y != b.y) {	//y좌표 다르면 y좌표 증가하는 순으로 정렬
		return a.y < b.y;
	}

	else {	//y좌표 같으면 x좌표 증가하는 순으로 정렬
		return a.x < b.x;
	}

}

int main() {
	int n; //점의 개수

	cin >> n;

	vector<point> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}
}