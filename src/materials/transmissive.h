#ifndef TRANSMISSIVE_H
#define TRANSMISSIVE_H

#include "material.h"

class Transmissive : public Material
{
public:
    Transmissive(double _nt);
    Transmissive(Vector3D& kd_, Vector3D& ks_, double shininess_);

    Vector3D getReflectance(const Vector3D& n, const Vector3D& wo, const Vector3D& wi) const;
    bool hasSpecular() const;
    bool hasTransmission() const;
    bool hasDiffuseOrGlossy() const;
    double getIndexOfRefraction() const;

    double nt;
    ~Transmissive();

private:
    Vector3D kd;
    Vector3D ks;
    double shininess;
};

#endif // TRANSMISSIVE_H
