#include "phongmaterial.h"

#include <iostream>

PhongMaterial::PhongMaterial(Vector3D _kd, Vector3D _ks, double _n) :
    kd(_kd), ks(_ks), n(_n)
{ }

Vector3D PhongMaterial::getReflectance(const Vector3D& n, const Vector3D& wo, const Vector3D& wi) const
{
    Vector3D wr = n * dot(n, wi) * 2 - wi;

    Vector3D r = this->kd * dot(wi, n) + this->ks * pow(dot(wo, wr), this->n);
    return r;

};
bool PhongMaterial::hasSpecular() const { return false; };
bool PhongMaterial::hasTransmission() const { return false; };
bool PhongMaterial::hasDiffuseOrGlossy() const { return true; };
double PhongMaterial::getIndexOfRefraction() const { return -1; };