#include "stdafx.h"
#include "MogreSceneManager.h"
#include "MogreSceneNode.h"
#include "MogreEntity.h"
#include "Marshalling.h"

using namespace Mogre;

SceneManager::~SceneManager()
{
	this->!SceneManager();
}

SceneManager::!SceneManager()
{
	OnDisposing(this, nullptr);

	if (IsDisposed)
		return;

	if (_createdByCLR && _native) { delete _native; _native = 0; }

	OnDisposed(this, nullptr);
}

bool SceneManager::IsDisposed::get()
{
	return (_native == nullptr);
}

Mogre::Color4 SceneManager::AmbientLight::get()
{
	return ToColor4(_native->getAmbientLight());
}

void SceneManager::AmbientLight::set(Mogre::Color4 value)
{
	_native->setAmbientLight(FromColor4(value));
}

bool SceneManager::DisplaySceneNodes::get()
{
	return _native->getDisplaySceneNodes();
}

void SceneManager::DisplaySceneNodes::set(bool value)
{
	_native->setDisplaySceneNodes(value);
}

Mogre::BillboardSet^ SceneManager::CreateBillboardSet(unsigned int poolSize)
{
	return ObjectTable::GetOrCreateObject<Mogre::BillboardSet^>((intptr_t)_native->createBillboardSet(poolSize));
}

void SceneManager::DestroyBillboardSet(Mogre::BillboardSet^ set)
{
	_native->destroyBillboardSet(GetPointerOrNull(set));
}

void SceneManager::DestroyAllBillboardSets()
{
	_native->destroyAllBillboardSets();
}

Mogre::BillboardChain^ SceneManager::CreateBillboardChain()
{
	return ObjectTable::GetOrCreateObject<Mogre::BillboardChain^>((intptr_t)_native->createBillboardChain());
}

void SceneManager::DestroyBillboardChain(Mogre::BillboardChain^ obj)
{
	_native->destroyBillboardChain(GetPointerOrNull(obj));
}

void SceneManager::DestroyAllBillboardChains() 
{
	_native->destroyAllBillboardChains();
}

Mogre::RibbonTrail^ SceneManager::CreateRibbonTrail()
{
	return ObjectTable::GetOrCreateObject<Mogre::RibbonTrail^>((intptr_t)_native->createRibbonTrail());
}

void SceneManager::DestroyRibbonTrail(Mogre::RibbonTrail^ obj)
{
	_native->destroyRibbonTrail(GetPointerOrNull(obj));
}

void SceneManager::DestroyAllRibbonTrails()
{
	_native->destroyAllRibbonTrails();
}

Mogre::ParticleSystem^ SceneManager::CreateParticleSystem(String^ templateName)
{
	DECLARE_NATIVE_STRING(o_templateName, templateName);

	return ObjectTable::GetOrCreateObject<Mogre::ParticleSystem^>((intptr_t)_native->createParticleSystem(o_templateName));
}

Mogre::ParticleSystem^ SceneManager::CreateParticleSystem(size_t quota, String^ resourceGroup)
{
	DECLARE_NATIVE_STRING(o_resourceGroup, resourceGroup);

	return ObjectTable::GetOrCreateObject<Mogre::ParticleSystem^>((intptr_t)_native->createParticleSystem(quota, o_resourceGroup));
}

Mogre::ParticleSystem^ SceneManager::CreateParticleSystem(size_t quota)
{
	return ObjectTable::GetOrCreateObject<Mogre::ParticleSystem^>((intptr_t)_native->createParticleSystem(quota));
}

void SceneManager::DestroyParticleSystem(Mogre::ParticleSystem^ obj)
{
	_native->destroyParticleSystem(GetPointerOrNull(obj));
}

void SceneManager::DestroyAllParticleSystems()
{
	static_cast<Ogre::SceneManager*>(_native)->destroyAllParticleSystems();
}

Mogre::Light^ SceneManager::CreateLight()
{
	return ObjectTable::GetOrCreateObject<Mogre::Light^>((intptr_t)_native->createLight());
}

void SceneManager::DestroyLight(Mogre::Light^ light)
{
	static_cast<Ogre::SceneManager*>(_native)->destroyLight(GetPointerOrNull(light));
}

void SceneManager::DestroyAllLights()
{
	_native->destroyAllLights();
}

Mogre::Camera^ SceneManager::CreateCamera(String^ name)
{
	return CreateCamera(name, true, false);
}

