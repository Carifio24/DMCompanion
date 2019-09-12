#ifndef SORT_HPP
#define SORT_HPP

#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <QList>
#include <functional>

#include "dnd/monster.h"

///// Typedefs //////
template <typename T>
using BinaryIntFunc = std::function<int(const T&, const T&)>;

template <typename T>
using Comparator = std::function<bool(const T&, const T&)>;


///// Given a type T and a pointer to a member function T.f() that returns type M, these functions return a function object int(const T&, const T&) that returns
// 1 if t1.f() < t2.f()
// 0 if t1.f() == t2.f()
// -1 if t1.f() > t2.f()

template <typename T, typename M>
BinaryIntFunc<T> test_less_equal(M (T::* mem_fn)(void) const) {
    return [mem_fn](const T& t1, const T& t2) {
        const M v1 = (t1.*mem_fn)();
        const M v2 = (t2.*mem_fn)();
        if ( v1 < v2 ) { return 1; }
        else if ( v1 == v2 ) { return 0; }
        return -1;
    };
}

template <typename T, typename M>
BinaryIntFunc<T> test_less_equal(const M& (T::* mem_fn)(void) const) {
    return [mem_fn](const T& t1, const T& t2) {
        const M& v1 = (t1.*mem_fn)();
        const M& v2 = (t2.*mem_fn)();
        if ( v1 < v2 ) { return 1; }
        else if ( v1 == v2 ) { return 0; }
        return -1;
    };
}

// The "None" sort field
inline static const std::string none_field = "None";



///// These functions take a vector or array and, rather than sort the container itself, return a vector of the indices of the sorted values
/// i.e., if the returned vector is { 1, 0, 4, 2, 3}, then v[1] is the smallest element, then v[0], ..., with v[3] being the largest

template <typename T>
std::vector<int> sorted_indices(const std::vector<T>& v, const Comparator<T>& fcomp=std::less<T>()) {
    std::vector<int> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&v, &fcomp](int i1, int i2) { return fcomp(v[i1], v[i2]); } );
    return idx;
}

template <typename T, size_t N>
std::vector<int> sorted_indices(const std::array<T,N>& v, const Comparator<T>& fcomp=std::less<T>()) {
    std::vector<int> idx(N);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&v, &fcomp](int i1, int i2) { return fcomp(v[i1], v[i2]); } );
    return idx;
}


/// Given a "map" (anything with key_type, mapped_type, begin(), and end()), this function returns a vector of std::pair<Key,Value>, sorted by value

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


/// Given functions with signatures int(const T&, const T&) (namely, something returned by test_less_equal), less_than does our comparison for us
/// less_than takes as arguments the two objects to be compared, and a number of binary functions.
/// It checks each comparison, in order, returning true if the comparator is positive and false if it is negative.
/// If the binary function returns 0 (i.e. the two objects compare equal for the given comparison), it moves on to the next binary function.
/// This function has a recursive implementation - the cases with arbitrary numbers of functions are handled by (if necessary) calls to versions with fewer functions
/// Note that we'll get the actual comparator function object from comparator() below, by wrapping less_than in a function object

template <typename T>
bool less_than(const T& t1, const T& t2, const BinaryIntFunc<T>& comp) {
    return comp(t1, t2) > 0;
}

template <typename T, typename... Args>
bool less_than(const T& t1, const T& t2, const BinaryIntFunc<T>& comp, Args&&... args) {
    int r = comp(t1, t2);
    if (r != 0) {
        return r > 0;
    }
    return less_than(t1, t2, std::forward<Args>(args)...);
}

/// Here we get the actual comparator function object by wrapping less_than
/// Note that we don't actually need a both forms here - something like comparator(Args&&... args) would work by itself
/// But doing it this way allows the compiler to automatically deduce the template type T
/// The type_traits stuff (commented out) would just ensure that every argument in Args.. has type BinaryIntFunc<T>
/// But we don't need it - we'll get an error from less_than anyways if they aren't

template <typename T>
Comparator<T> comparator(const BinaryIntFunc<T>& f) {
    return [f](const T& t1, const T& t2) { return less_than(t1, t2, f); };
}

//template <typename T, typename... Args, typename = std::enable_if_t<std::conjunction_v<std::is_same<BinaryIntFunc<T>, Args>...>> >
template <typename T, typename... Args>
Comparator<T> comparator(const BinaryIntFunc<T>& f, Args&&... args) {
    return [f, args...](const T& t1, const T& t2) { return less_than(t1, t2, f, args...); };
}


#endif
