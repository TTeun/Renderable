#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "RenderableObjects/axis.h"
#include "RenderableObjects/ballrenderable.h"
#include "ShaderHandler/blackshader.h"
#include "ShaderHandler/mainshader.h"
#include "openglwindow.h"
#include <QVector>
#include <QtCore/qmath.h>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>
#include <memory>

class RenderList : public OpenGLWindow
{
public:
  RenderList();

  void initialize() override;
  void createShaders();
  void render() override;

private:
  MainShader *m_mainShader;
  BlackShader *m_blackShader;

  QVector3D m_lightPos;
  unique_ptr<BallRenderable> ball;
  unique_ptr<Axis> axis;
  QMatrix4x4 m_projectionMatrix;
  float nsAngle = 0.0f;
  float ewAngle = 0.0f;

  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
  GLint m_readNormalsUniform;
  GLint m_lightPosUniform;
};

#endif // TRIANGLEWINDOW_H
