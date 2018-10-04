#include "qdocker.h"
#include <QWidget>

QDocker::QDocker() {}

QDocker::QDocker(int distance) {
    m_distance = distance;
}

QDocker::~QDocker() {}

// private

void QDocker::resizeHorizontal(QWidget* qw, QWidget* qaw, HorizontalPos& pos) {
    switch (pos) {
        case HorizontalLeft: break;

        case HorizontalRight: {
            qw->move(qaw->x()+qaw->width()-qw->width(), qw->y());
        } break;

        case HorizontalCenter: {
           int center_anchor = qaw->x()+qaw->width()/2;
           int center = center_anchor-qw->width()/2;
           qw->move(center, qw->y());
        } break;
    }
}

void QDocker::resizeHorizontal(QWidget& qw, QWidget& qaw, HorizontalPos& pos) {
    switch (pos) {
        case HorizontalLeft: break;

        case HorizontalRight: {
            qw.move(qaw.x()+qaw.width()-qw.width(), qw.y());
        } break;

        case HorizontalCenter: {
           int center_anchor = qaw.x()+qaw.width()/2;
           int center = center_anchor-qw.width()/2;
           qw.move(center, qw.y());
        } break;
    }
}

void QDocker::resizeVertical(QWidget* qw, QWidget* qaw, VerticalPos& pos) {
    switch (pos) {
        case VerticalTop: break;

        case VerticalBottom: {
            qw->move(qw->x(), qaw->y()+qaw->height()-qw->height());
        } break;

        case VerticalCenter: {
            int center_anchor = qaw->y()+qaw->height()/2;
            int center = center_anchor-qw->height()/2;
            qw->move(qw->x(),center);
        } break;
    }
}

void QDocker::resizeVertical(QWidget& qw, QWidget& qaw, VerticalPos& pos) {
    switch (pos) {
        case VerticalTop: break;

        case VerticalBottom: {
            qw.move(qw.x(), qaw.y()+qaw.height()-qw.height());
        } break;

        case VerticalCenter: {
            int center_anchor = qaw.y()+qaw.height()/2;
            int center = center_anchor-qw.height()/2;
            qw.move(qw.x(),center);
        } break;
    }
}

// public

int QDocker::getDistance() {
    return m_distance;
}

void QDocker::setDistance(int distance) {
    m_distance = distance;
}

// for dynamic allocated widgets

void QDocker::dockAbove(QWidget* qw, QWidget* qaw,
                   HorizontalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw->move(qaw->x(), qaw->y()-qaw->height()-distance);
    resizeHorizontal(qw, qaw, pos);

}

void QDocker::dockBelow(QWidget* qw, QWidget* qaw,
                        HorizontalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw->move(qaw->x(), qaw->y()+qaw->height()+distance);
    resizeHorizontal(qw, qaw, pos);
}

void QDocker::dockLeft(QWidget* qw, QWidget* qaw,
                  VerticalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw->move(qaw->x()-qw->width()-distance, qaw->y());
    resizeVertical(qw, qaw, pos);
}

void QDocker::dockRight(QWidget* qw, QWidget* qaw,
                  VerticalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw->move(qaw->x()+qaw->width()+distance, qaw->y());
    resizeVertical(qw, qaw, pos);
}

// for stack based widgets

void QDocker::dockAbove(QWidget& qw, QWidget& qaw,
                   HorizontalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw.move(qaw.x(), qaw.y()-qaw.height()-distance);
    resizeHorizontal(qw, qaw, pos);
}

void QDocker::dockBelow(QWidget& qw, QWidget& qaw,
                        HorizontalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw.move(qaw.x(), qaw.y()+qaw.height()+distance);
    resizeHorizontal(qw, qaw, pos);
}

void QDocker::dockLeft(QWidget& qw, QWidget& qaw,
                  VerticalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw.move(qaw.x()-qw.width()-distance, qaw.y());
    resizeVertical(qw, qaw, pos);
}

void QDocker::dockRight(QWidget& qw, QWidget& qaw,
                  VerticalPos pos, int distance)
{
    if (m_distance > 0 && distance == 20) {
        distance = m_distance;
    }
    qw.move(qaw.x()+qaw.width()+distance, qaw.y());
    resizeVertical(qw, qaw, pos);
}
