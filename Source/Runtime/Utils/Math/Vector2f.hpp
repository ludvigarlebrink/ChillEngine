#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with two components.
 */
struct UTILS_API Vector2f
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.  
     */
    Vector2f();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector2f(const Vector2f& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     */
    Vector2f(f32 x, f32 y);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector2f(f32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y)".
     *
     * @param vec String to create this vector from, format must be "(x, y)".
     */
    Vector2f(const std::string& vec);

    /**
     * @brief Get the angle in degrees between from and to.
     *
     * @param from Vector from which the angular difference is measured.
     * @param from Vector to which the angular difference is measured.
     * @return Angle in degrees between from and to.
     */
    static f32 angle(const Vector2f& from, const Vector2f& to);

    /**
     * @brief Get the distance between two points.
     *
     * @param p1 First point.
     * @param p2 Second point.
     * @return Distance between two points.
     */
    static f32 distance(const Vector2f& p1, const Vector2f& p2);

    /**
     * @brief Get the distance between two points squared.
     *
     * @param p1 First point.
     * @param p2 Second point.
     * @return Distance between two points squared.
     */
    static f32 distanceSquared(const Vector2f& p1, const Vector2f& p2);

    /**
     * @brief Get the dot product of two vectors.
     *
     * @param v1 First vector.
     * @param v2 Second vector.
     * @retunr Dot product of two vectors.
     */
    static f32 dot(const Vector2f& v1, const Vector2f& v2);

    /**
     * @brief Normlizes this vector.
     */
    void normalize();

    /**
     * @brief Creates a normalized version of this vector.
     *
     * @return A normalized version of this vector.
     */
    Vector2f normalized() const;

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

    Vector2f& operator=(const Vector2f& other);

    Vector2f& operator+=(const Vector2f& other);

    Vector2f& operator-=(const Vector2f& other);

    Vector2f& operator*=(const Vector2f& other);

    Vector2f& operator*=(f32 v);

    Vector2f& operator/=(const Vector2f& other);

    Vector2f& operator/=(f32 v);

    f32& operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Vector2f(0, -1).
     */
    static const Vector2f DOWN;

    /**
     * @brief Shorthand for Vector2f(-1, 0).
     */
    static const Vector2f LEFT;

    /**
     * @brief Shorthand for Vector2f(1, 1).
     */
    static const Vector2f ONE;

    /**
     * @brief Shorthand for Vector2f(1, 0).
     */
    static const Vector2f RIGHT;

    /**
     * @brief Shorthand for Vector2f(0, 1).
     */
    static const Vector2f UP;

    /**
     * @brief Shorthand for Vector2f(0, 0).
     */
    static const Vector2f ZERO;

    /**
     * @brief X component of a vector.
     */
    f32 x;

    /**
     * @brief Y component of a vector.
     */
    f32 y;
};

Vector2f operator+(const Vector2f& lhs, const Vector2f& rhs);

Vector2f operator-(const Vector2f& lhs, const Vector2f& rhs);

Vector2f operator-(const Vector2f& vector);

Vector2f operator*(const Vector2f& lhs, const Vector2f& rhs);

Vector2f operator*(const Vector2f& lhs, f32 rhs);

Vector2f operator*(f32 lhs, const Vector2f& rhs);

Vector2f operator/(const Vector2f& lhs, const Vector2f& rhs);

Vector2f operator/(const Vector2f& lhs, f32 rhs);
} // namespace chill

/**
 * @struct chill::Vector2i
 */
