//
// Created by 诸谦 on 16/6/18.
//

#ifndef RAYTRACER_DIFFGEOM_H
#define RAYTRACER_DIFFGEOM_H
#include "geometry.h"
#include "seidennki.h"

//微分几何
struct DifferentialGeometry{
    DifferentialGeometry() {
        u = v = dudx = dvdx = dudy = dvdy = 0.;
        shape = nullptr;
    }
    // DifferentialGeometry Public Methods
    DifferentialGeometry(const Point &P, const Vector &DPDU,
                         const Vector &DPDV, const Normal &DNDU,
                         const Normal &DNDV, float uu, float vv,
                         const Shape *sh);

    void ComputeDifferentials(const RayDifferential &r) const; //通过微分射线  计算  几何微分

    // DifferentialGeometry Public Data
    Point p;
    Normal nn;
    float u, v;
    const Shape *shape;
    Vector dpdu, dpdv;
    Normal dndu, dndv;
    mutable Vector dpdx, dpdy;
    mutable float dudx, dvdx, dudy, dvdy;
};

#endif //RAYTRACER_DIFFGEOM_H
