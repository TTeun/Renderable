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

  QMatrix4x4 *modelViewMatrix() const;
  void setModelViewMatrix(QMatrix4x4 *modelViewMatrix);

protected:
  void createBuffers(QOpenGLFunctions_4_1_Core *ui) override;

  unique_ptr<QVector<QVector3D>> m_vertices;
  unique_ptr<QVector<QVector4D>> m_colors;
  unique_ptr<QVector<QVector3D>> m_normals;
  unique_ptr<QVector<unsigned int>> m_indices;

  void updateBuffers(QOpenGLFunctions_4_1_Core *ui);

  uint m_coordsBO;
  uint m_colourBO;
  uint m_normalBO;
  uint m_indicesBO;

  QMatrix4x4 *m_modelViewMatrix;
};

#endif // SURFACERENDERABLE_H
