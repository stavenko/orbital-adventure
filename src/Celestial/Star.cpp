#include "Star.hpp"
namespace oa {
namespace game {
bool Star::hasOrbit() { return false; }
Star::Star(double m, double r, std::string n) : CelestialObject(n, m, r) {}

glm::vec3 Star::getVelocity() { return glm::vec3(0); }
glm::vec3 Star::getPoint() { return glm::vec3(0); }
bool Star::hasAtmosphere() { return false; }
}
}
