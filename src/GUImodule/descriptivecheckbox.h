#ifndef DESCRIPTIVECHECKBOX_H
#define DESCRIPTIVECHECKBOX_H

#include <QCheckBox>

class DescriptiveCheckBox : public QCheckBox {
    Q_OBJECT
  private:
    QString description;
  public:
    explicit DescriptiveCheckBox(QWidget* parent = 0);
    explicit DescriptiveCheckBox(QString desc, QWidget *parent = 0);
    
    virtual bool event(QEvent *e);

    void setDescription(QString desc) { description = desc; }
    QString getDescription() { return description; }

  signals:
    void descriptionSet(QString description);
  public slots:
};

#endif // DESCRIPTIVECHECKBOX_H
