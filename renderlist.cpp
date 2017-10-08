#include "renderlist.h"

RenderList::RenderList()
    : m_mainShader(new MainShader(this)),
      m_blackShader(new BlackShader(this)),
      ball(new BallRenderable()),
      axis(new Axis())
{
  m_lightPos = QVector3D(0.0, 0.0, 1.0);
}

void RenderList::initialize()
{
  glEnable(GL_BLEND);
  glBlendEquationSeparate(GL_MIN, GL_MIN);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  glEnable(GL_PRIMITIVE_RESTART);
  glPrimitiveRestartIndex(maxIndex);

  glPolygonMode(GL_FRONT, GL_FILL);

  createShaders();
  ball->init(this);
  ball->create();
  //  ball->load_obj("../Suzanne.obj");
  axis->init(this);
}

void RenderList::createShaders()
{
  m_mainShader->init();
  m_blackShader->init();
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

  m_mainShader->bind();
  m_mainShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  ball->render(m_glFunctions, m_projectionMatrix);

  m_blackShader->bind();
  m_blackShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  ball->renderSkeleton(m_glFunctions, m_projectionMatrix);

  m_mainShader->bind();
  axis->render(m_glFunctions, m_projectionMatrix);
}
