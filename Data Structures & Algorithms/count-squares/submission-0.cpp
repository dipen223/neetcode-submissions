class CountSquares {
    unordered_map<int, unordered_map<int, int>> ptsCount;

public:
    CountSquares() {}

    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
    }

    int count(vector<int> point) const {
        int res = 0;
        int x1 = point[0], y1 = point[1];

        auto column = ptsCount.find(x1);
        if (column == ptsCount.end()) return 0;

        for (const auto& [y2, cnt] : column->second) {
            int side = y2 - y1;
            if (side == 0) continue;

            int x3 = x1 + side, x4 = x1 - side;
            for (int x : {x3, x4}) {
                auto other = ptsCount.find(x);
                if (other == ptsCount.end()) continue;

                const auto& counts = other->second;
                auto p1 = counts.find(y1), p2 = counts.find(y2);
                if (p1 != counts.end() && p2 != counts.end()) {
                    res += cnt * p1->second * p2->second;
                }
            }
        }

        return res;
    }
};