#include "shaderhandler.h"

using namespace std;

ShaderHandler::ShaderHandler()
{
}

ShaderHandler::~ShaderHandler()
{
}

void ShaderHandler::createShaders(QObject *obj)
{
  m_shaders.resize(static_cast<unsigned int>(ShaderHandler::SHADER_TYPE::NUM_SHADER_TYPES));
  m_shaders[0] = new Shader({{QOpenGLShader::Vertex, "../Renderable/shaders/vertshader.glsl"},
                             {QOpenGLShader::Fragment, "../Renderable/shaders/fragshader.glsl"}},
                            {"projectionMatrix", "modelViewMatrix", "readNormals", "lightPos"},
                            obj);
}

bool ShaderHandler::isInitialized() const
{
  return m_isInitialized;
}

void ShaderHandler::bind(ShaderHandler::SHADER_TYPE type)
{
  m_shaders[static_cast<uint>(type)]->shaderProgram()->bind();
}
