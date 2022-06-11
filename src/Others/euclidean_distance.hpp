#ifndef ALGORITHM_EUCLIDEAN_DISTANCE_HPP
#define ALGORITHM_EUCLIDEAN_DISTANCE_HPP 1

namespace algorithm {

template <typename Type>
Type euclidean_distance(Type dy, Type dx) {
    return dy * dy + dx * dx;
}

}  // namespace algorithm

#endif  // ALGORITHM_EUCLIDEAN_DISTANCE_HPP
