#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include "raytracer.h"
#include "MathMod.h"

#define HIT		 1		
#define MISS	 0		
#define INPRIM	-1		

class Material
{
public:
	void SetColor( Color& NewColor ) { MatColor = NewColor; }
	Color GetColor() { return MatColor; }
	void SetDiffuse( float SetDiff ) { MatDiff = SetDiff; }		// рассеивание \ диффузное отражение
	void SetReflection( float SetRefl ) { MatRefl = SetRefl; }  // отражение
	void SetRefraction(float SetRefr){MatRefr = SetRefr;}		// преломление
	float GetRefraction(){return MatRefr;}
	float GetDiffuse() { return MatDiff; }
	float GetReflection() { return MatRefl; }

private:
	Color MatColor;
	float MatRefl;
	float MatDiff;
	float MatRefr;
};

class Light
{
public:
	Light(vector3& SetCentre, Color& SetLCol ) : LCentre( SetCentre ), LCol( SetLCol ){};
	vector3& GetCentre() { return LCentre; }
	void SetLight(vector3& NewPos) {LCentre = NewPos;}
	Color& GetColor() { return LCol; }
private:
	vector3 LCentre;
	Color LCol;
};


class Vertex
{
public:
	Vertex() {};
	Vertex(vector3 NewPos) : VertPos( NewPos ){};
	vector3& GetPos() { return VertPos; }
	void SetPos(vector3& NewPos) { VertPos = NewPos; }
private:
	vector3 VertPos;
};


class Primitive
{
public:
	enum
	{
		SPHERE		= 1,
		PLANE		= 2,
		TRIANGLE	= 3,
		TRREFR		= 4
	};
	Material* GetMaterial() { return &Mat; }
	void SetMaterial(Material& SetMat) { Mat = SetMat; }
	virtual int GetType() = 0;
	virtual void SetType(int kk){Ttype = kk;}
	virtual int Intersect(Ray& CurrRay, float& Dist) = 0;
	virtual vector3 GetNormal(vector3& Pos) = 0;
	Color GetColor() {return Mat.GetColor(); }

protected:
	Material Mat;
	int Ttype;
};


class Trian : public Primitive
{
public:
	Trian(Vertex* V1, Vertex* V2, Vertex* V3);
	int GetType() { return Ttype; }
	void BigAxis(vector3 TriangleNormal, int &u, int &v);
	void SetType(int SetTType) {Ttype = SetTType;}	
	int Intersect( Ray& CurrRay, float& Dist);
	vector3 GetNormal(vector3& a_Pos);

private:						
	Vertex* TrVert[3];	
	int Ttype;
	float U, V;							
	float nu, nv, nd;						
	int k;		
	vector3 TriangleNormal;
	float TriangleD;
	float bnu, bnv;							
	float cnu, cnv;							
};

class Sphere : public Primitive
{
public:
	Sphere(vector3& SetCenter, float SetRad): SpCenter(SetCenter), SpSqRad(SetRad * SetRad), 
		SpRad(SetRad) {};
	int GetType() { return Ttype; }
	vector3& GetCentre() { return SpCenter; }
	void SetType(int SetTType) { Ttype = SetTType; }
	float GetSqRadius() { return SpSqRad; }
	int Intersect(Ray& CurrRay, float& Dist);
	vector3 GetNormal(vector3& CurrPos) { return (CurrPos - SpCenter) * (1.0f / SpRad); }

private:
	vector3 SpCenter;
	float SpSqRad, SpRad;
};

#endif