#ifndef SURFACERENDERABLE_H
#define SURFACERENDERABLE_H

#include "renderable.h"

class SurfaceRenderable : public Renderable
{
public:
  SurfaceRenderable();
  ~SurfaceRenderable();

  void createBuffers(QOpenGLFunctions_4_1_Core *ui) override;
  void createShader(QObject *ui) override;
  void render(QOpenGLFunctions_4_1_Core *ui, QMatrix4x4 &projectionMatrix) override;

protected:
  GLint m_readNormalsUniform;
  QMatrix4x4 m_modelViewMatrix;

  unique_ptr<QVector<QVector3D>> m_vertices;
  unique_ptr<QVector<QVector4D>> m_colors;
  unique_ptr<QVector<QVector3D>> m_normals;
  unique_ptr<QVector<unsigned int>> m_indices;

  void updateBuffers(QOpenGLFunctions_4_1_Core *ui);
  void load_obj(const char *filename);

  uint m_coordsBO;
  uint m_colourBO;
  uint m_normalBO;
  uint m_indicesBO;

  struct State
  {
    GLenum polygonMode = GL_FILL;
    bool readNormals   = false;
  };
  State m_state;
  GLint m_frame = 0;
};

#endif // SURFACERENDERABLE_H
