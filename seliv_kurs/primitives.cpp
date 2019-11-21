#include "stdafx.h"
#include "primitives.h"

// Поиск пересечения со сферой
// Конструктор полигона
// Поиск пересечения с полигоном
// Доступ к нормали полигона


void Trian::BigAxis(vector3 TriangleNormal, int &u, int &v)
{
	// Определяем большую ось проекции
	if (fabsf(TriangleNormal.x) > fabsf(TriangleNormal.y))
	{
		if (fabsf(TriangleNormal.x) > fabsf(TriangleNormal.z)) 
			k =  0; 
		else 
			k =  2;
	}
	else
		if (fabsf(TriangleNormal.y) > fabsf(TriangleNormal.z)) 
			k =  1; 
		else 
			k =  2;

	// Определяем координаты
	u = (k + 1) % 3;
	v = (k + 2) % 3;

}


// Поиск пересечения со сферой.
int Sphere::Intersect(Ray& CurrRay, float& Dist)
{
	vector3 v = CurrRay.GetOrigin() - SpCenter;
	float b = -v.Dot(CurrRay.GetDirection());
	float det = (b * b) - v.Dot(v) + SpSqRad;
	if (det > 0)
	{
		det = sqrtf( det );
		float i1 = b - det;
		float i2 = b + det;
		if (i2 > 0)
		{
			if (i1 < 0) 
			{
				if (i2 < Dist) 
				{
					Dist = i2;
					return INPRIM;
				}
			}
			else
			{
				if (i1 < Dist)
				{
					Dist = i1;
					return HIT;
				}
			}
		}
	}
	return MISS;
}

// Конструктор полигона
Trian::Trian( Vertex* V1, Vertex* V2, Vertex* V3 )
{
	TrVert[0] = V1;
	TrVert[1] = V2;
	TrVert[2] = V3;
	int u, v; // барицентрические координаты.

	// Расчёт координат векторов.
	vector3 A = TrVert[0]->GetPos();
	vector3 B = TrVert[1]->GetPos();
	vector3 C = TrVert[2]->GetPos();
	vector3 BA = B - A;
	vector3 CA = C - A;

	// Векторное произведение к плоскости треугольника.
	TriangleNormal = CA.VecMult(BA);

	// Рассчитываем значение свободного члена для будущих расчётов
	TriangleD = -TriangleNormal.x*A.x-TriangleNormal.y*A.y-TriangleNormal.z*A.z;

	// Определяем большую ось проекции
	BigAxis(TriangleNormal, u, v);



	// Преобразование треугольника в единичный.
	float kk = 1.0f / TriangleNormal.cell[k];
	nu = TriangleNormal.cell[u] * kk;
	nv = TriangleNormal.cell[v] * kk;
	nd = TriangleNormal.Dot( A ) * kk;


	// Записываем уравнения линий
	float reci = 1.0f / (CA.cell[u] *BA.cell[v] - CA.cell[v] * BA.cell[u]);
	// Первое ур-е линии.
	bnu = CA.cell[u] * reci;
	bnv = -CA.cell[v] * reci;
	// 2-e
	cnu = BA.cell[v] * reci;
	cnv = -BA.cell[u] * reci;
	TriangleNormal.Normalize();
}

// Поиск пересечения с полигоном.
int Trian::Intersect( Ray& CurrRay, float& Dist )
{
	unsigned int modulo[] = { 0, 1, 2, 0, 1 };

	int ku = modulo[k+1], kv = modulo[k+2];
	vector3 O = CurrRay.GetOrigin(), 
		D = CurrRay.GetDirection(), 
		A = TrVert[0]->GetPos();

	// Расчёт расстояния до плоскости треугольника.
	const float lnd = 1.0f / (D.cell[k] + nu * D.cell[ku] + nv * D.cell[kv]);
	const float t = (nd - O.cell[k] - nu * O.cell[ku] - nv * O.cell[kv]) * lnd;

	// Тест по расстоянию.
	if (!(Dist > t && t > 0)) 
		return MISS;

	// Расчёт точки пересечения.
	float hu = O.cell[ku] + t * D.cell[ku] - A.cell[ku];
	float hv = O.cell[kv] + t * D.cell[kv] - A.cell[kv];
	float beta = U = hv * bnu + hu * bnv;
	if (beta < 0) return MISS;
	float gamma = V = hu * cnu + hv * cnv;
	if (gamma < 0) return MISS;

	// координаты нормализованы, поэтому должны быть = 1
	if ((U + V) > 1) return MISS;

	Dist = t;
	return (D.Dot(TriangleNormal) > 0)?INPRIM:HIT;
}

// Доступ к нормали полигона.
vector3	Trian::GetNormal(vector3& a_Pos)
{		
	return TriangleNormal;
}

