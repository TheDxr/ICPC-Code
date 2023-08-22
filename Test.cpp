#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int n, m, a, b;
struct Team{
    int id;
    vector<int> players;
};
vector<bool> TeamHasA;
vector<bool> TeamHasB;
unordered_set<string> st;
bool backtrack(vector<Team>& teams, vector<bool>& visited, int start, int currentSize, vector<int>& currentTeam, bool &hasA, bool& hasB){

    if(hasA && hasB && currentSize == m){
        for(int id : currentTeam){
            cout << id + 1 << " ";
        }
        cout << endl;
        return true;
    }
	//判断是否是失败状态
    vector<int> all1;
    for(int id: currentTeam){
        for(int num : teams[id].players){
            all1.push_back(num);
        }
    }
    sort(all1.begin(),all1.end());
    string s;
    for(auto num: all1){
        s += to_string(num);
    }
    if(st.find(s) != st.end()) return false;
	//
    for(size_t i = start; i < teams.size(); i++){
        if(visited[i] == true) continue;
        if(!visited[i] && currentSize + (int)teams[i].players.size() <= m){
            bool teamHasA = TeamHasA[i];
            bool teamHasB = TeamHasB[i];
            if((hasA && teamHasA) || (hasB && teamHasB)) continue;
            visited[i] = true;
            currentTeam.push_back(i);
            bool newHasA = hasA || teamHasA;
            bool newHasB = hasB || teamHasB;
            if(backtrack(teams, visited, i + 1, currentSize + (int)teams[i].players.size(),currentTeam, newHasA, newHasB)){
                return true;
            }
			//记录失败状态
            vector<int> all;
            for(int id: currentTeam){
                for(int num : teams[id].players){
                    all.push_back(num);
                }
            }
            sort(all.begin(),all.end());
            string s;
            for(auto num: all){
                s += to_string(num);
            }
            st.insert(s);
			//
            visited[i] = false;

            currentTeam.pop_back();
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> a >> b;
    vector<Team> teams;
    vector<bool> matched(n, false);
    TeamHasA.resize(n);
    TeamHasB.resize(n);

    for(int i = 0; i < n; i++){
        Team team;
        int t;
        cin >> t;
        team.id = i;
        for(int j = 0; j < t; j++){
            int player;
            cin >> player;
            if(player == a) TeamHasA[i] = true;
            if(player == b) TeamHasB[i] = true;
            team.players.push_back(player);
        }
        teams.push_back(team);
    }

    for(int i = 0 ;i < n; i++){
        if(matched[i] == true) continue;
        vector<int> cur;
        bool a = false;
        bool b = false;
        backtrack(teams, matched,i,0, cur, a, b);
    }

    return 0;

}
