#pragma once
#include <cmath>
#define PI 3.1415927f
#define RAD2DEG(rad) rad*(180.f/PI)
#define DEG2RAD(deg) deg*(PI/180.f)

class QAngle
{
public:
	float pitch, yaw, roll;

	QAngle();
	QAngle(float pitch, float yaw);
	QAngle(float pitch, float yaw, float roll);


	void operator=(QAngle ang);
	QAngle operator+(QAngle ang);
	QAngle operator-(QAngle ang);
	QAngle operator*(QAngle ang);
	QAngle operator/(QAngle ang);
	QAngle operator+(float num);
	QAngle operator-(float num);
	QAngle operator*(float num);
	QAngle operator/(float num);
	void operator+=(QAngle ang);
	void operator-=(QAngle ang);
	void operator*=(QAngle ang);
	void operator/=(QAngle ang);
	void operator+=(float num);
	void operator-=(float num);
	void operator*=(float num);
	void operator/=(float num);
	float operator[](int i);
	float length2D();
	float length();
};

class Vector
{
public:
	float x, y, z;

	Vector();
	Vector(float x, float y);
	Vector(float x, float y, float z);


	void operator=(Vector vec);
	Vector operator+(Vector vec);
	Vector operator-(Vector vec);
	Vector operator*(Vector vec);
	Vector operator/(Vector vec);
	Vector operator+(float num);
	Vector operator-(float num);
	Vector operator*(float num);
	Vector operator/(float num);
	void operator+=(Vector vec);
	void operator-=(Vector vec);
	void operator*=(Vector vec);
	void operator/=(Vector vec);	
	void operator+=(float num);
	void operator-=(float num);
	void operator*=(float num);
	void operator/=(float num);
	float operator[](int i);
	float length2D();
	float length();
	float dotProduct(Vector vec);
	QAngle getForwardAngle(Vector vec);
	void normalizeVec();
};

