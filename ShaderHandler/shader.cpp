#include "shader.h"
#include <QDebug>
#include <stdexcept>

using namespace std;

Shader::Shader(std::initializer_list<std::pair<QOpenGLShader::ShaderTypeBit, const char *>> &&sources,
               std::initializer_list<const char *> uniforms,
               QObject *obj)
{
  m_shaderProgram = new QOpenGLShaderProgram(obj);
  for (auto const &pair : sources)
    m_shaderProgram->addShaderFromSourceFile(pair.first, pair.second);

  m_shaderProgram->link();

  GLint uniformLocation;
  for (auto const &uni : uniforms)
  {
    uniformLocation = m_shaderProgram->uniformLocation(uni);
    qDebug() << uniformLocation;
    m_uniforms.insert(make_pair(uni, uniformLocation));
  }
  qDebug() << "New shader program created";
}

template <typename T> void Shader::setUniform(const char *uniform, const T &value)
{
  if (m_uniforms.find(uniform) == m_uniforms.end())
    throw string("Trying to set uniform that is not set");

  m_shaderProgram->setUniformValue(m_uniforms[uniform], value);
}

QOpenGLShaderProgram *Shader::shaderProgram()
{
  return m_shaderProgram;
}
