#include "layout.h"
#include <QHBoxLayout>

Layout::Layout(QWidget *parent) : QDialog (parent){


    label = new QLabel;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);

    setLayout(layout);

}

void Layout::setMobile()
{
   QString fileName = ":/resources/icon/mobile.jpg";
    if (!fileName.isEmpty()){

        /** set content to show center in label */
        label->setAlignment(Qt::AlignCenter);
        QPixmap pix;

        /** to check wether load ok */
        if(pix.load(fileName)){
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            label->setPixmap(pix);
            label->setScaledContents(true);
        }
    }
}

void Layout::setWeb()
{
   QString fileName = ":/resources/icon/web.jpg";
    if (!fileName.isEmpty()){

        /** set content to show center in label */
        label->setAlignment(Qt::AlignCenter);
        QPixmap pix;

        /** to check wether load ok */
        if(pix.load(fileName)){
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            label->setPixmap(pix);
            label->setScaledContents(true);
        }
    }
}

void Layout::setIDE()
{
   QString fileName = ":/resources/icon/ide.jpg";
    if (!fileName.isEmpty()){

        /** set content to show center in label */
        label->setAlignment(Qt::AlignCenter);
        QPixmap pix;

        /** to check wether load ok */
        if(pix.load(fileName)){
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            label->setPixmap(pix);
            label->setScaledContents(true);
        }
    }
}

void Layout::setCLI()
{
   QString fileName = ":/resources/icon/cli.jpg";
    if (!fileName.isEmpty()){

        /** set content to show center in label */
        label->setAlignment(Qt::AlignCenter);
        QPixmap pix;

        /** to check wether load ok */
        if(pix.load(fileName)){
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            label->setPixmap(pix);
            label->setScaledContents(true);
        }
    }
}
