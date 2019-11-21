#include "stdafx.h"
#include "raytracer.h"
#include "scene.h"
#include "Subsidiary.h"
#include "windows.h"
#include "winbase.h"

// Настройка камеры
// Поиск ближайшего примитива.
// Обратная трассировка луча.
// Поворот вектора относительно вектора.
// Установка экрана проекции.


void Engine::Render(float MoveX, float MoveY, float MoveZ, float AngX, 
	float AngY, System::Windows::Forms::ProgressBar ^prbar)
{
	// Настройки камеры. Преобразования координат.
	vector3 o(MoveX, MoveY, MoveZ);
	vector3 ny(0, 1, 0 );
	vector3 nx(-1, 0, 0 );
	RotVec(nx, ny, AngX*PI/180);

	vector3 temp, dir;
	int red, green, blue;

	PixID = 0;
	for ( int y = 0; y < SHeight; y++ )
	{
		CurrX = LeftX;
		for ( int x = 0; x < SWidth; x++ )
		{		
			temp = vector3( CurrX, CurrY, 10 );
			RotVec(temp, ny, AngX*PI/180);
			RotVec(temp, nx, AngY*PI/180);
			temp += vector3(MoveX, MoveY, MoveZ);
			dir = temp-o;
			dir.Normalize();
			Ray r( o, dir );			
			float dist;
			Color PixCol( 0, 0, 0 );
			Raytrace( r, PixCol, 1, 1.0f, dist);
			red = PixCol.r;
			green = PixCol.g;
			blue = PixCol.b;

			if ((red > 255)|| (red < 0))  red = 255;
			if ((green > 255) ||(green<0)) green = 255;
			if ((blue > 255)||(blue<0)) blue = 255;
			sCol[PixID].b = blue;
			sCol[PixID].r = red;
			sCol[PixID].g = green;
			PixID++;
			CurrX += DeltaX;
			prbar->Value++;
		}
		CurrY += DeltaY;
	}
}


// Поиск ближайшего примитива.
Primitive* Engine::SearchIntersect(const int kol, float& Dist, int &result, Ray & CurrRay)
{
	Primitive* prim;
	for ( int s = 0; s < kol; s++ )
	{
		Primitive* pr = GlobalScene->GetPrimitive(s);
		int res;
		if (res = pr->Intersect(CurrRay, Dist)) 
		{
			prim = pr;
			result = res; // 0 = не пересекает, 1 = пересекает, -1 = лежит внутри
		}
	}
	return prim;
}

