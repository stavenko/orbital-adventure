#pragma once
#include <boost/property_tree/ptree.hpp>
#include <map>
#include "GLFWWrapper.hpp"
#include "Geometry.hpp"

namespace oa {
namespace render {
class GeometryManager {
  GeometryManager();
  std::map<std::string, std::unique_ptr<geometry::Geometry>> loadedGeometries;

 public:
  static GeometryManager* instance();
  geometry::Geometry* loadGeometry(boost::property_tree::ptree& geometryProps);
  geometry::Geometry* createSphereGeometry(double radius = 1.0f, int rings = 10,
                                           int segments = 10);
  geometry::Geometry* createSkyboxGeometry(float size);
  geometry::Geometry* createPatchGeometry();
};
}
}
