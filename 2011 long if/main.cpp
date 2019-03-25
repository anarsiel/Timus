#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
    	int h;
    	cin >> h;
    	v.push_back(h);
    }
    sort(v.begin(), v.end());

    int cnt = 1;
   	while (next_permutation(v.begin(), v.end())){
   	 	cnt++;
   	 	if (cnt == 23)
   	 		break;
   	}
   	if (cnt >= 6)
   		cout << "Yes";
   	else
   		cout << "No";
 	return 0;
}