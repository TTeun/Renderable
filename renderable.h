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

protected:
  friend class RenderList;
  QOpenGLShaderProgram *m_shaderProgram;
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
  GLint m_readNormalsUniform;
  QMatrix4x4 m_modelViewMatrix;

  unique_ptr<QVector<QVector3D>> m_vertices;
  unique_ptr<QVector<QVector4D>> m_colors;
  unique_ptr<QVector<QVector3D>> m_normals;
  unique_ptr<QVector<unsigned int>> m_indices;

  uint m_vao;
  uint m_coordsBO;
  uint m_colourBO;
  uint m_normalBO;
  uint m_indicesBO;

  GLint m_frame = 0;

  void createBuffers(QOpenGLFunctions_4_1_Core *ui);
  void updateBuffers(QOpenGLFunctions_4_1_Core *ui);
  void createShader(QObject *ui);
  virtual void render(QOpenGLFunctions_4_1_Core *ui, QMatrix4x4 &projectionMatrix);
  void load_obj(const char *filename);

  struct State
  {
    GLenum polygonMode = GL_FILL;
    bool readNormals   = false;
  };
  State m_state;
};

#endif // RENDERABLE_H
