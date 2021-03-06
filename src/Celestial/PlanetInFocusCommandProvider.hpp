#pragma once
#include "../CommandProvider.hpp"
#include "CelestialCameraManager.hpp"
#include "InputListener.hpp"
#include "SolarSystem.hpp"

namespace oa {
namespace game {
class PlanetInFocusCommandProvider : public CommandProvider,
                                     public input::InputListener {
  const SolarSystem* solarSystem;
  CelestialCameraManager* cameraMgr;
  SolarSystem::CelestialMapRef planetMap;
  SolarSystem::CelestialMap::const_iterator currentIterator;

  void onKeyUp(int keyCode, int mods);
  void createCommand();

 public:
  PlanetInFocusCommandProvider(CommandAcceptor*, SolarSystem* ss,
                               CelestialCameraManager* cm);
};
}
}
