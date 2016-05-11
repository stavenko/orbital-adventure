#pragma once
#include <memory>
#include "Geometry.hpp"
#include "ShaderProgam.hpp"
#include "UniformHolder.hpp"
#include "UniformInstaller.hpp"
namespace oa {
namespace render {
class TextureCreator : public UniformHolder {
  std::vector<std::string> targets;
  bool needsDepthTest_;
  int width, height;
  ShaderProgram* shaderProgram;
  geometry::Geometry* geometry;
  std::vector<std::unique_ptr<UniformInstaller>> uniformInstallers;

 public:
  void addUniformInstaller(UniformInstaller*);
  void clearUniformInstallers();

  virtual std::vector<std::string>& getTargets();
  virtual bool needsDepthTest();
  virtual size_t supposedWidth();
  virtual size_t supposedHeight();
  TextureCreator(ShaderProgram*, std::string target);
  TextureCreator(ShaderProgram*, std::string target, bool needsDepthTest,
                 int width, int height);
  TextureCreator(ShaderProgram*, std::vector<std::string>& target,
                 bool needsDepthTest, int width, int height);
  virtual void render();
};
}
}
