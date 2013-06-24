#include "descriptivecheckbox.h"
#include <QEvent>

DescriptiveCheckBox::DescriptiveCheckBox(QWidget *parent) : QCheckBox(parent) {
  installEventFilter(this);
}

DescriptiveCheckBox::DescriptiveCheckBox(QString desc, QWidget* parent) : QCheckBox(parent) {
  installEventFilter(this);
  description = desc;
}

bool DescriptiveCheckBox::event(QEvent *e) {
  if (e->type() == QEvent::Enter) {
    emit descriptionSet(description);
    return true;
  }
  if (e->type() == QEvent::Leave) {
    emit descriptionSet(QString());
    return true;
  }
  return QCheckBox::event(e);
}
