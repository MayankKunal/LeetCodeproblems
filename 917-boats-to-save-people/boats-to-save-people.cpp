class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size()-1;
        int count = 0;

        while(left<=right) {
            if(people[right] == limit) { // heaviest person goes alone
                count++;
                right--;
            }
            else if(people[left] + people[right] > limit) { // heaviest person goes alone
                count++;
                right--;
            }
            else {
                // both person goes in a single boat
                count++;
                left++;
                right--;
            }
        }
        return count;
    }
};