#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "axis.h"
#include "ballrenderable.h"
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
  void render() override;

private:
  unique_ptr<SurfaceRenderable> ball;
  unique_ptr<Axis> axis;
  QMatrix4x4 m_projectionMatrix;
  float nsAngle = 0.0f;
  float ewAngle = 0.0f;
};

#endif // TRIANGLEWINDOW_H
