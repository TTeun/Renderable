#include "flatshader.h"

FlatShader::FlatShader(QObject *parent) : QOpenGLShaderProgram(parent)
{
}

void FlatShader::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
{
  setUniformValue(m_modelViewMatrixUniform, modelViewMatrix);
  setUniformValue(m_projecionMatrixUniform, projectionMatrix);
}

void FlatShader::init()
{
  static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                                     "../Renderable/shaders/vert_flat.glsl");
  static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                                                     "../Renderable/shaders/frag_flat.glsl");
  static_cast<QOpenGLShaderProgram *>(this)->link();

  m_projecionMatrixUniform = uniformLocation("projectionMatrix");
  m_modelViewMatrixUniform = uniformLocation("modelViewMatrix");
}
