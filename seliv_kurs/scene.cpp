#include "stdafx.h"
#include "Subsidiary.h"
#include "string.h"
#include "scene.h"
#include "raytracer.h"

// Установка координат.
// Прямоугольник из двух треугольников.
// Установка стен и пола.
// Установка льда.
// Установка гарды.
// Установка меча.
// Заполнение массива вершин.
// Перемещение источника света.
// Инициализация сцены.

Scene::~Scene()
{
	delete Obj_Prim;
	delete Obj_Light;
}

// Установка координат.
void SetCords(Cord &p1, Cord &p2, Cord &p3, Cord &p4,
	float x1, float y1, float z1, float x2, float y2, float z2,
	float x3, float y3, float z3,	float x4, float y4, float z4)
{
	p1.x = x1; p1.y = y1; p1.z = z1;
	p2.x = x2; p2.y = y2; p2.z = z2;
	p3.x = x3; p3.y = y3; p3.z = z3;
	p4.x = x4; p4.y = y4; p4.z = z4;
}

// Прямоугольник из двух треугольников.
void Scene::NewRect(int &Indx, Cord p1, Cord p2, Cord p3, Cord p4, Cord p5, Cord p6,
	int Vkol, Color color, float Refl, float Diff, float Refr, bool Refracting)
{
	// массив из вершин
	int vtemp = Vkol;
	v[Vkol++] = new Vertex( vector3(p1.x, p1.y, p1.z));
	v[Vkol++] = new Vertex( vector3(p2.x, p2.y, p2.z));
	v[Vkol++] = new Vertex( vector3(p3.x, p3.y, p3.z));
	v[Vkol++] = new Vertex( vector3(p4.x, p4.y, p4.z));
	v[Vkol++] = new Vertex( vector3(p5.x, p5.y, p5.z));
	v[Vkol++] = new Vertex( vector3(p6.x, p6.y, p6.z));

	// массив из треугольников
	Obj_Prim[Indx] = new Trian(v[vtemp], v[vtemp+1], v[vtemp+2]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection(Refl);
	Obj_Prim[Indx]->GetMaterial()->SetRefraction(Refr);
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse(Diff);
	Obj_Prim[Indx]->GetMaterial()->SetColor(Color(color));	
	NumOfPrims++;
	Indx++;

	Obj_Prim[Indx] = new Trian(v[vtemp+3], v[vtemp+4], v[vtemp+5]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection(Refl);
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse(Diff);
	Obj_Prim[Indx]->GetMaterial()->SetRefraction(Refr);
	Obj_Prim[Indx]->GetMaterial()->SetColor(Color(color));
	if (Refracting)
	{
		Obj_Prim[Indx]->SetType(4);
		Obj_Prim[Indx-1]->SetType(4);
	}
	else
	{
		Obj_Prim[Indx]->SetType(3);
		Obj_Prim[Indx-1]->SetType(3);
	}
	NumOfPrims++;
	Indx++;
}

// Установка стен и пола.
void Scene::WallAndFloor(float WDif, float WRefl, int &Indx)
{
	// Передняя стена.
	Obj_Prim[Indx] = new Trian(v[1], v[2], v[0]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->SetType(3);
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 48, 225, 200) );
	NumOfPrims++;
	Indx++;
	Obj_Prim[Indx] = new Trian(v[0], v[2], v[3]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->SetType(3);
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));

	NumOfPrims++;
	Indx++;

	// Пол
	Obj_Prim[Indx] = new Trian(v[4], v[6], v[5]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl);
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->SetType(3);
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));
	NumOfPrims++;
	Indx++;		
	Obj_Prim[Indx] = new Trian(v[8], v[9], v[7]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->SetType(3);
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));
	NumOfPrims++;
	Indx++;

	// Левая стена.
	Obj_Prim[Indx] = new Trian(v[18], v[14], v[19]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->SetType(3);
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));
	//Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 256, 256, 256) );
	NumOfPrims++;
	Indx++;
	Obj_Prim[Indx] = new Trian(v[17], v[16], v[15]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->SetType(3);
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));
	//Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 256, 256, 256) );
	NumOfPrims++;
	Indx++;

	// Правая стена.
	Obj_Prim[Indx] = new Trian(v[11], v[10], v[12]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));
	//Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 256, 256, 256) );
	NumOfPrims++;
	Indx++;
	Obj_Prim[Indx] = new Trian(v[13], v[12], v[10]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif ); 
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));
	//Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 256, 256, 256)  );
	NumOfPrims++;
	Indx++;

	// Задняя стена.
	Obj_Prim[Indx] = new Trian(v[23], v[21], v[22]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 213, 200));
	//Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 256, 256, 256) );
	NumOfPrims++;
	Indx++;
	Obj_Prim[Indx] = new Trian(v[23], v[22], v[24]);
	Obj_Prim[Indx]->GetMaterial()->SetReflection( WRefl );
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse( WDif );
	Obj_Prim[Indx]->GetMaterial()->SetColor( Color(48, 225, 200));
	//Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 256, 256, 256) );
	NumOfPrims++;
	Indx++;

}

