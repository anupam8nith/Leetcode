#pragma GCC optimize("O3")
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
    ios_base::sync_with_stdio(false);
    unordered_map<int, int> counts;
    vector<int> heap;
    for (auto n : arr)
        ++counts[n];
    for (auto &p: counts)
        heap.push_back(p.second);
    make_heap(begin(heap), end(heap), greater<int>());
    while (k > 0) {
        k -= heap.front();
        pop_heap(begin(heap), end(heap), greater<int>()); 
        if (k >= 0)
            heap.pop_back();
    }
    return heap.size();
}
};