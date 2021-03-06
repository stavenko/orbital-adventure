#pragma once
#include "Celestial/CameraControlCommandProvider.hpp"
#include "Celestial/CelestialCameraManager.hpp"
#include "Celestial/PlanetInFocusCommandProvider.hpp"
#include "Celestial/SolarSystem.hpp"
#include "CommandAcceptor.hpp"
#include "GameEventsCommandProvider.hpp"
#include "Gui/Gui.hpp"
#include "engine/Camera.hpp"
#include "engine/GLFWWrapper.hpp"
#include "engine/Renderer.hpp"
#include "engine/TextureCreator.hpp"

namespace oa {
namespace game {
class Game : public CommandAcceptor {
 public:
  Game();
  void init();
  void mainLoop();
  void stopGame();

 private:
  gui::Gui gui;
  typedef std::chrono::duration<double, std::ratio<1>> Duration;
  std::chrono::system_clock::time_point oldTimePoint;
  std::chrono::system_clock::time_point simulatatedTime;
  double timeMultiplier = 1.0;
  std::vector<std::unique_ptr<CommandProvider>> providers;
  std::vector<std::unique_ptr<render::TextureCreator>> textureCreators;
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
  void initTextureCreators();
  void prerender();
};
}
}
