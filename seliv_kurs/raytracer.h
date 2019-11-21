#ifndef I_RAYTRACER_H
#define I_RAYTRACER_H

#include "Subsidiary.h"
#include "MathMod.h"


class Ray
{
public:
	Ray() : RayOrigin(vector3(0, 0, 0)), RayDirection(vector3(0, 0, 0)) {};
	Ray(vector3& Origin, vector3& Direction): RayOrigin(Origin), RayDirection(Direction) {}
	void SetOrigin(vector3& Origin) { RayOrigin = Origin; }
	void SetDirection(vector3& Direction) { RayDirection = Direction; }
	vector3& GetOrigin() { return RayOrigin; }
	vector3& GetDirection() { return RayDirection; }
private:
	vector3 RayOrigin;
	vector3 RayDirection;
};

class Scene;
class Primitive;
class Engine
{
public:
	Engine();
	~Engine();
	void SettingCanvas(Col* aCol, int Pct_Width, int Pct_Height);
	void Raytrace(Ray& CurrRay, Color& PixColor, int RayLevel, float koeff, float& Dist);
	Scene* GetScene() { return GlobalScene; }
	Primitive* Engine::SearchIntersect(const int kol, float& Dist, int &result, Ray & CurrRay);		
	void InitRender();
	void Render(float MoveX, float MoveY, float MoveZ, float AngX, 
		float AngY, System::Windows::Forms::ProgressBar ^prbar);

protected:
	float LeftX, LeftY, RightX, RightY, DeltaX, DeltaY, CurrX, CurrY;
	Scene* GlobalScene;
	Col* sCol;
	int SWidth, SHeight, LineID, PixID;
};




#endif