Mogre::Camera^ SceneManager::CreateCamera(String^ name, bool notShadowCaster)
{
	return CreateCamera(name, notShadowCaster, false);
}

Mogre::Camera^ SceneManager::CreateCamera(String^ name, bool notShadowCaster, bool forCubemapping)
{
	DECLARE_NATIVE_STRING(o_name, name);

	return ObjectTable::GetOrCreateObject<Mogre::Camera^>((intptr_t)_native->createCamera(o_name, notShadowCaster, forCubemapping));
}

Mogre::Camera^ SceneManager::FindCamera(String^ name)
{
	DECLARE_NATIVE_STRING(o_name, name);

	return ObjectTable::GetOrCreateObject<Mogre::Camera^>((intptr_t)_native->findCamera(o_name));
}

Mogre::Camera^ SceneManager::FindCameraNoThrow(String^ name)
{
	DECLARE_NATIVE_STRING(o_name, name);

	return ObjectTable::GetOrCreateObject<Mogre::Camera^>((intptr_t)_native->findCameraNoThrow(o_name));
}

void SceneManager::DestroyCamera(Mogre::Camera^ camera)
{
	_native->destroyCamera(GetPointerOrNull(camera));
}

void SceneManager::DestroyAllCameras()
{
	_native->destroyAllCameras();
}

Mogre::Entity^ SceneManager::CreateEntity(String^ meshName)
{
	DECLARE_NATIVE_STRING(o_meshName, meshName);

	return ObjectTable::GetOrCreateObject<Mogre::Entity^>((intptr_t)_native->createEntity(o_meshName));
}

Mogre::Entity^ SceneManager::CreateEntity(String^ meshName, String^ groupName)
{
	DECLARE_NATIVE_STRING(o_meshName, meshName);
	DECLARE_NATIVE_STRING(o_groupName, groupName);

	return ObjectTable::GetOrCreateObject<Mogre::Entity^>((intptr_t)_native->createEntity(o_meshName, o_groupName));
}

Mogre::Entity^ SceneManager::CreateEntity(String^ meshName, String^ groupName, SceneMemoryMgrTypes sceneType)
{
	DECLARE_NATIVE_STRING(o_meshName, meshName);
	DECLARE_NATIVE_STRING(o_groupName, groupName);

	return ObjectTable::GetOrCreateObject<Mogre::Entity^>((intptr_t)_native->createEntity(o_meshName, o_groupName, (Ogre::SceneMemoryMgrTypes)sceneType));
}

Mogre::Entity^ SceneManager::CreateEntity(Mogre::SceneManager::PrefabType ptype)
{
	return ObjectTable::GetOrCreateObject<Mogre::Entity^>((intptr_t)_native->createEntity((Ogre::SceneManager::PrefabType)ptype));
}

Mogre::Entity^ SceneManager::CreateEntity(Mogre::SceneManager::PrefabType ptype, SceneMemoryMgrTypes sceneType)
{
	return ObjectTable::GetOrCreateObject<Mogre::Entity^>((intptr_t)_native->createEntity((Ogre::SceneManager::PrefabType)ptype, (Ogre::SceneMemoryMgrTypes)sceneType));
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName, Ogre::Real scale, Ogre::Real tiling, bool drawFirst, Ogre::Real bow, int xsegments, int ysegments, String^ groupName)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);
	DECLARE_NATIVE_STRING(o_groupName, groupName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName, scale, tiling, drawFirst, bow, xsegments, ysegments, o_groupName);
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName, Ogre::Real scale, Ogre::Real tiling, bool drawFirst, Ogre::Real bow, int xsegments, int ysegments)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName, scale, tiling, drawFirst, bow, xsegments, ysegments);
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName, Ogre::Real scale, Ogre::Real tiling, bool drawFirst, Ogre::Real bow, int xsegments)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName, scale, tiling, drawFirst, bow, xsegments);
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName, Ogre::Real scale, Ogre::Real tiling, bool drawFirst, Ogre::Real bow)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName, scale, tiling, drawFirst, bow);
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName, Ogre::Real scale, Ogre::Real tiling, bool drawFirst)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName, scale, tiling, drawFirst);
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName, Ogre::Real scale, Ogre::Real tiling)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName, scale, tiling);
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName, Ogre::Real scale)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName, scale);
}

