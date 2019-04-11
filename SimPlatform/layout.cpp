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
   QString fileName = ":/resources/icon/mobile.jpg"; // Mobile picture - Free Stock Photo
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
