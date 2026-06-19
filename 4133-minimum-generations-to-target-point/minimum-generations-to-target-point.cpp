class Solution {
public:
    struct Point {
        int x, y, z;

        bool operator<(const Point &other) const {
            if (x != other.x) return x < other.x;
            if (y != other.y) return y < other.y;
            return z < other.z;
        }
    };

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int maxX = 0, maxY = 0, maxZ = 0;

        map<Point, int> dist;
        vector<Point> pts;

        for (auto &p : points) {
            Point cur = {p[0], p[1], p[2]};
            dist[cur] = 0;
            pts.push_back(cur);

            maxX = max(maxX, p[0]);
            maxY = max(maxY, p[1]);
            maxZ = max(maxZ, p[2]);
        }

        Point tar = {target[0], target[1], target[2]};

        if (dist.count(tar)) return 0;

        if (target[0] > maxX || target[1] > maxY || target[2] > maxZ)
            return -1;

        const int INF = 1e9;

        bool changed = true;

        while (changed) {
            changed = false;

            int sz = pts.size();

            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {

                    Point a = pts[i], b = pts[j];

                    Point c = {
                        (a.x + b.x) / 2,
                        (a.y + b.y) / 2,
                        (a.z + b.z) / 2
                    };

                    int newGen = max(dist[a], dist[b]) + 1;

                    if (!dist.count(c)) {
                        dist[c] = newGen;
                        pts.push_back(c);
                        changed = true;
                    }
                    else if (newGen < dist[c]) {
                        dist[c] = newGen;
                        changed = true;
                    }
                }
            }
        }

        if (dist.count(tar))
            return dist[tar];

        return -1;
    }
};