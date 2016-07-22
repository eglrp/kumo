//
// Created by 诸谦 on 16/6/25.
//

#ifndef RAYTRACER_SIMPLERENDERER_H
#define RAYTRACER_SIMPLERENDERER_H
#include "global.h"
#include "renderer.h"
#include "memory.h"
#include "random.h"

class SimpleRenderer :public Renderer{
private:
    Camera* camera;
    Sampler* sampler;
    SurfaceIntegrator* mSurfaceIntegrator;
    Random mRand;
    MemoryArena mArena;
public:

    SimpleRenderer(Camera* c,Sampler* s,SurfaceIntegrator* si):Renderer(),camera(c),sampler(s),mSurfaceIntegrator(si){
        assert(camera!=nullptr);
        assert(sampler!=nullptr);
    }
    virtual void render(const Scene* scene) override;


};


#endif //RAYTRACER_SIMPLERENDERER_H
