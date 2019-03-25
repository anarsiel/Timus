#include <bits/stdc++.h>

using namespace std;

vector<int> v;

vector<vector<int> > tree;
void palament(int l, int r){      //границы включительно
	if (l > r) {
		return;
	}
	if (l == r){
		tree[l] = {-1, -1};
		return;
	}
	int root = v[r];
	int index = l;
	while (v[index] < root){
	 	index++;
	}

	if (index == l) {
		tree[r] = {-1, r - 1};
	} else if (index == r) {
 		tree[r] = {index - 1, -1};
 	} else {	
		tree[r] = {index - 1, r - 1};
	}

	palament(l, index - 1);
	palament(index, r - 1);
	return;
}

void make_me_an_answer(int vertex){
	if (vertex == -1){
	 	return;
	}
	make_me_an_answer(tree[vertex][1]);
	make_me_an_answer(tree[vertex][0]);

	cout << v[vertex] << endl;
}

int main(){
	int n;
	cin >> n;

	tree.resize(n);

	for (int i = 0; i < n; i++){
	 	int h;
	 	cin >> h;
	 	v.push_back(h);
	}

    palament(0, n - 1);
    make_me_an_answer(n - 1);
 	return 0;
}