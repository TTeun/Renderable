#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <QMatrix4x4>
#include <QOpenGLFunctions_4_1_Core>
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <QVector4D>
#include <QVector>
#include <QWindow>
#include <memory>

using namespace std;

class Renderable
{
public:
  Renderable();
  ~Renderable();

  virtual void createBuffers(QOpenGLFunctions_4_1_Core *ui) = 0;
  virtual void createShader(QObject *ui)                    = 0;
  virtual void render(QOpenGLFunctions_4_1_Core *ui, QMatrix4x4 &projectionMatrix) = 0;

protected:
  QOpenGLShaderProgram *m_shaderProgram;
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;

  uint m_vao;
};

#endif // RENDERABLE_H
