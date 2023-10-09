#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> point;
typedef pair<double, pair<double, double> > dot;

int n;
double x, y;
vector<dot> dots;

int convexhull[100001];
int top;

int ccw(point a, point b, point c);
double getdist(dot A, dot B);
bool setdots(dot A, dot B);
void setslope(dot P0);
void ConvexHull();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	dots.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		dots[i].second.first = y;
		dots[i].second.second = x;
	}
	sort(dots.begin(), dots.end());
	setslope(dots[0]);
	convexhull[top++] = 0;
	convexhull[top++] = 1;
	ConvexHull();
	cout << top;
}

int ccw(point a, point b, point c) {
	point ab;
	point bc;
	ab.first = b.first - a.first; 
	ab.second = b.second - a.second;
	bc.first = c.first - b.first;
	bc.second = c.second - b.second;
	double ret = ab.first*bc.second - ab.second*bc.first;
	ret = -ret;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

double getdist(dot A, dot B) {
	return sqrt(pow(A.second.first - B.second.first, 2.0) + pow(A.second.second - B.second.second, 2.0));
}

bool setdots(dot A, dot B) {
	int cw = ccw(dots[0].second, A.second, B.second);
	if (cw > 0) return 1;
	if (cw < 0) return 0;
	else if (A.first < B.first) return 1;
	return 0;
}

void setslope(dot P0) {
	for (int i = 1; i < n; i++) 
		dots[i].first = getdist(P0, dots[i]);
	sort(dots.begin() + 1, dots.end(), setdots);
}

void ConvexHull() {
	for (int i = 2; i < n; i++) {
		while (top >= 2 && ccw(dots[convexhull[top-2]].second, dots[convexhull[top - 1]].second, dots[i].second) <= 0) top--;
		convexhull[top++]=i;
	}
}