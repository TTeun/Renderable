#include "renderlist.h"

RenderList::RenderList() : ball(new SurfaceRenderable()), axis(new Axis())
{
}

void RenderList::initialize()
{
  glEnable(GL_BLEND);
  glBlendEquationSeparate(GL_MIN, GL_MIN);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  //  glEnable(GL_CULL_FACE);
  //  glCullFace(GL_BACK);

  glEnable(GL_PRIMITIVE_RESTART);
  glPrimitiveRestartIndex(maxIndex);

  glPolygonMode(GL_FRONT, GL_FILL);

  ball->init(this);
  //  ball->create();
  ball->load_obj("../Suzanne.obj");
  axis->init(this);
}

void RenderList::render()
{
  const qreal retinaScale = devicePixelRatio();
  glViewport(0, 0, width() * retinaScale, height() * retinaScale);
  glClear(GL_COLOR_BUFFER_BIT);

  m_projectionMatrix.setToIdentity();
  m_projectionMatrix.perspective(80.0f, width() / static_cast<float>(height()), 0.1f, 100.0f);
  m_projectionMatrix.translate(0, 0, -4);
  m_projectionMatrix.rotate(nsAngle / screen()->refreshRate(), 1, 0, 0);
  m_projectionMatrix.rotate(ewAngle / screen()->refreshRate(), 0, 1, 0);

  nsAngle += 20;
  ewAngle += 12;

  ball->render(m_glFunctions, m_projectionMatrix);
  axis->render(m_glFunctions, m_projectionMatrix);
}
