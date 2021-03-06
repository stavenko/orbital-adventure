#pragma once
#include <boost/property_tree/ptree.hpp>
#include "IterativeTextureCreator.hpp"
#include "TextureCreator.hpp"
#include "UniformFabric.hpp"
#include "UniformInstallerFabric.hpp"
namespace oa {
namespace render {
class TextureCreatorFabric {
  std::string rootDir;
  std::string vShader;
  std::string gShader;
  std::unique_ptr<UniformInstallerFabric> uniformInstallerFabric;
  std::unique_ptr<UniformFabric> uniformFabric;
  GLenum getBlend(std::string);
  GLenum getBlendFunc(std::string);

 public:
  void setRootDir(std::string);
  void setDefaultVertexShaderPath(std::string);
  void setDefaultGeometryShaderPath(std::string);
  void setUniformInstallerFabric(UniformInstallerFabric*);
  void setUniformFabric(UniformFabric*);
  TextureCreator* make(boost::property_tree::ptree&);
};
}
}
