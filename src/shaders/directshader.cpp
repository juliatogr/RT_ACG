#include "directshader.h"
#include "../core/utils.h"

DirectShader::DirectShader()
{ }

DirectShader::DirectShader(Vector3D bgColor_) :
    Shader(bgColor_)
{ }

Vector3D DirectShader::computeColor(const Ray &r,
                               const std::vector<Shape*> &objList,
                               const std::vector<PointLightSource> &lsList) const
{
    // Get the closest Intersection along the ray
    Intersection its; // Auxiliar structure to store information about the intersection, in case there is one
    if(Utils::getClosestIntersection(r, objList, its))
    {
        Vector3D Lo(0.0);        
        //Check if Phong Material
        if (its.shape->getMaterial().hasDiffuseOrGlossy()){
            for (auto const& light: lsList) {
                Vector3D P_L = light.getPosition() - its.itsPoint; //Vector from intersection point to lightsource
                Vector3D wi = P_L.normalized(); //Normalized Vector wi
                Ray ray_visibility(its.itsPoint, wi, 0, Epsilon, P_L.length());
                if (Utils::hasIntersection(ray_visibility, objList))
                    continue;
                Lo += light.getIntensity(its.itsPoint) * its.shape->getMaterial().getReflectance(its.normal,-r.d ,wi )*dot(its.normal,wi);
                }
            }

        if (its.shape->getMaterial().hasSpecular()) {

            Vector3D wo = -r.d;      //Vector from intersection point to view origin
            
            Vector3D wr = its.normal * 2 * dot(its.normal, wo) - wo;

            Ray ray_visibility(its.itsPoint, wr, r.depth+1);

  
            Lo = computeColor(ray_visibility, objList, lsList);
        }

        if (its.shape->getMaterial().hasTransmission()) {

            double nt = its.shape->getMaterial().getIndexOfRefraction();
            
            Vector3D wo = -r.d;      //Vector from intersection point to view origin
            double cos = dot(its.normal, wo);
            double sin2 = 1 - cos*cos;
            double refract = 1 - nt * nt * sin2;

            if (refract >= 0) {
                Vector3D wt = its.normal * (-sqrt(refract) + nt * cos) - wo * nt;

                Ray ray_refract(its.itsPoint, wt, r.depth + 1);
                Lo = computeColor(ray_refract, objList, lsList);

            } else {

                Vector3D wr = its.normal * 2 * dot(its.normal, wo) - wo;

                Ray ray_visibility(its.itsPoint, wr, r.depth + 1);
                
                Lo = computeColor(ray_visibility, objList, lsList);
            }
            Vector3D wr = its.normal * 2 * dot(its.normal, wo) - wo;

            Ray ray_visibility(its.itsPoint, wr, r.depth + 1);


            Lo = computeColor(ray_visibility, objList, lsList);
        }
            // Once all light sources have been taken into account, return the final result
        return Lo;
    }    
    else    
        return bgColor;
    
}
