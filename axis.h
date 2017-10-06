#ifndef AXIS_H
#define AXIS_H

#include "renderable.h"
#include <memory>

class Axis : public Renderable
{
public:
  Axis();
  ~Axis();

  virtual void render(QOpenGLFunctions_4_1_Core *glFunctions, QMatrix4x4 &projectionMatrix);
  virtual void init(OpenGLWindow *openGLWindow);

protected:
  std::unique_ptr<QVector<QVector3D>> m_vertices;
  std::unique_ptr<QVector<QVector3D>> m_colors;

  uint m_coordsBO;
  uint m_colourBO;

  QMatrix4x4 m_modelViewMatrix;
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;

  virtual void createBuffers(QOpenGLFunctions_4_1_Core *glFunctions);
  virtual void createShader(QObject *obj);
};

#endif // AXIS_H
