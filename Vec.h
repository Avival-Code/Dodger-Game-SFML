#pragma once

template<typename V>
class Vec2
{
public:
	Vec2() = default;
	Vec2(V x_in, V y_in)
		:
		x( x_in ),
		y( y_in )
	{
	};
	Vec2(const Vec2<V>& rhs)
		:
		Vec2(rhs.x, rhs.y)
	{
	};
	Vec2<V>& operator=(const Vec2<V>& rhs)
	{
		x = rhs.x;
		y = rhs.y;

		return *this;
	};
	~Vec2()
	{};
	Vec2<V> operator+( const Vec2<V>& rhs)
	{
		x += rhs.x;
		y += rhs.y;
	}
	Vec2<V>& operator+=( const Vec2<V>& rhs)
	{
		return *this = *this + rhs;
	}
	Vec2<V> operator-(const Vec2<V>& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
	}
	Vec2<V>& operator-=(const Vec2<V>& rhs)
	{
		return *this = *this - rhs;
	}
	Vec2<V> operator*(const Vec2<V>& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
	}
	Vec2<V>& operator*=(const Vec2<V>& rhs)
	{
		return *this = *this * rhs;
	}
public:
	V x;
	V y;
};

typedef Vec2<int> Vei2;
typedef Vec2<float> Vef2;