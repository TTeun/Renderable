#ifndef SURFACERENDERABLE_H
#define SURFACERENDERABLE_H

#include "renderable.h"
#include <QMatrix4x4>
#include <QVector3D>
#include <QVector4D>
#include <QVector>
#include <QWindow>
#include <memory>

using namespace std;

class SurfaceRenderable : public Renderable
{
public:
  SurfaceRenderable();
  ~SurfaceRenderable();

  void init(OpenGLWindow *openGLWindow) override;
  void render(QOpenGLFunctions_4_1_Core *ui, QMatrix4x4 &projectionMatrix) override;
  void load_obj(const char *filename);

protected:
  void createBuffers(QOpenGLFunctions_4_1_Core *ui) override;
  void createShader(QObject *obj) override;

  unique_ptr<QVector<QVector3D>> m_vertices;
  unique_ptr<QVector<QVector4D>> m_colors;
  unique_ptr<QVector<QVector3D>> m_normals;
  unique_ptr<QVector<unsigned int>> m_indices;

  void updateBuffers(QOpenGLFunctions_4_1_Core *ui);

  uint m_coordsBO;
  uint m_colourBO;
  uint m_normalBO;
  uint m_indicesBO;

  QMatrix4x4 m_modelViewMatrix;
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
  GLint m_readNormalsUniform;
  GLint m_lightPosUniform;
  QVector3D m_lightPos;

  struct State
  {
    GLenum polygonMode = GL_FILL;
    bool readNormals   = false;
  };
  State m_state;
  GLint m_frame = 0;
};

#endif // SURFACERENDERABLE_H
