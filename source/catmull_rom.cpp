#include "catmull_rom.h"

constexpr float CatmullRom::Eval_h00(float t) {
    return 2*t*t*t - 3*t*t + 1;
}

constexpr float CatmullRom::Eval_h01(float t) {
    return -2*t*t*t + 3*t*t;
}

constexpr float CatmullRom::Eval_h10(float t) {
    return t*t*t - 2*t*t + t;
}

constexpr float CatmullRom::Eval_h11(float t) {
    return t*t*t - t*t;
}

vec2<float> CatmullRom::Eval_m(const vec2<float> p0,
                               const vec2<float> p1) {
    return (p0 + p1) / 2.f; 
}

vec2<float> CatmullRom::InterpolatePoint(float t, const vec2<float>& p0, const vec2<float>& p1,
                                                  const vec2<float>& p2, const vec2<float>& p3) {
    vec2<float> res_ptr{};

    const float h00 = Eval_h00(t);
    const float h01 = Eval_h01(t);
    const float h10 = Eval_h10(t);
    const float h11 = Eval_h11(t);

    const vec2<float> m0 = Eval_m(p0,2);
    const vec2<float> m1 = Eval_m(p1, p3);

    return p1 * h00 + m0 * h10 +
           p2 * h01 + m1 * h11;
}

vec2<float> CatmullRom::operator[](float t) {
    std::size_t point_number = static_cast<std::size_t>(t);

    return InterpolatePoint(t - static_cast<float>(point_number),
                            points_[point_number + 0],
                            points_[point_number + 1],
                            points_[point_number + 2],
                            points_[point_number + 3]);
}
