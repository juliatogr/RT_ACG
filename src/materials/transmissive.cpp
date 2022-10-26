#include "transmissive.h"

Transmissive::Transmissive(double _nt) :
    nt(_nt)
{ }

Transmissive::Transmissive(Vector3D& kd_, Vector3D& ks_, double shininess_) :
    shininess(shininess_), kd(kd_), ks(ks_)
{ }

double Transmissive::getIndexOfRefraction() const
{
    return nt;
}

bool Transmissive::hasSpecular() const
{
    return false;
}

bool Transmissive::hasTransmission() const
{
    return true;
}

bool Transmissive::hasDiffuseOrGlossy() const
{
    return false;
}

Vector3D Transmissive::getReflectance(const Vector3D& n, const Vector3D& wo, const Vector3D& wi) const
{  
    // Compute the perfect reflection direction
    Vector3D wr = n * 2 * dot(n, wi) - wi;
    // Compute the cos of the angle between the incident light direction
    // and the perfect reflection direction
    double cosWrWo = dot(wr, wo);
    return kd* std::max(dot(wi, n),0.0) + ks * pow(cosWrWo, shininess);
}

Transmissive::~Transmissive()
{

}

Vector3D Transmissive::getDiffuseCoefficient() const
{
    return Vector3D(-1);
}