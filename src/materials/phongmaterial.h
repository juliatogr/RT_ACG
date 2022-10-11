#ifndef PHONGMATERIAL
#define PHONGMATERIAL

#include "../core/vector3d.h"
#include "material.h"

class PhongMaterial : public Material
{
public:
    PhongMaterial(Vector3D _kd, Vector3D _ks, double _n);

    Vector3D getReflectance(const Vector3D &n, const Vector3D &wo, const Vector3D &wi) const;

    bool hasSpecular() const;
    bool hasTransmission() const;
    bool hasDiffuseOrGlossy() const;
    double getIndexOfRefraction() const;

    Vector3D kd;
    Vector3D ks;
    double n;

};


#endif // PHONGMATERIAL
