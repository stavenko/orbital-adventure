#pragma once
#include <string>
#include <map>
#include <memory>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include "CelestialObject.hpp"
#include "PlanetID.hpp"
#include "Mesh.hpp"

namespace oa {
namespace game {
typedef std::unique_ptr<CelestialObject> CelestialPtr;
typedef std::shared_ptr<render::Mesh> MeshPtr;
class SolarSystem {
 public:
  SolarSystem();
  void createPlanets();
  void updatePlanets(long);
  const std::map<PlanetID, MeshPtr> *const getCelestialMeshes() const;

 private:
  std::map<PlanetID, CelestialPtr> celestialsMap;
  std::map<PlanetID, MeshPtr> celestialMeshes;

  std::string planetFilePath;
  void parsePlanet(boost::property_tree::ptree::value_type &);
  MeshPtr createMesh(boost::property_tree::ptree meshDescription);
};
}
}
