class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for(auto obstacle : obstacles) 
            st.insert({obstacle[0], obstacle[1]});
        // 0 -> north, 1 -> east, 2 -> south, 3 -> west
        int dir = 0, posx = 0, posy = 0, ans = 0;
        for(auto command : commands) {
            if(command == -1) {
                dir = (dir + 1)%4;
            } else if (command == -2) {
                dir = (dir + 4 - 1)%4;
            } else {
                if(dir == 0) {
                    for(int i = 1; i <= command; i++) {
                        if(st.find({posx, posy + 1}) != st.end()) break;
                        posy++;
                    }
                } else if (dir == 1) {
                    for(int i = 1; i <= command; i++) {
                        if(st.find({posx + 1, posy}) != st.end()) break;
                        posx++;
                    }
                } else if (dir == 2) {
                    for(int i = 1; i <= command; i++) {
                        if(st.find({posx, posy - 1}) != st.end()) break;
                        posy--;
                    }
                } else {
                    for(int i = 1; i <= command; i++) {
                        if(st.find({posx - 1, posy}) != st.end()) break;
                        posx--;
                    }
                }
            }
            ans = max(ans, (posx*posx) + (posy*posy));
        }
        return ans;
    }
};