void SceneManager::SetSkyPlane(bool enable, Mogre::Plane plane, String^ materialName)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyPlane(enable, FromPlane(plane), o_materialName);
}


void SceneManager::SetSkyBox(bool enable, String^ materialName, Ogre::Real distance, bool drawFirst, Mogre::Quaternion orientation, String^ groupName)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);
	DECLARE_NATIVE_STRING(o_groupName, groupName);

	_native->setSkyBox(enable, o_materialName, distance, drawFirst, FromQuaternion(orientation), o_groupName);
}
void SceneManager::SetSkyBox(bool enable, String^ materialName, Ogre::Real distance, bool drawFirst, Mogre::Quaternion orientation)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyBox(enable, o_materialName, distance, drawFirst, FromQuaternion(orientation));
}

void SceneManager::SetSkyBox(bool enable, String^ materialName, Ogre::Real distance, bool drawFirst)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyBox(enable, o_materialName, distance, drawFirst);
}

void SceneManager::SetSkyBox(bool enable, String^ materialName, Ogre::Real distance)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyBox(enable, o_materialName, distance);
}

void SceneManager::SetSkyBox(bool enable, String^ materialName)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyBox(enable, o_materialName);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling, Ogre::Real distance, bool drawFirst, Mogre::Quaternion orientation, int xsegments, int ysegments, int ysegments_keep, String^ groupName)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);
	DECLARE_NATIVE_STRING(o_groupName, groupName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling, distance, drawFirst, FromQuaternion(orientation), xsegments, ysegments, ysegments_keep, o_groupName);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling, Ogre::Real distance, bool drawFirst, Mogre::Quaternion orientation, int xsegments, int ysegments, int ysegments_keep)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling, distance, drawFirst, FromQuaternion(orientation), xsegments, ysegments, ysegments_keep);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling, Ogre::Real distance, bool drawFirst, Mogre::Quaternion orientation, int xsegments, int ysegments)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling, distance, drawFirst, FromQuaternion(orientation), xsegments, ysegments);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling, Ogre::Real distance, bool drawFirst, Mogre::Quaternion orientation, int xsegments)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling, distance, drawFirst, FromQuaternion(orientation), xsegments);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling, Ogre::Real distance, bool drawFirst, Mogre::Quaternion orientation)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling, distance, drawFirst, FromQuaternion(orientation));
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling, Ogre::Real distance, bool drawFirst)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling, distance, drawFirst);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling, Ogre::Real distance)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling, distance);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature, Ogre::Real tiling)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature, tiling);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName, Ogre::Real curvature)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName, curvature);
}

void SceneManager::SetSkyDome(bool enable, String^ materialName)
{
	DECLARE_NATIVE_STRING(o_materialName, materialName);

	_native->setSkyDome(enable, o_materialName);
}

void SceneManager::SetFog(Mogre::FogMode mode, Mogre::Color4 colour, Ogre::Real expDensity, Ogre::Real linearStart, Ogre::Real linearEnd)
{
	_native->setFog((Ogre::FogMode)mode, FromColor4(colour), expDensity, linearStart, linearEnd);
}

void SceneManager::SetFog(Mogre::FogMode mode, Mogre::Color4 colour, Ogre::Real expDensity, Ogre::Real linearStart)
{
	_native->setFog((Ogre::FogMode)mode, FromColor4(colour), expDensity, linearStart);
}

void SceneManager::SetFog(Mogre::FogMode mode, Mogre::Color4 colour, Ogre::Real expDensity)
{
	_native->setFog((Ogre::FogMode)mode, FromColor4(colour), expDensity);
}

void SceneManager::SetFog(Mogre::FogMode mode, Mogre::Color4 colour)
{
	_native->setFog((Ogre::FogMode)mode, FromColor4(colour));
}

void SceneManager::SetFog(Mogre::FogMode mode)
{
	_native->setFog((Ogre::FogMode)mode);
}

void SceneManager::SetFog()
{
	_native->setFog();
}

void SceneManager::ClearScene()
{
	_native->clearScene();
}

Mogre::SceneNode^ SceneManager::RootSceneNode::get()
{
	return ObjectTable::GetOrCreateObject<Mogre::SceneNode^>((intptr_t)_native->getRootSceneNode());
}

Ogre::SceneManager* SceneManager::UnmanagedPointer::get()
{
	return _native;
}
