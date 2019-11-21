#ifndef I_COMMON_H
#define I_COMMON_H

#include "math.h"
#include "stdlib.h"

typedef unsigned int Pixel;

struct Col
{
	int r,g,b;
};

struct NeedR
{
	bool f;
};

struct Cord
{
	float x, y, z;
};


#define MoveConst 8			// Константа для изменения y и x координат при перемещении кнопками.
#define RotateConst 12		// Константа для изменения углов при повороте кнопками.	

#define EPSILON			0.1f
#define EPSREFR			0.00000000001f
#define MAXLVLRAY		10
#define PI				3.141592653589793238462f

//--------------Комната--------------//
// Константы значений граничных точек.
#define WLeft -25		// Значение Х самой левой точки комнаты.
#define WRight 25		// Значение Х самой правой точки комнаты.
#define HWall 40		// Значение Y самой верхней точки комнаты.
#define WFloor -4		// Значение Y самой нижней точки комнаты.
#define WWidth -80		// Значение Z задней стены.
#define LenW  30			// Значение Z передней стены.
//--------------Комната--------------//


//--------------- Ёлка ------------- //

// Коэффициенты отражения и диффузного освещения.
#define SRel 0.1    //Отражение
#define SDif 0.9	//Поглощение

#define YfootUp 1
#define YfootDown 5
#define XfootUp 1.5
#define XfootDown 0.5
#define ZfootUp 1.5
#define ZfootDown 0.5

#endif