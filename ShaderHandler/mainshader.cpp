#include "mainshader.h"

MainShader::MainShader(QObject *parent) : QOpenGLShaderProgram(parent)
{
}

void MainShader::init()
{
  static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                                     "../Renderable/shaders/vertshader.glsl");
  static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                                                     "../Renderable/shaders/fragshader.glsl");
  static_cast<QOpenGLShaderProgram *>(this)->link();

  m_projecionMatrixUniform = uniformLocation("projectionMatrix");
  m_modelViewMatrixUniform = uniformLocation("modelViewMatrix");
  m_lightPosUniform        = uniformLocation("lightPos");
}

void MainShader::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
{
  setUniformValue(m_modelViewMatrixUniform, modelViewMatrix);
  setUniformValue(m_projecionMatrixUniform, projectionMatrix);
  setUniformValue(m_lightPosUniform, m_lightPosition);
}
