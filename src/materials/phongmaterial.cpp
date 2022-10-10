#include "phongmaterial.h"

#include <iostream>

PhongMaterial::PhongMaterial(double _kd, double _ks, double _n) :
    kd(_kd), ks(_ks), n(_n)
{ }

Vector3D PhongMaterial::getReflectance(const Vector3D& n, const Vector3D& wo, const Vector3D& wi)
{
    Vector3D wr = n * dot(n, wi) * 2 - wi;

    Vector3D r = dot(wi, n) * this->kd + pow(dot(wo, wr), this->n) * this->ks;
    return r;

};
bool hasSpecular() {};
bool hasTransmission() {};
bool hasDiffuseOrGlossy() {};
