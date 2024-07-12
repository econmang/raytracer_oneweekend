#ifndef CUBE_H
#define CUBE_H

#include "hittable.h"
#include "vec3.h"

class cube: public hittable {
public:
    cube(const point3& center, double side) : center(center), side(fmax(0,side)) {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        return true;
    }
private:
    point3 center;
    double side;
};

#endif
