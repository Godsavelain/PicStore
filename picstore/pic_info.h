#ifndef PIC_INFO_H
#define PIC_INFO_H
#include <QString>

class pic_info
{
public:
    pic_info();
    Set_pic_info(int num, QString addr, QString artist, QString name,QString time,int hot);

    int num;
    QString addr;
    QString artist;
    QString name;
    QString time;
    int hot;
private:

};

#endif // PIC_INFO_H
