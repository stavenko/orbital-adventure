#pragma once
#include "Camera.hpp"
#include "Filter.hpp"
#include "GLFWWrapper.hpp"
#include "Scene.hpp"
#include "TextureCreator.hpp"
#include "UniformHolder.hpp"

namespace oa {
namespace render {
class Renderer {
  struct RenderTargetsUniformInstaller : public UniformInstaller {
    std::map<std::string, GLuint> *map;
    bool *texturesUpdated;
    RenderTargetsUniformInstaller(std::map<std::string, GLuint> *, bool *,
                                  int *, int *);
    int *width, *height;
    void install(UniformHolder *, const Camera *, double);
  };
  GLuint framebuffer;
  GLuint depthbuffer;
  GLuint VertexArrayID;
  int width, height;
  bool texturesUpdated;
  std::vector<std::unique_ptr<Filter>> filters;
  // renderer owns all textures.
  std::map<std::string, GLuint> targets;
  std::string mainTarget = "mainRender";
  int lastTargetsAmount;

  void createFrameBuffer(bool);
  void startFBORendering();
  void renderFilters();

  void reinitFBOTargetTextures();
  void initFBOTargets(Filter *);
  void bindTargets(std::vector<std::string> &&ts);
  void bindTargets(std::vector<std::string> &ts);
  void updateUniformHolder();
  void resetRenderState();
  void bindVertexArrayBuffer();

 public:
  Renderer();
  void setupTarget(const std::string &name, int);
  void bindTarget(const std::string &name);
  void unbindTargets();
  void unbindFramebuffer();

  void pushFilter(Filter *);
  void setViewportDimentions(int width, int height);
  void render(TextureCreator *, UniformHolder *);
  void render(const Scene *, const Camera *);
  void renderSorted(const Scene *, const Camera *);
  void clearColor();
  void clearDepth();
};
}
}
