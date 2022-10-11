#include "directshader.h"
#include "../core/utils.h"

DirectShader::DirectShader()
{ }


Vector3D DirectShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    Vector3D lo;

    Intersection its;

    if (Utils::getClosestIntersection(r, objList, its)) {

        int nL = lsList.size();
        int numObjs = objList.size();
        
        for (int obj = 0; obj < numObjs; obj++) {
            
            bool vi = false;

            Intersection itsObj;
            if (objList[obj]->rayIntersect(r, itsObj)) {
                if (itsObj.itsPoint.x == its.itsPoint.x && itsObj.itsPoint.y == its.itsPoint.y && itsObj.itsPoint.z == its.itsPoint.z) {
                    vi = true;
                }
            }

            if (vi) {
                for (int s = 0; s < nL; s++) {
                    Vector3D li = lsList[s].getIntensity(its.itsPoint);

                    Vector3D wo = r.o - its.itsPoint;
                    Vector3D wi = lsList[s].getPosition() - its.itsPoint;
            
                    Vector3D r = objList[obj]->getMaterial().getReflectance(its.normal, wo, wi);
                
                
                    lo += li * r;
                }
            }

        }
    }


    return lo;
}
