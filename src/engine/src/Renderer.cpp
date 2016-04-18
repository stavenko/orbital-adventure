#include <iostream>
#include "Renderer.hpp"
namespace oa {
namespace render {
Renderer::Renderer() {}

void Renderer::render(const Scene *scene, const Camera *camera) {
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  for (auto sp : scene->getAllShaders()) {
    glUseProgram(sp->getProgramId());
    for (auto g : scene->getGeometries(sp)) {
      g->setBuffers();
      for (auto m : scene->getMeshes(g)) {
        m->setupUniforms(camera->getProjectionMatrix(), camera->getMatrix());
        g->render();
      }
      g->unsetBuffers();
    }
  }
}
}
}
