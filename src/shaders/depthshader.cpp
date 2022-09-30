#include "depthshader.h"
#include "../core/utils.h"

DepthShader::DepthShader() : color(Vector3D(1, 0, 0))  
{ }

DepthShader::DepthShader(Vector3D color_, double maxDist_, Vector3D bgColor_) :
    Shader(bgColor_), color(color_), maxDist(maxDist_)
{ }

Vector3D DepthShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
  //  if (Utils::hasIntersection(r, objList))
       // return hitColor;
  //  else
   //     return bgColor;
}
