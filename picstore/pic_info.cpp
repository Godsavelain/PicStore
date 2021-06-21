#include "pic_info.h"

pic_info::pic_info()
{

}
pic_info::Set_pic_info(int num1, QString addr1, QString artist1, QString name1,QString time1,int hot1){
    num = num1;
    addr = addr1;
    artist = artist1;
    name = name1;
    time = time1;
    hot = hot1;
}
