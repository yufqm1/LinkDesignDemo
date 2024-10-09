#ifndef LINKDESIGN_COMMON_H
#define LINKDESIGN_COMMON_H

#include<QVector>

enum class ItemType {
    NoType,
    SubArray,       // 子阵
    PhaseShifter,   // 移相器
    Attenuator,     // 衰减器
    Amplifier,      // 放大器
    WaveFilter,     // 滤波器
    Mixer,          // 混频器
};

enum class DataType
{
    Name = Qt::UserRole,
    ComType,


};

#endif // LINKDESIGN_COMMON_H
