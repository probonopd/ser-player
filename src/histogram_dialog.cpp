// ---------------------------------------------------------------------
// Copyright (C) 2015 Chris Garry
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// ---------------------------------------------------------------------

#include <QDebug>

#include <Qt>
#include <QDesktopWidget>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "histogram_dialog.h"


c_histogram_dialog::c_histogram_dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Histogram"));
    QDialog::setWindowFlags(QDialog::windowFlags() & ~Qt::WindowContextHelpButtonHint);

    mp_histogram_Label = new QLabel;
    mp_histogram_Label->setPixmap(QPixmap(256, 150));

    QVBoxLayout *dialog_vlayout = new QVBoxLayout;
    dialog_vlayout->addWidget(mp_histogram_Label);
    dialog_vlayout->setMargin(0);
    dialog_vlayout->setSpacing(0);
   
    setLayout(dialog_vlayout);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}


void c_histogram_dialog::set_pixmap(QPixmap histogram)
{
    mp_histogram_Label->setPixmap(histogram);
}


void c_histogram_dialog::move_to_default_position()
{
    // Move the histogram to the top-right(ish) of the application window
    QDesktopWidget widget;
    int screen_right_edge = widget.availableGeometry().right();
    QPoint histogram_pos = parentWidget()->geometry().topRight();
    if ((histogram_pos.x() + frameGeometry().width()) > screen_right_edge) {
        int new_x = screen_right_edge - frameGeometry().width();
        histogram_pos.setX(new_x);
    }

    move(histogram_pos);
}