// Обратная трассировка луча.
// Вход: Текущий луч, Цвет пикселя, Уровень рекурсии
// Выход: цвет пиксела
void Engine::Raytrace( Ray& CurrRay, Color& PixColor, int RayLevel, float koeff, float& Dist )
{

	// При превышение глубины рекурсии выходим.
	if (RayLevel > MAXLVLRAY)  return ;

	Dist = 1000000.0f;
	Primitive* prim = 0;
	int result;								 
	int PrimCnt = GlobalScene->GetNumbP();   // Количество объектов в сцене.
	int LightCnt = GlobalScene->GetNumbL();  // Количество источников света.

	// Если нету пересечений, выходим.
	if (!(prim = SearchIntersect(PrimCnt, Dist, result, CurrRay)))
		return ;


	vector3	NewRay = CurrRay.GetOrigin() + CurrRay.GetDirection() * Dist; // Вектор от камеры до ближайшего примитива.
	Color color = prim->GetColor();										  // Цвет ближайшего примитива.


	for ( int i = 0; i < LightCnt; i++ )
	{
		Light* light = GlobalScene->GetLight(i);
		float shade = 1.0f;
		vector3 LightToPrim = light->GetCentre() - NewRay;
		float tdist = LightToPrim.Length();
		LightToPrim *= (1.0f / tdist);

		// Луч от источника света до точки, которую пересекает первичный луч. Теневой фронт.
		Ray r = Ray( NewRay + LightToPrim, LightToPrim );

		for ( int j = 0; j < PrimCnt; j++ )
		{
			Primitive* pr = GlobalScene->GetPrimitive(j); // проход по всем объектам

			// Если луч от источника света до нашего ближайшего примитива
			// пересекает по пути другой примитив, то будет тень.
			if ((pr->Intersect( r, tdist )!=0) && (pr->GetType() != 4))
			{
				shade = 0;
				break;
			}
		}

		if (shade > 0)   // Если объект не в тени.
		{
			// диффузное освещение. учитывает только лучи от источников освещения, закраска				
			if (prim->GetMaterial()->GetDiffuse() > 0)
			{
				vector3 N = prim->GetNormal(NewRay); 
				float dot = LightToPrim.Dot(N); // скалярное умножение, остается только косинус
				if (dot > 0) 
				{
					float diff = dot * prim->GetMaterial()->GetDiffuse();
					PixColor += diff*light->GetColor() *color;
				}
			}					
		}
	}

	// Вычисление отражения.	
	
	float refl = prim->GetMaterial()->GetReflection();
	if ((refl > 0.0f)&&(RayLevel < MAXLVLRAY))   // Если материал отражает, то идём дальше.
	{
		vector3 N = prim->GetNormal( NewRay );

		// Находим отражённый вектор по формуле R=V-2(V*N)*N;
		vector3 R = CurrRay.GetDirection() - 2.0f * CurrRay.GetDirection().Dot(N) * N;

		// Трассируем отражённый луч.
		Color rcol( 0, 0, 0 );
		float dist;
		Raytrace( Ray( NewRay + R, R ), rcol, RayLevel + 1, koeff, dist );
		PixColor += refl * rcol * prim->GetMaterial()->GetColor();
	}
	


	// Вычисление преломления
	float refr = prim->GetMaterial()->GetRefraction();
	if ((refr > 0) && (RayLevel < MAXLVLRAY))
	{
		float n = koeff/refr;
		vector3 N = prim->GetNormal( NewRay ) * (float)result;    // нормаль к плоскости раздела двух сред
		float cosI = -N.Dot(CurrRay.GetDirection());
		float cosT2 = 1.0f - n * n * (1.0f - cosI * cosI);
		if (cosT2 > 0.0f)
		{
			vector3 T = (n * CurrRay.GetDirection()) + (n * cosI - sqrtf( cosT2 )) * N;
			Color rcol( 0, 0, 0 );
			float dist;
			Raytrace( Ray( NewRay + T*EPSREFR, T ), rcol, RayLevel + 1, refr, dist );
			Color absorbance = prim->GetMaterial()->GetColor() * 0.1f * -dist;
			Color transparency = Color(expf( absorbance.r ), expf( absorbance.g ), expf( absorbance.b ));
			PixColor += rcol*transparency;
		}
	}
}



// Поворот вектора относительно вектора.
void RotVec(vector3 &v1, vector3 n, float delta)
{
	float tx = v1.x, ty= v1.y, tz = v1.z;
	float cd = cos(delta);
	float sd = sin(delta);
	v1.x = (cd+(1-cd)*n.x*n.x)*tx + ((1-cd)*n.x*n.y-sd*n.z)*ty+((1-cd)*n.x*n.z+sd*n.y)*tz;
	v1.y = ((1-cd)*n.y*n.x+sd*n.z)*tx+(cd+(1-cd)*n.y*n.y)*ty+((1-cd)*n.z*n.y-sd*n.x)*tz;
	v1.z = ((1-cd)*n.z*n.x-sd*n.y)*tx+((1-cd)*n.z*n.y+sd*n.x)*ty+(cd+(1-cd)*n.z*n.z)*tz;
}


// Установка буфера кадра.
void Engine::SettingCanvas(Col* aCol, int Pct_Width, int Pct_Height )
{
	sCol = aCol;
	SWidth = Pct_Width;
	SHeight = Pct_Height;
}

Engine::Engine()
{
	GlobalScene = new Scene();
}

// Установка экрана проекции.
void Engine::InitRender()
{	
	LeftX = -4, RightX = 4, LeftY = CurrY = 3, RightY = -3;
	DeltaX = (RightX - LeftX) / (SWidth);
	DeltaY = (RightY - LeftY) / (SHeight);
}

Engine::~Engine()
{
	delete GlobalScene;
}