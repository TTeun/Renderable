#ifndef BALLRENDERABLE_H
#define BALLRENDERABLE_H

#include "surfacerenderable.h"
#include <QVector3D>
#include <cmath>

class BallRenderable : public SurfaceRenderable
{
public:
  BallRenderable();

  void setRadius(float _r);
  void setCenter(QVector3D &_c);
  void create();
  void renderSkeleton(QOpenGLFunctions_4_1_Core *glFunctions, QMatrix4x4 &projectionMatrix);

private:
  float m_radius = 1;
  float m_x      = 0;
  float m_y      = 0;
  float m_z      = 0;

  QVector3D atSphericalCoords(double polar_angle, double azi_angle);
};

#endif // BALLRENDERABLE_H