// Установка шара.

void Scene::SetSphere(Color SphereCol, int& Indx)
{
	Cord p1, p2, p3, p4;
	float Refl = 0.0f;
	float Refr = 1.1f;

	Obj_Prim[Indx] = new Sphere(vector3(0, 9, 0), 9.0f);
	Obj_Prim[Indx]->GetMaterial()->SetReflection(Refl);
	Obj_Prim[Indx]->GetMaterial()->SetRefraction(Refr);
	Obj_Prim[Indx]->GetMaterial()->SetDiffuse(0.0f);
	Obj_Prim[Indx]->GetMaterial()->SetColor(SphereCol);
	Obj_Prim[Indx]->SetType(4);
	NumOfPrims++;
	Indx++;
}


// Установка ствола.
void Scene::TreeDown(int& Indx)
{
	Cord p1, p2, p3, p4;
	Color FootColor = Color( 150, 75, 0 );

	
	float TreeRefl = 0.0f, HandDif = 0.8f;

	SetCords(p1, p2, p3, p4,	XfootDown, YfootDown, ZfootUp,		XfootUp, YfootDown, ZfootDown,
		XfootUp,YfootUp, ZfootDown,			XfootDown, YfootUp, ZfootUp);
	NewRect(Indx,  p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);

	SetCords(p1, p2, p3, p4, XfootUp, YfootDown, ZfootDown, XfootUp, YfootDown, -ZfootDown,
		XfootUp, YfootUp, -ZfootDown, XfootUp, YfootUp, ZfootDown);
	NewRect(Indx, p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);
	
	SetCords(p1, p2, p3, p4, XfootUp, YfootDown, -ZfootDown, XfootDown, YfootDown, -ZfootUp,
		XfootDown, YfootUp, -ZfootUp, XfootUp, YfootUp, -ZfootDown);
	NewRect(Indx, p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);

	SetCords(p1, p2, p3, p4, XfootDown, YfootDown, -ZfootUp, -XfootDown, YfootDown, -ZfootUp,
		-XfootDown, YfootUp, -ZfootUp, XfootDown, YfootUp, -ZfootUp);
	NewRect(Indx, p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);

	SetCords(p1, p2, p3, p4, -XfootDown, YfootDown, -ZfootUp, -XfootUp, YfootDown, -ZfootDown,
		-XfootUp, YfootUp, -ZfootDown, -XfootDown, YfootUp, -ZfootUp);
	NewRect(Indx, p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);

	SetCords(p1, p2, p3, p4, -XfootUp, YfootDown, -ZfootDown, -XfootUp, YfootDown, ZfootDown,
		-XfootUp, YfootUp, ZfootDown, -XfootUp, YfootUp, -ZfootDown);
	NewRect(Indx, p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);

	SetCords(p1, p2, p3, p4, -XfootUp, YfootDown, ZfootDown, -XfootDown, YfootDown, ZfootUp,
		-XfootDown, YfootUp, ZfootUp, -XfootUp, YfootUp, ZfootDown);
	NewRect(Indx, p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);

	SetCords(p1, p2, p3, p4, -XfootDown, YfootDown, ZfootUp, XfootDown, YfootDown, ZfootUp,
		XfootDown, YfootUp, ZfootUp, -XfootDown, YfootUp, ZfootUp);
	NewRect(Indx, p1, p2, p3, p3, p4, p1, 44, FootColor, TreeRefl, HandDif, 0.0f, false);

}


