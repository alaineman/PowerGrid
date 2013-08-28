/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
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
