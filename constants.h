#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <numeric>
constexpr const float max_speed{20};//32
constexpr const float move_accel{5};
constexpr const float take_off_speed{-(52)};//64
constexpr const float _gravity{6};
constexpr const float _space_gravity{3};
constexpr const float max_y_speed{53};
constexpr const float take_off_side_speed{20};


template<typename T>
constexpr void divideby6 (T &val)
{
    val = val / 6;
}
#endif // CONSTANTS_H