// Установка Дерева.
void Scene::SetTree(int& Indx)
{// Установка Подставки.
	Obj_Prim[Indx] = new Trian(v[26], v[25], v[27]);
	Obj_Prim[Indx+1] = new Trian(v[28], v[27], v[25]);
	Obj_Prim[Indx+2] = new Trian(v[26], v[27], v[30]);   
	Obj_Prim[Indx+3] = new Trian(v[26], v[29], v[30]);
	Obj_Prim[Indx + 4] = new Trian(v[28], v[32], v[31]);
	Obj_Prim[Indx + 5] = new Trian(v[28], v[31], v[25]);
	Obj_Prim[Indx + 6] = new Trian(v[29], v[30], v[32]);
	Obj_Prim[Indx + 7] = new Trian(v[31], v[32], v[29]);
	Obj_Prim[Indx + 8] = new Trian(v[28], v[27], v[30]);
	Obj_Prim[Indx + 9] = new Trian(v[32], v[28], v[30]);
	//Установка листьев
	Obj_Prim[Indx + 10] = new Trian(v[35], v[34], v[43]);
	Obj_Prim[Indx + 11] = new Trian(v[36], v[35], v[43]);
	Obj_Prim[Indx + 12] = new Trian(v[37], v[36], v[43]);
	Obj_Prim[Indx + 13] = new Trian(v[38], v[37], v[43]);
	Obj_Prim[Indx + 14] = new Trian(v[39], v[38], v[43]);
	Obj_Prim[Indx + 15] = new Trian(v[40], v[39], v[43]);
	Obj_Prim[Indx + 16] = new Trian(v[41], v[40], v[43]);
	Obj_Prim[Indx + 17] = new Trian(v[34], v[41], v[43]);

	Obj_Prim[Indx + 18] = new Trian(v[35], v[34], v[42]);
	Obj_Prim[Indx + 19] = new Trian(v[36], v[35], v[42]);
	Obj_Prim[Indx + 20] = new Trian(v[37], v[36], v[42]);
	Obj_Prim[Indx + 21] = new Trian(v[38], v[37], v[42]);
	Obj_Prim[Indx + 22] = new Trian(v[39], v[38], v[42]);
	Obj_Prim[Indx + 23] = new Trian(v[40], v[39], v[42]);
	Obj_Prim[Indx + 24] = new Trian(v[41], v[40], v[42]);
	Obj_Prim[Indx + 25] = new Trian(v[34], v[41], v[42]);

	int TempInd = Indx+9;
	for(Indx; Indx <= TempInd; Indx++)
	{
		Obj_Prim[Indx]->GetMaterial()->SetReflection( 0.1f );
		Obj_Prim[Indx]->GetMaterial()->SetDiffuse( SDif );
		Obj_Prim[Indx]->GetMaterial()->SetRefraction(0.0f );
		Obj_Prim[Indx]->GetMaterial()->SetColor( Color( 30, 10, 5) );
	}			
	NumOfPrims += 10;

	int St = Indx + 16;
	for (Indx; Indx < St; Indx++)
	{
		Obj_Prim[Indx]->GetMaterial()->SetDiffuse(0.9f);
		Obj_Prim[Indx]->GetMaterial()->SetReflection(0.0);
		Obj_Prim[Indx]->GetMaterial()->SetColor(Color(1, 209, 1));
		Obj_Prim[Indx]->SetType(3);
	}
	NumOfPrims += 16;

	TreeDown(Indx);
}

