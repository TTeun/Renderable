#include "renderlist.h"

RenderList::RenderList() : r(new SurfaceRenderable()), axis(new Axis()), m_frame(0)
{
}

void RenderList::initialize()
{
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  glEnable(GL_PRIMITIVE_RESTART);
  glPrimitiveRestartIndex(maxIndex);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  r->init(this);
  axis->init(this);
  qDebug() << "init";
}

void RenderList::render()
{
  const qreal retinaScale = devicePixelRatio();
  glViewport(0, 0, width() * retinaScale, height() * retinaScale);
  glClear(GL_COLOR_BUFFER_BIT);

  m_projectionMatrix.setToIdentity();
  m_projectionMatrix.perspective(80.0f, width() / static_cast<float>(height()), 0.1f, 100.0f);
  m_projectionMatrix.translate(0, 0, -2);
  m_projectionMatrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0.5, 0.4, 0);

  r->render(m_glFunctions, m_projectionMatrix);
  axis->render(m_glFunctions, m_projectionMatrix);

  ++m_frame;
}
