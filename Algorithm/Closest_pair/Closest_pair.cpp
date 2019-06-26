#include <bits/stdc++.h>
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

bool cmpx(const point& a , const point& b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

ll dis(const point& a, const point& b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

void dc(int left, int right) {
	if(left + 1 == right) return;
	int mid = left + (right - left) / 2;
	dc(left, mid);
	dc(mid, right);
	for(int i = left; i != mid; i++) {
		for(int j = mid; j != right; j++) {
			if((p[i].x - p[j].x) * (p[i].x - p[j].x) > max_heap.top()) break;
			max_heap.push(dis(p[i], p[j]));
			while(max_heap.size() > k) max_heap.pop();
		}
	}
}

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	cin >> n >> k;
	p = new point[n];
	for(int i = 0; i < k; i++) max_heap.push(INF);
	ll x, y, rx = 1 + rand() % 10, ry = 1 + rand() % 10;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		p[i].x = x * rx - y * ry;
		p[i].y = x * ry + y * rx;
	}
	sort(p, p + n, cmpx);
	dc(0, n);
	cout << max_heap.top() / (rx * rx + ry * ry) << endl;
	return 0;
}