#include "math.h"
// QANGLES
QAngle::QAngle() : pitch(0.f), yaw(0.f), roll(0.f) {}
QAngle::QAngle(float pitch, float yaw) : pitch(pitch), yaw(yaw), roll(0.f) {}
QAngle::QAngle(float pitch, float yaw, float roll) : pitch(pitch), yaw(yaw), roll(roll) {}

void QAngle::operator=(QAngle ang) {
	pitch = ang.pitch;
	yaw = ang.yaw;
	roll = ang.roll;
}
QAngle QAngle::operator+(QAngle ang) {
	return QAngle(pitch + ang.pitch, yaw + ang.yaw, roll + ang.roll);
}
QAngle QAngle::operator-(QAngle ang) {
	return QAngle(pitch - ang.pitch, yaw - ang.yaw, roll - ang.roll);
}
QAngle QAngle::operator*(QAngle ang) {
	return QAngle(pitch * ang.pitch, yaw * ang.yaw, roll * ang.roll);
}
QAngle QAngle::operator/(QAngle ang) {
	return QAngle(pitch / ang.pitch, yaw / ang.yaw, roll / ang.roll);
}
QAngle QAngle::operator+(float num) {
	return QAngle(pitch + num, yaw + num, roll + num);
}
QAngle QAngle::operator-(float num) {
	return QAngle(pitch - num, yaw - num, roll - num);
}
QAngle QAngle::operator*(float num) {
	return QAngle(pitch * num, yaw * num, roll * num);
}
QAngle QAngle::operator/(float num) {
	return QAngle(pitch / num, yaw / num, roll / num);
}
void QAngle::operator+=(QAngle ang) {
	pitch += ang.pitch;
	yaw += ang.yaw;
	roll += ang.roll;
}
void QAngle::operator-=(QAngle ang) {
	pitch -= ang.pitch;
	yaw -= ang.yaw;
	roll -= ang.roll;
}
void QAngle::operator*=(QAngle ang) {
	pitch *= ang.pitch;
	yaw *= ang.yaw;
	roll *= ang.roll;
}
void QAngle::operator/=(QAngle ang) {
	pitch /= ang.pitch;
	yaw /= ang.yaw;
	roll /= ang.roll; 
}
void QAngle::operator+=(float num) {
	pitch += num;
	yaw += num;
	roll += num;
}
void QAngle::operator-=(float num) {
	pitch -= num;
	yaw -= num;
	roll -= num;
}
void QAngle::operator*=(float num) {
	pitch *= num;
	yaw *= num;
	roll *= num;
}
void QAngle::operator/=(float num) {
	pitch /= num;
	yaw /= num;
	roll /= num;
}
float QAngle::operator[](int i) {
	if (i > 2 || i < 0)
		return 0.f;

	return i == 0 ? pitch : (i == 1 ? yaw : roll);
}
float QAngle::length2D() {
	return sqrt(pitch * pitch + yaw * yaw);
}
float QAngle::length() {
	return sqrt(pitch * pitch + yaw * yaw + roll * roll);
}



// VECTOR
Vector::Vector() : x(0.f), y(0.f), z(0.f) {}
Vector::Vector(float x, float y) : x(x), y(y), z(0.f) {}
Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

void Vector::operator=(Vector vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}
Vector Vector::operator+(Vector vec) {
	return Vector(x + vec.x, y + vec.y, z + vec.z);
}
Vector Vector::operator-(Vector vec) {
	return Vector(x - vec.x, y - vec.y, z - vec.z);
}
Vector Vector::operator*(Vector vec) {
	return Vector(x * vec.x, y * vec.y, z * vec.z);
}
Vector Vector::operator/(Vector vec) {
	return Vector(x / vec.x, y / vec.y, z / vec.z);
}
Vector Vector::operator+(float num) {
	return Vector(x + num, y + num, z + num);
}
Vector Vector::operator-(float num) {
	return Vector(x - num, y - num, z - num);
}
Vector Vector::operator*(float num) {
	return Vector(x * num, y * num, z * num);
}
Vector Vector::operator/(float num) {
	return Vector(x / num, y / num, z / num);
}
void Vector::operator+=(Vector vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
}
void Vector::operator-=(Vector vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}
void Vector::operator*=(Vector vec) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
}
void Vector::operator/=(Vector vec) {
	x /= vec.x;
	y /= vec.y;
	z /= vec.z;
}
void Vector::operator+=(float num) {
	x += num;
	y += num;
	z += num;
}
void Vector::operator-=(float num) {
	x -= num;
	y -= num;
	z -= num;
}
void Vector::operator*=(float num) {
	x *= num;
	y *= num;
	z *= num;
}
void Vector::operator/=(float num) {
	x /= num;
	y /= num;
	z /= num;
}
float Vector::operator[](int i) {
	if (i > 2 || i < 0)
		return 0.f;

	return i == 0 ? x : (i == 1 ? y : z);
}
float Vector::length2D() {
	return sqrt(x * x + y * y);
}
float Vector::length() {
	return sqrt(x * x + y * y + z * z);
}
float Vector::dotProduct(Vector vec) {
	return x * vec.x + y * vec.y + z * vec.z;
}

QAngle Vector::getForwardAngle(Vector vec) {
	Vector forward = (*this - vec);
	forward.normalizeVec();

	float yaw = RAD2DEG(atan2(forward.y, forward.x)); 
	float pitch = RAD2DEG(atan2(forward.z, Vector(forward.x, forward.y).length2D()));

	
	
	return QAngle(0, yaw, 0);
}

void Vector::normalizeVec() {
	float length = this->length();
	x /= length;
	y /= length;
	z /= length;
}