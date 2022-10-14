#include "mirror.h"

Mirror::Mirror() :
    shininess(50)
{
    kd = Vector3D(1.0);
    ks = Vector3D(1.0);
}

Mirror::Mirror(Vector3D& kd_, Vector3D& ks_, double shininess_) :
    shininess(shininess_), kd(kd_), ks(ks_)
{

}



bool Mirror::hasSpecular() const
{
    return true;
}

bool Mirror::hasTransmission() const
{
    return false;
}

bool Mirror::hasDiffuseOrGlossy() const
{
    return false;
}

Vector3D Mirror::getReflectance(const Vector3D& n, const Vector3D& wo, const Vector3D& wi) const
{  
    // Compute the perfect reflection direction
    Vector3D wr = n * 2 * dot(n, wi) - wi;
    // Compute the cos of the angle between the incident light direction
    // and the perfect reflection direction
    double cosWrWo = dot(wr, wo);
    return kd* std::max(dot(wi, n),0.0) + ks * pow(cosWrWo, shininess);
}

Mirror::~Mirror()
{

}