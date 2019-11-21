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


#define MoveConst 8			// ��������� ��� ��������� y � x ��������� ��� ����������� ��������.
#define RotateConst 12		// ��������� ��� ��������� ����� ��� �������� ��������.	

#define EPSILON			0.1f
#define EPSREFR			0.00000000001f
#define MAXLVLRAY		10
#define PI				3.141592653589793238462f

//--------------�������--------------//
// ��������� �������� ��������� �����.
#define WLeft -25		// �������� � ����� ����� ����� �������.
#define WRight 25		// �������� � ����� ������ ����� �������.
#define HWall 40		// �������� Y ����� ������� ����� �������.
#define WFloor -4		// �������� Y ����� ������ ����� �������.
#define WWidth -80		// �������� Z ������ �����.
#define LenW  30			// �������� Z �������� �����.
//--------------�������--------------//


//--------------- ���� ------------- //

// ������������ ��������� � ���������� ���������.
#define SRel 0.1    //���������
#define SDif 0.9	//����������

#define YfootUp 1
#define YfootDown 5
#define XfootUp 1.5
#define XfootDown 0.5
#define ZfootUp 1.5
#define ZfootDown 0.5

#endif