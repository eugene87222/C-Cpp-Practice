#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
const ll INF = 1e17;
int n, k;

class point {
public:
	ll x, y;
};
point *p;

priority_queue<ll> max_heap;

bool CompareX(const point& a , const point& b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

ll Distance(const point& a, const point& b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

void DivideConquer(int left, int right) {
	if(left + 1 == right) return;
	int mid = left + (right - left) / 2;
	DivideConquer(left, mid);
	DivideConquer(mid, right);
	for(int i = left; i != mid; i++) {
		for(int j = mid; j != right; j++) {
			if((p[i].x - p[j].x) * (p[i].x - p[j].x) > max_heap.top()) break;
			max_heap.push(Distance(p[i], p[j]));
			while(max_heap.size() > k) max_heap.pop();
		}
	}
}

int main(int argc, char const *argv[]) {
	/* test.in
	5 3 <- number of pairs of dots, k-th closest pair
	1 1 <- (x, y) of pair 1
	2 2 <- (x, y) of pair 2
	3 3 <- ...
	4 4
	5 5
	*/
	srand(time(NULL));
	ifstream input_file;
	input_file.open("test.in", ifstream::in);
	input_file >> n >> k;
	p = new point[n];
	for(int i = 0; i < k; i++) max_heap.push(INF);
	ll x, y, rx, ry;
	rx = 1 + rand() % 10;
	ry = 1 + rand() % 10;
	for(int i = 0; i < n; i++) {
		input_file >> x >> y;
		p[i].x = x * rx - y * ry;
		p[i].y = x * ry + y * rx;
	}
	sort(p, p + n, CompareX);
	DivideConquer(0, n);
	cout << sqrt(max_heap.top() / (rx * rx + ry * ry)) << endl;
	delete [] p;
	return 0;
}