#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    set<int> team1, team2;
    cin >> n;
    for (int i = 0; i < n; i++){
        int h;
        vector<int> without;
        bool from1 = false, from2 = false;
        while (cin >> h){
            if (h == 0){
                break;
            }
            if (team1.count(h) == 1){
                from1 = true;
                continue;
            }
            if (team2.count(h) == 1){
                from2 = true;
                continue;
            }
            without.push_back(h);
        }

        if (without.size() == 0 && (team1.count(i + 1) * team2.count(i + 1) == 0)){
            if (from1){
                team2.insert(i + 1);
            }else{
                team1.insert(i + 1);
            }
            continue;
        }

        if (team1.count(i + 1) == 1){
            for (int j = 0; j < without.size(); j++)
                team2.insert(without[j]);
            without.clear();
            continue;
        }
        if (team2.count(i + 1) == 1){
            for (int j = 0; j < without.size(); j++)
                team1.insert(without[j]);
            without.clear();
            continue;
        }
        team1.insert(i + 1);
        for (int j = 0; j < without.size(); j++)
                team2.insert(without[j]);
        without.clear();
    }
    cout << team1.size() << endl;
    int len = team1.size();
    for (int i = 0; i < len; i++){
        cout << *team1.begin() << ' ';
        team1.erase(team1.begin());
    }
    return 0;
}
