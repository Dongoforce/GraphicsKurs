#ifndef MYMATH_H
#define MYMATH_H

class vector3
{
public:
	vector3(): x(0.0f), y(0.0f), z(0.0f) {};
	vector3(float SetX, float SetY, float SetZ): x(SetX), y(SetY), z(SetZ) {};

	void Normalize() 
	{ 
		float len = 1.0f /(float)sqrt(x * x + y * y + z * z);
		x *= len; 
		y *= len; 
		z *= len; 
	}

	float Dot(vector3 V) 
	{ 
		return x*V.x + y*V.y + z*V.z; 
	}

	vector3 VecMult(vector3 b) 
	{ 
		return vector3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x); 
	}

	float Length()
	{
		return (sqrtf(x*x+y*y+z*z));
	}

	void operator +=(vector3& V)
	{ 
		x += V.x; 
		y += V.y;
		z += V.z;
	}

	void operator +=(vector3* V) 
	{ 
		x += V->x;
		y += V->y;
		z += V->z;
	}

	void operator -=(vector3& V) 
	{
		x -= V.x; 
		y -= V.y; 
		z -= V.z; 
	}

	void operator -=(vector3* V) 
	{
		x -= V->x; 
		y -= V->y; 
		z -= V->z; 
	}

	void operator *=(float f) 
	{
		x *= f; 
		y *= f;
		z *= f; 
	}

	void operator *=(vector3& V) 
	{ 
		x *= V.x; 
		y *= V.y;
		z *= V.z; 
	}

	void operator *=(vector3* V)
	{ 
		x *= V->x; 
		y *= V->y;
		z *= V->z; 
	}

	friend vector3 operator +(const vector3& v1, const vector3& v2) 
	{ 
		return vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); 
	}

	friend vector3 operator +(const vector3& v1, vector3* v2)
	{ 
		return vector3(v1.x + v2->x, v1.y + v2->y, v1.z + v2->z);
	}

	friend vector3 operator -(const vector3& v1, const vector3& v2) 
	{ 
		return vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}

	friend vector3 operator -(const vector3& v1, vector3* v2) 
	{ 
		return vector3(v1.x - v2->x, v1.y - v2->y, v1.z - v2->z);
	}

	friend vector3 operator *(const vector3& v, float f) 
	{ 
		return vector3(v.x * f, v.y * f, v.z * f); 
	}

	friend vector3 operator *(const vector3& v1, vector3& v2) 
	{ 
		return vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); 
	}

	friend vector3 operator *(float f, const vector3& v) 
	{ 
		return vector3(v.x * f, v.y * f, v.z * f);
	}
	union
	{
		struct 
		{ 
			float x, y, z; 
		};
		struct 
		{ 
			float r, g, b; 
		};
		struct 
		{ 
			float cell[3];
		};
	};
};

void RotVec(vector3 &v1, vector3 n, float delta);

typedef vector3 Color;

#endif