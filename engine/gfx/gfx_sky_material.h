/* Copyright (c) David Cunningham and the Grit Game Engine project 2015
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <vector>

class GfxSkyMaterial;
typedef std::vector<GfxSkyMaterial*> GfxSkyMaterials;

#ifndef GFX_SKY_MATERIAL_H
#define GFX_SKY_MATERIAL_H

#include <OgreMaterial.h>

#include "gfx_material.h"
#include "gfx_internal.h"
#include "gfx_gasoline.h"
#include "gfx_shader.h"

enum GfxSkyMaterialSceneBlend {
    GFX_SKY_MATERIAL_OPAQUE,
    GFX_SKY_MATERIAL_ALPHA,
    GFX_SKY_MATERIAL_ADD
};

class GfxSkyMaterial : public GfxBaseMaterial {

    GfxSkyMaterialSceneBlend sceneBlend;

    GfxSkyMaterial (const std::string &name);

    public:
    // take MAT_SYNC when iterating through this stuff

    GfxSkyMaterialSceneBlend getSceneBlend (void) const { return sceneBlend; }
    void setSceneBlend (GfxSkyMaterialSceneBlend v) { sceneBlend = v; }

    void addDependencies (DiskResource *into);

    const std::string name;

    friend GfxSkyMaterial *gfx_sky_material_add(const std::string &);
    friend class GfxSkyBody;
};  
    
GfxSkyMaterial *gfx_sky_material_add (const std::string &name);

GfxSkyMaterial *gfx_sky_material_add_or_get (const std::string &name);

GfxSkyMaterial *gfx_sky_material_get (const std::string &name);
    
bool gfx_sky_material_has (const std::string &name);

void gfx_sky_material_shutdown (void);

void gfx_sky_material_init (void);

#endif
