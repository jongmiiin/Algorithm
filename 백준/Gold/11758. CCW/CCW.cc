#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x, y;
};

int ccw(Point a, Point b, Point c);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << ccw(a, b, c);
	return 0;
}

int ccw(Point a, Point b, Point c){
	Point ab, bc;
	ab.x = b.x - a.x; ab.y = b.y - a.y;
	bc.x = c.x - b.x; bc.y = c.y - b.y;
	int result = ab.x*bc.y - ab.y*bc.x;
	if(result>0) return 1;
	else if(result==0) return 0;
	else return -1;
}