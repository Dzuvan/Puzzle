#pragma once

#include <math.h>

class Vector2D {
private:
	int m_x;
	int m_y;
public:
	Vector2D() {}
	Vector2D(int x, int y) : m_x(x), m_y(y) {}
	
	int get_x() { return m_x; }
	int get_y() { return m_y; }

	void set_x(int x) { m_x = x; }
	void set_y(int y) { m_y = y; }

	Vector2D operator+(const Vector2D& v2) const {
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}
	friend Vector2D operator+=(Vector2D& v1, const Vector2D& v2) {
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	Vector2D operator*(int scalar) {
		return Vector2D(m_x * scalar, m_y * scalar);
	}
	Vector2D& operator*=(int scalar) {
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}
	Vector2D operator-(const Vector2D& v2) const {
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}
	friend Vector2D operator-=(Vector2D& v1, const Vector2D& v2) {
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}
	
	int length() {
		return (int)sqrt(m_x * m_x + m_y * m_y);
	}
	void normalize() {
		int l = length();
		if (l > 0) {
			(*this) *= 1 / l;
		}
	}
};