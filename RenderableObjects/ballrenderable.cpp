#include "ballrenderable.h"

BallRenderable::BallRenderable()
{
}

void BallRenderable::setRadius(float _r)
{
  m_radius = _r;
}

void BallRenderable::setCenter(QVector3D &_c)
{
  m_x = _c[0];
  m_y = _c[1];
  m_z = _c[2];
}

QVector3D BallRenderable::atSphericalCoords(double polar_angle, double azi_angle)
{
  return QVector3D(cos(polar_angle) * sin(azi_angle), sin(polar_angle) * sin(azi_angle), cos(azi_angle));
}

void BallRenderable::create()
{
  m_vertices->clear();
  m_vertices->squeeze();
  m_colors->clear();
  m_colors->squeeze();
  m_normals->clear();
  m_normals->squeeze();
  m_indices->clear();
  m_indices->squeeze();

  size_t polar_slices = 20;
  size_t azi_slices   = 10;
  uint index;

  double d_polar = 2 * M_PI / static_cast<double>(polar_slices);
  double d_azi   = M_PI / static_cast<double>(azi_slices);
  double polar_angle;
  double azi_angle;

  for (size_t polar = 0; polar != polar_slices; ++polar)
  {
    polar_angle = polar * d_polar;
    for (size_t azi = 0; azi != azi_slices; ++azi)
    {
      azi_angle = azi * d_azi;

      index = m_vertices->size();
      m_vertices->append(m_radius * atSphericalCoords(polar_angle, azi_angle));
      m_vertices->append(m_radius * atSphericalCoords(polar_angle + d_polar, azi_angle));
      m_vertices->append(m_radius * atSphericalCoords(polar_angle + d_polar, azi_angle + d_azi));
      m_vertices->append(m_radius * atSphericalCoords(polar_angle, azi_angle + d_azi));

      m_indices->append(index);
      m_indices->append(index + 1);
      m_indices->append(index + 2);

      m_indices->append(index);
      m_indices->append(index + 2);
      m_indices->append(index + 3);
    }
  }

  for (size_t i = 0; i != m_vertices->size(); ++i)
  {
    m_colors->append(QVector4D(0.9, 0.9, 0.9, 0.2));
    m_normals->append(m_vertices->at(i));
  }
}

void BallRenderable::renderSkeleton(QOpenGLFunctions_4_1_Core *glFunctions, QMatrix4x4 &projectionMatrix)
{
  glFunctions->glBindVertexArray(m_vao);

  updateBuffers(glFunctions);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glFunctions->glDrawElements(GL_TRIANGLES, m_indices->size(), GL_UNSIGNED_INT, 0);
}
