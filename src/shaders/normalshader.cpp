#include "normalshader.h"
#include "../core/utils.h"

NormalShader::NormalShader() 
{ }

NormalShader::NormalShader(Vector3D bgColor_) :
    Shader(bgColor_)
{ }

Vector3D NormalShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    Vector3D c;

    Intersection its;

    if (Utils::getClosestIntersection(r, objList, its)) {
        
        Vector3D resta = its.itsPoint - r.o;
        double hitDist = sqrt(pow(resta.x,2) + pow(resta.y, 2) + pow(resta.z, 2));

        c = (its.normal + Vector3D(1,1,1)) / 2;
    }
   

    return c;
}
