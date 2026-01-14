struct SegmentTree {
    int n;
    vector<int> count; // how many times this segment is “covered”
    vector<long long>
        length;           // how much actual x-length is covered in this segment
    vector<long long> xs; // the sorted unique x-coordinates

    SegmentTree(const vector<long long>& _xs) {
        xs = _xs;
        n = (int)xs.size() - 1;
        count.assign(4 * n, 0);
        length.assign(4 * n, 0);
    }

    // update cover count +val over interval [l, r) in x-coordinates
    void update(int idx, int left, int right, int l, int r, int val) {
        if (r <= left || right <= l) {
            return;
        }
        if (l <= left && right <= r) {
            count[idx] += val;
        } else {
            int mid = (left + right) >> 1;
            update(idx * 2, left, mid, l, r, val);
            update(idx * 2 + 1, mid, right, l, r, val);
        }
        if (count[idx] > 0) {
            // fully covered
            length[idx] = xs[right] - xs[left];
        } else {
            if (left + 1 == right) {
                // leaf
                length[idx] = 0;
            } else {
                length[idx] = length[idx * 2] + length[idx * 2 + 1];
            }
        }
    }

    // helper for user: update interval [lIdx, rIdx) in index space
    void updateRange(int lIdx, int rIdx, int val) {
        update(1, 0, n, lIdx, rIdx, val);
    }

    long long coveredLength() const { return length[1]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int m = (int)squares.size();
        // events: (y, delta, x_left, x_right)
        vector<tuple<long long, int, long long, long long>> events;
        vector<long long> xs;
        xs.reserve(2 * m);

        for (int i = 0; i < m; i++) {
            long long x = squares[i][0];
            long long y = squares[i][1];
            long long l = squares[i][2];
            long long x2 = x + l;
            long long y2 = y + l;
            events.emplace_back(y, +1, x, x2);
            events.emplace_back(y2, -1, x, x2);
            xs.push_back(x);
            xs.push_back(x2);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end());

        SegmentTree seg(xs);

        // first compute total union area
        long long totalAreaLL = 0;
        long long prevY = get<0>(events[0]);
        for (auto& e : events) {
            long long y = get<0>(e);
            int delta = get<1>(e);
            long long xl = get<2>(e);
            long long xr = get<3>(e);

            long long coveredX = seg.coveredLength();
            totalAreaLL += coveredX * (y - prevY);

            // update segment tree: find indices of xl,xr in xs
            int li = int(lower_bound(xs.begin(), xs.end(), xl) - xs.begin());
            int ri = int(lower_bound(xs.begin(), xs.end(), xr) - xs.begin());
            seg.updateRange(li, ri, delta);

            prevY = y;
        }

        // Now find the minimum y where area below = area above = totalArea/2
        double halfArea = totalAreaLL / 2.0;
        seg = SegmentTree(xs); // reset
        prevY = get<0>(events[0]);
        long long areaBelowLL = 0;

        for (auto& e : events) {
            long long y = get<0>(e);
            int delta = get<1>(e);
            long long xl = get<2>(e);
            long long xr = get<3>(e);

            long long coveredX = seg.coveredLength();
            long long deltaY = y - prevY;
            double areaGain = (double)coveredX * deltaY;

            if (areaBelowLL + areaGain >= halfArea) {
                // the answer lies in this horizontal strip
                double remaining = halfArea - areaBelowLL;
                // coveredX is constant in this strip
                double resY = prevY + remaining / coveredX;
                return resY;
            }

            areaBelowLL += areaGain;

            int li = int(lower_bound(xs.begin(), xs.end(), xl) - xs.begin());
            int ri = int(lower_bound(xs.begin(), xs.end(), xr) - xs.begin());
            seg.updateRange(li, ri, delta);

            prevY = y;
        }

        // fallback (shouldn't reach)
        return prevY;
    }
};