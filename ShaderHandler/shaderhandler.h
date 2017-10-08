#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include "ShaderHandler/shader.h"
#include <QOpenGLShaderProgram>
#include <string>
#include <unordered_map>
#include <vector>

enum class UNIFORMS // Collect here all uniforms
{
  PROJECTION_MATRIX = 0,
  MODEL_VIEW_MATRIX,
  LIGHT_POSITION,
  NUM_UNIFORM_TYPE
};

class ShaderHandler
{
public:
  ShaderHandler();
  ~ShaderHandler();

  virtual void createShaders(QObject *obj);

  bool isInitialized() const;

  enum class SHADER_TYPE
  {
    BLACK = 0,
    NO_NORMALS,
    NORMALS,
    NUM_SHADER_TYPES
  };

  void bind(SHADER_TYPE type);
  std::unordered_map<UNIFORMS, std::string> uniformsNames;

private:
  std::vector<Shader *> m_shaders;
  bool m_isInitialized = false;
};

#endif // SHADERHANDLER_H
