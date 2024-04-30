#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    VALUE_REQUEST = 1,
    VALUE_ANSWER,
    PRINT_CLASSIC_REQUEST,
    PRINT_CANONIC_REQUEST,
    PRINT_ANSWER,
    DETERMINANT_REQUEST,
    TRANSPONED_REQUEST,
    RANG_REQUEST,
    DETERMINANT_ANSWER,
    TRANSPONED_ANSWER,
    RANG_ANSWER,
    SIZE_MATRIX
};
enum modes
{
    I_MODE=1,
    C_MODE,
    R_MODE
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
