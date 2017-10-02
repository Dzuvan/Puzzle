#pragma once

#include <math.h>

class Vec2 {
    public:
        Vec2(){}
        Vec2(int x, int y): m_x(x), m_y(y) {}
        ~Vec2() {}

        int getX() { return m_x; }
        int getY() { return m_y; }

        void setX(int x) { m_x = x; }
        void setY(int y) { m_y = y; }

        int length() { return (int)sqrt(m_x * m_x + m_y * m_y); }

        Vec2 operator+(const Vec2& v2) const{return Vec2(m_x + v2.m_x, m_y + v2.m_y);}
        friend Vec2& operator+=(Vec2& v1, const Vec2& v2)
        {
            v1.m_x += v2.m_x;
            v1.m_y += v2.m_y;
            return v1;
        }

        Vec2 operator*(int scalar){return Vec2(m_x * scalar, m_y * scalar);}
        Vec2& operator*=(int scalar)
        {
            m_x *= scalar;
            m_y *= scalar;
            return *this;
        }

        Vec2 operator-(const Vec2& v2) const{return Vec2(m_x - v2.m_x, m_y - v2.m_y);}
        friend Vec2& operator-=(Vec2& v1, const Vec2& v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;
            return v1;
        }

        Vec2 operator/(int scalar){return Vec2(m_x / scalar, m_y / scalar);}
        Vec2& operator/=(int scalar)
        {
            m_x /= scalar;
            m_y /= scalar;
            return *this;
        }

        void normalize()
        {
            int l = length();
            if (l > 0) // we never want to attempt to divide by 0
            {
                (*this) *= 1 / l;
            }
        }
        
    private:
        int m_x;
        int m_y;
};
