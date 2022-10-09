#include "depthshader.h"
#include "../core/utils.h"

DepthShader::DepthShader() : color(Vector3D(0, 1, 0))  
{ }

DepthShader::DepthShader(Vector3D color_, double maxDist_, Vector3D bgColor_) :
    Shader(bgColor_), color(color_), maxDist(maxDist_)
{ }

Vector3D DepthShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    Vector3D c;

    Intersection its;

    if (Utils::getClosestIntersection(r, objList, its)) {

        Vector3D resta = its.itsPoint - r.o;
        double hitDist = sqrt(pow(resta.x,2) + pow(resta.y, 2) + pow(resta.z, 2));

        c.y = std::max(1 - (double) hitDist / maxDist, 0.0);
    }
   

    return c;
}
