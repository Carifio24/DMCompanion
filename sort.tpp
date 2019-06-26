#ifndef SORT_T
#define SORT_T

#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <QList>
#include <functional>



template <typename T, typename M>
std::function<int(const T&,const T&)> test_less_equal(M (T::* mem_fn)(void) const) {
    return [mem_fn](const T& t1, const T& t2) {
        const M v1 = (t1.*mem_fn)();
        const M v2 = (t2.*mem_fn)();
        if ( v1 < v2 ) { return 1; }
        else if ( v1 == v2 ) { return 0; }
        return -1;
    };
}

template <typename T, typename M>
std::function<int(const T&,const T&)> test_less_equal(const M& (T::* mem_fn)(void) const) {
    return [mem_fn](const T& t1, const T& t2) {
        const M& v1 = (t1.*mem_fn)();
        const M& v2 = (t2.*mem_fn)();
        if ( v1 < v2 ) { return 1; }
        else if ( v1 == v2 ) { return 0; }
        return -1;
    };
}

template <typename T>
std::vector<int> sorted_indices(const std::vector<T>& v, const std::function<bool(const T&, const T&)>& fcomp=[](const T& x, const T& y){return x < y;}) {
    std::vector<int> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&v, &fcomp](int i1, int i2) { return fcomp(v[i1], v[i2]); } );
    return idx;
}

template <typename T, size_t N>
std::vector<int> sorted_indices(const std::array<T,N>& v, const std::function<bool(const T&, const T&)>& fcomp=[](const T& x, const T& y){return x < y;}) {
    std::vector<int> idx(N);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&v, &fcomp](int i1, int i2) { return fcomp(v[i1], v[i2]); } );
    return idx;
}

template <typename Map>
auto value_sort(const Map& m) {
    using K = typename Map::key_type;
    using V = typename Map::mapped_type;
    using KVP = std::pair<K,V>;
    std::vector<KVP> v;
    v.reserve(m.size());
    for (auto it = m.begin(); it != m.end(); ++it) {
        v.push_back(*it);
    }
    std::sort(v.begin(), v.end(), [](const KVP& p1, const KVP& p2) { return p1.second < p2.second; });
    return v;
}


template <typename T>
bool less_than(const T& t1, const T& t2, const std::function<int(const T&,const T&)>& comp) {
    return comp(t1, t2) > 0;
}

template <typename T, typename... Args>
bool less_than(const T& t1, const T& t2, const std::function<int(const T&,const T&)>& comp, Args&&... args) {
    int r = comp(t1, t2);
    if (r != 0) {
        return r > 0;
    }
    return less_than(t1, t2, std::forward<Args>(args)...);
}



// This class provides a template function that sorts based on a member value of the user's choice
// MemberType is a pointer to the specified member value, i.e. &DnD::Spell::name
// Note that the sorting is done via std::sort with an appropriate lambda function
//template <typename T, auto (T::*mem_ptr)(void)>
//class MemValComp {

//	public:
//        static bool doCompare(const T& s1, const T& s2) {
//            return (s1.*mem_ptr)() < (s1.*mem_ptr)();
//		}

//        static void doSort(auto& slist) {
//            std::sort(slist.begin(), slist.end(), [](const T& s1, const T& s2) {return doCompare(s1, s2);});
//		}
//};

//// This class does the same thing for two-level sorting
//// MemberType1 corresponds to the first-level sort
//template <typename T, auto (T::*mem_ptr)(void), auto... vs>
//class MemValComp {

//    public:
//        static bool doCompare(const T& s1, const T& s2) {
//            if ( (s1.*mem_ptr)() != (s2.*mem_ptr)() ) {
//                return (s1.*mem_ptr)() < (s1.*mem_ptr)();
//            } else {
//                return MemValComp<T, vs...>::doCompare(s1, s2);
//            }
//        }

//        static void doSort(auto& slist) {
//            std::sort(slist.begin(), slist.end(), [](const T& s1, const T& s2) {return doCompare(s1, s2);});
//        }
//};


#endif
