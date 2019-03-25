#include <bits/stdc++.h>

using namespace std;

struct point{
  	double x, y;

  	point(){}

  	point(double x, double y){
  	 	this->x = x;
  	 	this->y = y;
  	}

  	void read(){
  	 	cin >> x >> y;
  	}
        
  	double len(){
  	 	return sqrt(x * x + y * y);
  	}
};point operator -(point a, point b){
     return point(a.x - b.x, a.y - b.y);
}
                      
int main(){
	#ifdef LocalHost
    freopen("rope.in", "r", stdin);
	freopen("rope.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cout.precision(2);

	int n; 
	cin >> n;
	long double r;
	cin >> r;

	vector<point> v;
	for (int i = 0; i < n; i++){
	 	point p;
	 	p.read();
	 	v.push_back(p);
	}
	v.push_back(v[0]);
	long double answ = 0;
	for (int i = 0; i < n; i++){
	    answ += (v[i] - v[i + 1]).len();
	}
	cout << fixed << 3.14159265359 * 2 * r + answ;
 	return 0;
}