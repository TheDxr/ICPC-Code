// 方法一求凸包
class Solution
{
public:
    bool isConvex(vector<vector<int>> points)
    {
        vector<vec2> dots(points.size());
        float yMin = 1e9;
        float yMinIndex;
        for(int i = 0; i < points.size(); i++) {
            dots[i].x = points[i][0];
            dots[i].y = points[i][1];
            if(dots[i].y < yMin){
                yMin = dots[i].y;
                yMinIndex = i;
            }
        }
        for(int i = 0; i < dots.size(); i++) {
            float dx = dots[i].x - points[yMinIndex][0];
            float dy = dots[i].y - points[yMinIndex][1];
            if(dx == 0) {
                if(dy == 0) {
                    dots[i].angle = -1e9;
                    continue;
                }
                dots[i].angle = dy > 0 ? 3.14 / 2 : -3.14 / 2;
            }
            else {
                dots[i].angle = atan2(dy, dx);
            }
        }
        auto convex = graham(dots);
        return points.size() == convex.size();
    }

private:

    struct vec2
    {
        float x;
        float y;
        float angle;
        bool operator<(const vec2 &v) const
        {
            if(angle == v.angle) {
                if(x == v.x) return y < v.y;
                return x < v.x;
            }
            return angle < v.angle;
        }
    };
    vector<vec2> graham(vector<vec2> &points)
    {
        const int N = points.size();
        vector<bool> visit(N, false);
        vector<vec2> hull;
        hull.reserve(N);
        std::sort(points.begin(), points.end());
        if(N <= 2) return {};
        for(int i = 0; i < N; i++) {
            if(visit[i]) continue;
            vec2 cur = points[i];
            if(hull.size() < 2) {
                hull.push_back(cur);
                visit[i] = true;
                continue;
            }
            else {
                vec2 top = hull.back();
                vec2 nextTop = hull[hull.size() - 2];
           
                if(crossProduct(nextTop, top, cur) < 0) {
                    hull.pop_back();
                    i--;
                }
                else {
                    hull.push_back(cur);
                    visit[i] = true;
                }
            }
        }
        reverse(hull.begin(), hull.end());
        return hull;
    }
    // 大于0在左边，小于0在右边，等于0在一条直线上
    int crossProduct(const vec2 &a, const vec2 &b, const vec2 &c)
    {
        return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
    }
};