// Заполнение массива вершин.
void Scene::SetVertices()
{
	// Передняя стена.
	v[0] = new Vertex( vector3(	WLeft, WFloor, LenW));
	v[1] = new Vertex( vector3(	-WLeft, WFloor, LenW));
	v[2] = new Vertex( vector3(	-WLeft,	HWall,	LenW));
	v[3] = new Vertex( vector3(WLeft,	HWall,	LenW));

	// Пол.
	v[4] = new Vertex( vector3(WLeft, WFloor, LenW));
	v[5] = new Vertex( vector3(-WLeft, WFloor, LenW));
	v[6] = new Vertex( vector3(WLeft, WFloor, WWidth));
	v[7] = new Vertex( vector3(-WLeft, WFloor, LenW));
	v[8] = new Vertex( vector3(WLeft, WFloor, WWidth));
	v[9] = new Vertex( vector3(-WLeft, WFloor, WWidth));

	// Правая стена.
	v[10] = new Vertex( vector3(-WLeft, WFloor, LenW));
	v[11] = new Vertex( vector3(-WLeft, HWall, LenW));
	v[12] = new Vertex( vector3(-WLeft,	HWall,	WWidth));
	v[13] = new Vertex( vector3(-WLeft,	WFloor,	WWidth));

	// Левая стена.
	v[14] = new Vertex( vector3(WLeft, WFloor, LenW));
	v[15] = new Vertex( vector3(WLeft,	HWall,	LenW));
	v[16] = new Vertex( vector3(WLeft, WFloor, WWidth));
	v[17] = new Vertex( vector3(WLeft, HWall, WWidth));
	v[18] = new Vertex( vector3(WLeft, WFloor, WWidth));
	v[19] = new Vertex( vector3(WLeft, HWall, LenW));

	// Задняя стена.
	v[20] = new Vertex( vector3(WLeft, HWall, WWidth));
	v[21] = new Vertex( vector3(-WLeft, WFloor, WWidth));
	v[22] = new Vertex( vector3(WLeft, WFloor, WWidth));
	v[23] = new Vertex( vector3(-WLeft, HWall, WWidth));
	v[24] = new Vertex( vector3(WLeft, HWall, WWidth));


	//Подставка
	v[25] = new Vertex( vector3(-5, -5, -5));
	v[26] = new Vertex( vector3(5, -5, -5));
	v[27] = new Vertex( vector3(3, 1, -4));
	v[28] = new Vertex( vector3(-3, 1, -4));
	v[29] = new Vertex( vector3(5, -5, 5));
	v[30] = new Vertex( vector3(3, 1, 4));
	v[31] = new Vertex( vector3(-5, -5, 5));
	v[32] = new Vertex( vector3(-3, 1, 4));
	v[33] = new Vertex( vector3(0, 1, 2));

	//Листья
	v[34] = new Vertex(vector3(3, 5, 5));
	v[35] = new Vertex(vector3(5, 5, 3));
	v[36] = new Vertex(vector3(5, 5, -3));
	v[37] = new Vertex(vector3(3, 5, -5));
	v[38] = new Vertex(vector3(-3, 5, -5));
	v[39] = new Vertex(vector3(-5, 5, -3));
	v[40] = new Vertex(vector3(-5, 5, 3));
	v[41] = new Vertex(vector3(-3, 5, 5));	
	v[42] = new Vertex(vector3(0, 5, 0));
	v[43] = new Vertex(vector3(0, 16, 0));
}


// Перемещение источника света.
void Scene::MoveLight(float LX, float LY, float LZ)
{
	Obj_Light[GetNumbL()-1]->SetLight(vector3(LX, LY, LZ));
}

// Инициализация сцены.
void Scene::InitScene()
{

	Obj_Prim = new Primitive*[100];
	Obj_Light = new Light*[1];

	// Инициализация индексов заполнения по массивам.
	int Indx = 0, vIndx = 0;

	// Количество источников освещения в сцене.
	int NumL = 0;

	// Заполнение массива вершин.
	SetVertices();	     		

	// Настройка стен и пола.
	float WDif =1.0f, WRefl = 0.0f;              //Коффициенты диффузии и отражения
	WallAndFloor(WDif, WRefl, Indx);	

	// Установка подставки.
	SetTree(Indx);

	// Установка сферы.
	Color SphereCol = Color(0.2f, 0.2f, 0.1f);
	//SetSphere(SphereCol, Indx);

	// Освещение
	Obj_Light[0] = new Light(vector3(-5,30, -45), Color( 1.0f, 1.0f, 1.0f) );
	NumL++;
	SetNumbL(NumL);




}






