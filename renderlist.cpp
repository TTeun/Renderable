#include "renderlist.h"

RenderList::RenderList()
    : m_mainShader(new MainShader(this)),
      m_blackShader(new BlackShader(this)),
      m_flatshader(new FlatShader(this)),
      m_normalShader(new NormalShader(this)),
      ball(new BallRenderable()),
      axis(new Axis())
{
  m_lightPos = QVector3D(0.0, 0.0, -4.0);
}

void RenderList::initialize()
{
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE_MINUS_DST_COLOR);
  glBlendEquation(GL_FUNC_ADD);

  //  glEnable(GL_DEPTH_TEST);
  //  glDepthFunc(GL_GREATER);

  createShaders();
  ball->init(this);
  ball->create();
  //  ball->load_obj("../Suzanne.obj");
  axis->init(this);
}

void RenderList::createShaders()
{
  m_mainShader->init();
  m_flatshader->init();
  m_normalShader->init();
  m_blackShader->init();
}

void RenderList::render()
{
  const qreal retinaScale = devicePixelRatio();
  glViewport(0, 0, width() * retinaScale, height() * retinaScale);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  m_projectionMatrix.setToIdentity();
  m_projectionMatrix.perspective(80.0f, width() / static_cast<float>(height()), 0.1f, 100.0f);
  m_projectionMatrix.translate(0, 0, -3);
  m_projectionMatrix.rotate(nsAngle / screen()->refreshRate(), 1, 0, 0);
  m_projectionMatrix.rotate(ewAngle / screen()->refreshRate(), 0, 1, 0);

  nsAngle += 20;
  ewAngle += 12;

  m_mainShader->bind();
  m_mainShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);
  ball->render(m_glFunctions, m_projectionMatrix);

  //  m_normalShader->bind();
  //  m_normalShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  //  ball->render(m_glFunctions, m_projectionMatrix);

  m_blackShader->bind();
  m_blackShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  ball->renderSkeleton(m_glFunctions, m_projectionMatrix);

  m_flatshader->bind();
  m_flatshader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  axis->render(m_glFunctions, m_projectionMatrix);
}
