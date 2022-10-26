#ifndef MIRROR_H
#define MIRROR_H

#include "material.h"

class Mirror : public Material
{
public:
    Mirror();
    Mirror(Vector3D& kd_, Vector3D& ks_, double shininess_);

    Vector3D getReflectance(const Vector3D& n, const Vector3D& wo, const Vector3D& wi) const;
    bool hasSpecular() const;
    bool hasTransmission() const;
    bool hasDiffuseOrGlossy() const;
    Vector3D getDiffuseCoefficient() const;

    ~Mirror();

private:
    Vector3D kd;
    Vector3D ks;
    double shininess;
};

#endif // MIRROR_H
