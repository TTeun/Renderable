#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLShaderProgram>
#include <initializer_list>
#include <string>
#include <tuple>
#include <unordered_map>

class Shader
{
public:
  Shader() = delete;
  Shader(std::initializer_list<std::pair<QOpenGLShader::ShaderTypeBit, const char *>> &&sources,
         std::initializer_list<const char *> uniforms,
         QObject *obj);

  QOpenGLShaderProgram *shaderProgram();

private:
  QOpenGLShaderProgram *m_shaderProgram;
  std::unordered_map<char const *, GLint> m_uniforms;

  template <typename T> void setUniform(char const *uniform, T const &value);
};

#endif // SHADER_H
