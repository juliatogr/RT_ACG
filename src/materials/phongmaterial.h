#ifndef PHONGMATERIAL
#define PHONGMATERIAL

#include "../core/vector3d.h"
#include "material.h"

class PhongMaterial : public Material
{
public:
    PhongMaterial(double kd, double ks, double _n);

    Vector3D getReflectance(const Vector3D &n, const Vector3D &wo, const Vector3D &wi);
    bool hasSpecular();
    bool hasTransmission();
    bool hasDiffuseOrGlossy();
    double getIndexOfRefraction() const;

    double kd;
    double ks;
    double n;

};


#endif // PHONGMATERIAL
