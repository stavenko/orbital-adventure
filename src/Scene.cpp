#include "Scene.hpp"

namespace oa {
namespace render {
void Scene::addMesh(Mesh* meshptr) {
  auto geometry = meshptr->getGeometry();
  auto shader = meshptr->getShader();
  shaders.emplace(shader);
  if (materialGeometryMap.count(shader) == 0)
    materialGeometryMap[shader] = std::set<geometry::Geometry*>();
  materialGeometryMap[shader].emplace(geometry);
  if (geometryMeshMap.count(geometry) == 0)
    geometryMeshMap[geometry] = std::set<Mesh*>();
  geometryMeshMap[geometry].emplace(meshptr);
}
const std::set<ShaderProgram*>& Scene::getAllShaders() { return shaders; }
const std::set<geometry::Geometry*>& Scene::getGeometries(
    const ShaderProgram* sp) {
  return materialGeometryMap[sp];
}
const std::set<Mesh*>& Scene::getMeshes(const geometry::Geometry* g) {
  return geometryMeshMap[g];
}
}
}