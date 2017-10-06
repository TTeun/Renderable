#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "openglwindow.h"
#include "surfacerenderable.h"
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
  unique_ptr<SurfaceRenderable> r;
  QMatrix4x4 m_projectionMatrix;
  int m_frame;
};

#endif // TRIANGLEWINDOW_H
