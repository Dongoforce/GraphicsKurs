#ifndef I_SCENE_H
#define I_SCENE_H

#include "raytracer.h"
#include "primitives.h"

class Scene
{
public:
	Scene(): NumOfPrims(0), Obj_Prim(0), 
		NumOfLights(0), Obj_Light(0) {};
	~Scene();
	void InitScene();

	int GetNumbP() {return NumOfPrims;}
	int GetNumbL() {return NumOfLights;}
	void SetNumbP(int Numb) {NumOfPrims = Numb;}
	void SetNumbL(int Numb) {NumOfLights = Numb;}
	Light* GetLight(int k) {return Obj_Light[k];}
	Primitive* GetPrimitive(int k) {return Obj_Prim[k];}

	void SetVertices();
	void MoveLight(float LX, float LY, float LZ);
	void TreeDown(int& Indx);
	void SetTree(int& Indx);
	void SetSphere(Color SphereCol, int& Indx);
	void WallAndFloor(float WDif, float WRefl, int &Indx);		
	void NewRect(int &Indx, Cord p1, Cord p2, Cord p3, Cord p4, 
		Cord p5, Cord p6,int Vkol, Color color, float Refl,
		float Diff, float Refr, bool Refracting);		
private:
	int NumOfPrims;
	int NumOfLights;
	Vertex* v[80];		
	Light **Obj_Light;
	Primitive** Obj_Prim;
};

#endif