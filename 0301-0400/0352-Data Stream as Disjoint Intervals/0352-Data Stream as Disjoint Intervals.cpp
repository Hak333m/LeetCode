/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = table.lower_bound(Interval(val, val));
        if (it != table.begin()) {
            auto prev = it;
            --prev;
            if (prev->end >= val - 1) {
                it = prev;
            }
        }
        int start = val, end = val;
        while (it != table.end() && it->start <= val + 1 && it->end >= val - 1) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = table.erase(it);
        }
        table.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for (auto val : table) {
            result.push_back(val);
        }
        return result;
    }
    
private:
    struct cmp {
        bool operator()(Interval i1, Interval i2) {
            return i1.start < i2.start;
        }
    };
    set<Interval, cmp> table;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto l = table.lower_bound(val);
        if (l != table.begin()) {
            --l;
            if (l->second < val - 1) {
                ++l;
            }
        }
        
        auto r = table.upper_bound(val + 1);
        int left = val, right = val;
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            table.erase(l, ++r);
        }
        
        table[left] = right;
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for (auto t : table) {
            result.emplace_back(t.first, t.second);
        }
        return result;
    }
    
private:
    map<int, int> table;
};


