class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, pair<int, char>>> vec;

        // Combine positions, healths, and directions into one vector of tuples
        for (int i = 0; i < n; ++i) {
            vec.push_back({positions[i], {healths[i], directions[i]}});
        }
        
        // Sort the vector by positions
        sort(vec.begin(), vec.end());

        stack<pair<int, pair<int, char>>> st;
        for (int i = 0; i < n; ++i) {
            auto currRobot = vec[i];
            while (!st.empty() && st.top().second.second == 'R' && currRobot.second.second == 'L') {
                auto topRobot = st.top();
                st.pop();
                
                // If top robot's health is greater
                if (topRobot.second.first > currRobot.second.first) {
                    topRobot.second.first -= 1;
                    st.push(topRobot);
                    currRobot.second.first = 0;
                    break;
                } 
                // If current robot's health is greater
                else if (topRobot.second.first < currRobot.second.first) {
                    currRobot.second.first -= 1;
                } 
                // If both robots' health are equal
                else {
                    currRobot.second.first = 0;
                    break;
                }
            }
            if (currRobot.second.first > 0) {
                st.push(currRobot);
            }
        }

        // Create a map to store final healths by original positions
        unordered_map<int, int> positionHealthMap;
        while (!st.empty()) {
            auto robot = st.top();
            st.pop();
            positionHealthMap[robot.first] = robot.second.first;
        }

        // Prepare the result array based on the original order
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (positionHealthMap.find(positions[i]) != positionHealthMap.end()) {
                result.push_back(positionHealthMap[positions[i]]);
            }
        }
        
        return result;
    }
};
