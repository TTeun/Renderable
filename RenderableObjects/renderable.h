#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <QOpenGLFunctions_4_1_Core>

class OpenGLWindow;

class Renderable
{
public:
  Renderable();
  ~Renderable();

  virtual void render(QOpenGLFunctions_4_1_Core *ui, QMatrix4x4 &projectionMatrix) = 0;
  virtual void init(OpenGLWindow *openGLWindow) = 0;

protected:
  virtual void createBuffers(QOpenGLFunctions_4_1_Core *ui) = 0;
  uint m_vao;
};

#endif // RENDERABLE_H
