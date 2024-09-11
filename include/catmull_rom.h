#ifndef CATMULL_ROM_H_
#define CATMULL_ROM_H_

// https://en.wikipedia.org/wiki/Cubic_Hermite_spline

#include "vec.h"
#include <vector>

using namespace Vectors;

class CatmullRom {
private:
    constexpr float Eval_h00(float t);
    constexpr float Eval_h01(float t);
    constexpr float Eval_h10(float t);
    constexpr float Eval_h11(float t);

    const std::vector<vec2<float>>& points_;

    vec2<float> Eval_m(const vec2<float> p0,
                       const vec2<float> p1);

    vec2<float> InterpolatePoint(float t, const vec2<float>& p0, const vec2<float>& p1,
                                          const vec2<float>& p2, const vec2<float>& p3);

public:
    CatmullRom(const std::vector<vec2<float>>& points)
        : points_(points) {}

    vec2<float> operator[](float t);
};

#endif // CATMULL_ROM_H_
