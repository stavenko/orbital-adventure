#pragma once
#include "CameraControlCommandProvider.hpp"
#include "CelestialCameraManager.hpp"
#include "CommandAcceptor.hpp"
#include "GameEventsCommandProvider.hpp"
#include "PlanetInFocusCommandProvider.hpp"
#include "SolarSystem.hpp"
#include "engine/Camera.hpp"
#include "engine/GLFWWrapper.hpp"
#include "engine/Renderer.hpp"

namespace oa {
namespace game {
class Game : public CommandAcceptor {
 public:
  Game();
  void init();
  void mainLoop();
  void stopGame();

 private:
  std::vector<std::unique_ptr<CommandProvider>> providers;
  void initGLFW();
  void initSolarSystem();
  void initPlayer();
  bool isPlaying;
  void initCommandsInf();
  gl::GLFWWrapper *glfw;
  void deinit();
  std::unique_ptr<SolarSystem> solarSystem;
  render::Renderer renderer;
  CelestialCameraManager cameraManager;
};
}
}
