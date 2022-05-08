/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> a;
    int j = 0;
    void func(NestedInteger i) {
        if(i.isInteger())
            a.push_back(i.getInteger());
        else
            for(auto &&j : i.getList())
                func(j);
    }
    NestedIterator(vector<NestedInteger>& list) {
        for(auto i: list) func(i);
    }
    
    int next() {
        return a[j++];
    }
    
    bool hasNext() {
        return (j < a.size() ? true : false);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */