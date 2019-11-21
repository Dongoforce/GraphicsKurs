#include "stdafx.h"
#include "raytracer.h"
#include "scene.h"
#include "Subsidiary.h"
#include "windows.h"
#include "winbase.h"

// ��������� ������
// ����� ���������� ���������.
// �������� ����������� ����.
// ������� ������� ������������ �������.
// ��������� ������ ��������.


void Engine::Render(float MoveX, float MoveY, float MoveZ, float AngX, 
	float AngY, System::Windows::Forms::ProgressBar ^prbar)
{
	// ��������� ������. �������������� ���������.
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


// ����� ���������� ���������.
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
			result = res; // 0 = �� ����������, 1 = ����������, -1 = ����� ������
		}
	}
	return prim;
}

// �������� ����������� ����.
// ����: ������� ���, ���� �������, ������� ��������
// �����: ���� �������
void Engine::Raytrace( Ray& CurrRay, Color& PixColor, int RayLevel, float koeff, float& Dist )
{

	// ��� ���������� ������� �������� �������.
	if (RayLevel > MAXLVLRAY)  return ;

	Dist = 1000000.0f;
	Primitive* prim = 0;
	int result;								 
	int PrimCnt = GlobalScene->GetNumbP();   // ���������� �������� � �����.
	int LightCnt = GlobalScene->GetNumbL();  // ���������� ���������� �����.

	// ���� ���� �����������, �������.
	if (!(prim = SearchIntersect(PrimCnt, Dist, result, CurrRay)))
		return ;


	vector3	NewRay = CurrRay.GetOrigin() + CurrRay.GetDirection() * Dist; // ������ �� ������ �� ���������� ���������.
	Color color = prim->GetColor();										  // ���� ���������� ���������.


	for ( int i = 0; i < LightCnt; i++ )
	{
		Light* light = GlobalScene->GetLight(i);
		float shade = 1.0f;
		vector3 LightToPrim = light->GetCentre() - NewRay;
		float tdist = LightToPrim.Length();
		LightToPrim *= (1.0f / tdist);

		// ��� �� ��������� ����� �� �����, ������� ���������� ��������� ���. ������� �����.
		Ray r = Ray( NewRay + LightToPrim, LightToPrim );

		for ( int j = 0; j < PrimCnt; j++ )
		{
			Primitive* pr = GlobalScene->GetPrimitive(j); // ������ �� ���� ��������

			// ���� ��� �� ��������� ����� �� ������ ���������� ���������
			// ���������� �� ���� ������ ��������, �� ����� ����.
			if ((pr->Intersect( r, tdist )!=0) && (pr->GetType() != 4))
			{
				shade = 0;
				break;
			}
		}

		if (shade > 0)   // ���� ������ �� � ����.
		{
			// ��������� ���������. ��������� ������ ���� �� ���������� ���������, ��������				
			if (prim->GetMaterial()->GetDiffuse() > 0)
			{
				vector3 N = prim->GetNormal(NewRay); 
				float dot = LightToPrim.Dot(N); // ��������� ���������, �������� ������ �������
				if (dot > 0) 
				{
					float diff = dot * prim->GetMaterial()->GetDiffuse();
					PixColor += diff*light->GetColor() *color;
				}
			}					
		}
	}

	// ���������� ���������.	
	
	float refl = prim->GetMaterial()->GetReflection();
	if ((refl > 0.0f)&&(RayLevel < MAXLVLRAY))   // ���� �������� ��������, �� ��� ������.
	{
		vector3 N = prim->GetNormal( NewRay );

		// ������� ��������� ������ �� ������� R=V-2(V*N)*N;
		vector3 R = CurrRay.GetDirection() - 2.0f * CurrRay.GetDirection().Dot(N) * N;

		// ���������� ��������� ���.
		Color rcol( 0, 0, 0 );
		float dist;
		Raytrace( Ray( NewRay + R, R ), rcol, RayLevel + 1, koeff, dist );
		PixColor += refl * rcol * prim->GetMaterial()->GetColor();
	}
	


	// ���������� �����������
	float refr = prim->GetMaterial()->GetRefraction();
	if ((refr > 0) && (RayLevel < MAXLVLRAY))
	{
		float n = koeff/refr;
		vector3 N = prim->GetNormal( NewRay ) * (float)result;    // ������� � ��������� ������� ���� ����
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



// ������� ������� ������������ �������.
void RotVec(vector3 &v1, vector3 n, float delta)
{
	float tx = v1.x, ty= v1.y, tz = v1.z;
	float cd = cos(delta);
	float sd = sin(delta);
	v1.x = (cd+(1-cd)*n.x*n.x)*tx + ((1-cd)*n.x*n.y-sd*n.z)*ty+((1-cd)*n.x*n.z+sd*n.y)*tz;
	v1.y = ((1-cd)*n.y*n.x+sd*n.z)*tx+(cd+(1-cd)*n.y*n.y)*ty+((1-cd)*n.z*n.y-sd*n.x)*tz;
	v1.z = ((1-cd)*n.z*n.x-sd*n.y)*tx+((1-cd)*n.z*n.y+sd*n.x)*ty+(cd+(1-cd)*n.z*n.z)*tz;
}


// ��������� ������ �����.
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

// ��������� ������ ��������.
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