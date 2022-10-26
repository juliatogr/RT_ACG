#ifndef GLOBALSHADER_H
#define GLOBALSHADER_H

#include "shader.h"

class GlobalShader : public Shader
{
public:
    GlobalShader();
    GlobalShader(Vector3D bgColor_, Vector3D at_);

    Vector3D computeColor(const Ray &r,
                             const std::vector<Shape*> &objList,
                             const std::vector<PointLightSource> &lsList) const;
    Vector3D at;
};

#endif // GLOBALSHADER_H
