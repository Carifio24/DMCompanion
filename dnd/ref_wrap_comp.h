#include <functional>

// For comparing reference wrappers
struct ref_wrap_comp {
    template <typename T>
    bool operator()(const std::reference_wrapper<T>& r1, const std::reference_wrapper<T>& r2) {
        return r1.get() < r2.get();
    }

    template <typename T>
    bool operator()(const std::reference_wrapper<const T>& r1, const std::reference_wrapper<const T>& r2) {
        return r1.get() < r2.get();
    }
};