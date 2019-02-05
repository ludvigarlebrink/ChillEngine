#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with two components.
 */
struct UTILS_API Vector2
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.  
     */
    Vector2();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector2(const Vector2& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     */
    Vector2(f32 x, f32 y);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector2(f32 uniform);

    /**
     * @brief Get the distance between two points.
     *
     * @param p1 First point.
     * @param p2 Second point.
     * @return Distance between two points.
     */
    static f32 distance(const Vector2& p1, const Vector2& p2);

    /**
     * @brief Get the distance between two points squared.
     *
     * @param p1 First point.
     * @param p2 Second point.
     * @return Distance between two points squared.
     */
    static f32 distanceSquared(const Vector2& p1, const Vector2& p2);

    /**
     * @brief Get the dot product of two vectors.
     *
     * @param v1 First vector.
     * @param v2 Second vector.
     * @retunr Dot product of two vectors.
     */
    static f32 dot(const Vector2& v1, const Vector2& v2);

    /**
     * @brief Normlizes this vector.
     */
    void normalize();

    /**
     * @brief Get the length of this vector.
     *
     * @return Length of the vector.
     */
    f32 length() const;

    /**
     * @brief Get the squared length of this vector.
     *
     * @return Squared length of the vector.
     */
    f32 lengthSquared() const;

    /**
     * @brief Get this vector as a nicely formated string: "(x, y)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector2& operator=(const Vector2& other);

    Vector2& operator+=(const Vector2& other);

    Vector2& operator-=(const Vector2& other);

    Vector2& operator*=(const Vector2& other);

    Vector2& operator/=(const Vector2& other);

    f32& operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Vector2(0, -1).
     */
    static const Vector2 DOWN;

    /**
     * @brief Shorthand for Vector2(-1, 0).
     */
    static const Vector2 LEFT;

    /**
     * @brief Shorthand for Vector2(1, 1).
     */
    static const Vector2 ONE;

    /**
     * @brief Shorthand for Vector2(1, 0).
     */
    static const Vector2 RIGHT;

    /**
     * @brief Shorthand for Vector2(0, 1).
     */
    static const Vector2 UP;

    /**
     * @brief Shorthand for Vector2(0, 0).
     */
    static const Vector2 ZERO;

    /**
     * @brief X component of a vector.
     */
    f32 x;

    /**
     * @brief Y component of a vector.
     */
    f32 y;
};

Vector2 operator+(const Vector2& lhs, const Vector2& rhs);

Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

Vector2 operator-(const Vector2& vector);

Vector2 operator*(const Vector2& lhs, const Vector2& rhs);

Vector2 operator*(const Vector2& lhs, f32 rhs);

Vector2 operator*(f32 lhs, const Vector2& rhs);

Vector2 operator/(const Vector2& lhs, const Vector2& rhs);

Vector2 operator/(const Vector2& lhs, f32 rhs);
} // namespace snack

/**
 * @struct chill::Vector2
 */