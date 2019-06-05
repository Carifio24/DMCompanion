#include <vector>
#include <numeric>
#include <algorithm>

template <class T>
int get_index(const std::vector<T>& v, const T& x) {
    auto it = std::find(v.begin(), v.end(), x);
    int idx = (it != v.end()) ? std::distance(v.begin(), it); : -1;
    return idx;
}

template <class T>
T sum(const std::vector<T>& v) {
    return std::accumulate(v.begin(), v.end(), T(0));
}