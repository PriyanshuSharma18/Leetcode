class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        int goal = (size * (size - 1)) / 2;
        int psize = 0;
        int csize = 0;
        int sum = 0;
        std::unordered_map<int, int> accessibleRooms;

        for (auto room : rooms[0]) {
            accessibleRooms[room] = 1;
            sum += room;
            csize++;
        }
        while (psize != csize) {
            for (auto [key, value] : accessibleRooms) {
                for (auto room : rooms[key]) {
                    if (accessibleRooms[room] != 1) {
                        csize++;
                        accessibleRooms[room] = 1;
                        sum += room;
                    }
                }
            }
            psize++;
        }
        return ((goal != sum) ? false : true);
    }
};