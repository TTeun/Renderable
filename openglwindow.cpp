#include "openglwindow.h"
#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

GLuint const OpenGLWindow::maxIndex = static_cast<unsigned int>(-1);

OpenGLWindow::OpenGLWindow(QWindow *parent) : QWindow(parent), m_context(0), m_animating(false), m_device(0)
{
  setSurfaceType(QWindow::OpenGLSurface);
}

OpenGLWindow::~OpenGLWindow()
{
  delete m_device;
}

void OpenGLWindow::render(QPainter *painter)
{
  Q_UNUSED(painter);
}

void OpenGLWindow::initialize()
{
}

void OpenGLWindow::render()
{
  if (!m_device)
    m_device = new QOpenGLPaintDevice;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

  m_device->setSize(size());

  QPainter painter(m_device);
  render(&painter);
}

void OpenGLWindow::renderLater()
{
  requestUpdate();
}

bool OpenGLWindow::event(QEvent *event)
{
  switch (event->type())
  {
  case QEvent::UpdateRequest:
    renderNow();
    return true;
  default:
    return QWindow::event(event);
  }
}

void OpenGLWindow::exposeEvent(QExposeEvent *event)
{
  Q_UNUSED(event);

  if (isExposed())
    renderNow();
}

void OpenGLWindow::renderNow()
{
  if (!isExposed())
    return;

  bool needsInitialize = false;

  if (!m_context)
  {
    m_context = new QOpenGLContext(this);
    m_context->setFormat(requestedFormat());
    m_context->create();

    needsInitialize = true;
  }

  m_context->makeCurrent(this);
  m_glFunctions = m_context->versionFunctions<QOpenGLFunctions_4_1_Core>();

  if (needsInitialize)
  {
    if (not initializeOpenGLFunctions())
      qDebug() << "Could not initialized OpenGlFunctions";

    initialize();
  }
  glClearColor(1.0, 1.0, 1.0, 1.0);
  render();

  m_context->swapBuffers(this);

  if (m_animating)
    renderLater();
}

void OpenGLWindow::setAnimating(bool animating)
{
  m_animating = animating;

  if (animating)
    renderLater();
}
