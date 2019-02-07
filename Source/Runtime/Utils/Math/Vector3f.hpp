#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with three components.
 */
struct UTILS_API Vector3f
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector3f();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector3f(const Vector3f& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     * @param z Value of the z component.
     */
    Vector3f(f32 x, f32 y, f32 z);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector3f(f32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y, z)".
     *
     * @param str String to create this vector from, format must be "(x, y, z)".
     */
    Vector3f(const std::string& str);

    /**
     * @brief Get the angle in degrees between from and to.
     *
     * @param from Vector from which the angular difference is measured.
     * @param from Vector to which the angular difference is measured.
     * @return Angle in degrees between from and to.
     */
    static f32 angle(const Vector3f& from, const Vector3f& to);

    /**
     * @brief Get the cross product of two vectors.
     *
     * @param v1 First vector.
     * @param v2 Second vector.
     * @retunr Cross product of two vectors.
     */
    static Vector3f cross(const Vector3f& lhs, const Vector3f& rhs);

    /**
     * @brief Clamp this vector.
     *
     * @param min Minimum value of this vector.
     * @param max Maximum value of this vector.
     */
    void clamp(const Vector3f& min, const Vector3f& max);

    /**
     * @brief Get the distance between two points.
     *
     * @param p1 First point.
     * @param p2 Second point.
     * @return Distance between two points.
     */
    static f32 distance(const Vector3f& p1, const Vector3f& p2);

    /**
     * @brief Get the distance between two points squared.
     *
     * @param p1 First point.
     * @param p2 Second point.
     * @return Distance between two points squared.
     */
    static f32 distanceSquared(const Vector3f& p1, const Vector3f& p2);

    /**
     * @brief Get the dot product of two vectors.
     *
     * @param v1 First vector.
     * @param v2 Second vector.
     * @retunr Dot product of two vectors.
     */
    static f32 dot(const Vector3f& lhs, const Vector3f& rhs);

    /**
     * @brief Get the length of this vector.
     *
     * @return Length of this vector.
     */
    f32 length() const;

    /**
     * @brief Get the squared length of this vector.
     *
     * @return Squared length of this vector.
     */
    f32 lengthSquared() const;

    /**
     * @param Linear interpolation between two vectors.
     *
     * @param start Start vector.
     * @param end End vector.
     * @param t Interpolation value.
     * @return A linear interpolated vector.
     */
    static Vector3f lerp(const Vector3f& start, const Vector3f& end, f32 t);

    /**
     * @param Normalized linear interpolation between two vectors.
     *
     * @param start Start vector.
     * @param end End vector.
     * @param t Interpolation value.
     * @return A normalized linear interpolated vector.
     */
    static Vector3f nlerp(const Vector3f& start, const Vector3f& end, f32 t);

    /**
     * @brief Normlizes this vector.
     */
    void normalize();

    /**
     * @brief Creates a normalized version of this vector.
     *
     * @return A normalized version of this vector.
     */
    Vector3f normalized() const;

    static Vector3f slerp(const Vector3f& start, const Vector3f& end, f32 t);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y, z)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector3f& operator=(const Vector3f& other);

    Vector3f& operator+=(const Vector3f& other);

    Vector3f& operator-=(const Vector3f& other);

    Vector3f& operator*=(const Vector3f& other);

    Vector3f& operator*=(f32 v);

    Vector3f& operator/=(const Vector3f& other);

    Vector3f& operator/=(f32 v);

    f32& operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Vector2f(0, 0, -1).
     */
    static const Vector3f BACK;

    /**
     * @brief Shorthand for Vector2f(0, -1, 0).
     */
    static const Vector3f DOWN;

    /**
     * @brief Shorthand for Vector2f(0, 0, 1).
     */
    static const Vector3f FORWARD;

    /**
     * @brief Shorthand for Vector2f(-1, 0, 0).
     */
    static const Vector3f LEFT;

    /**
     * @brief Shorthand for Vector2f(1, 1, 1).
     */
    static const Vector3f ONE;

    /**
     * @brief Shorthand for Vector2f(1, 0, 0).
     */
    static const Vector3f RIGHT;

    /**
     * @brief Shorthand for Vector2f(0, 1, 0).
     */
    static const Vector3f UP;

    /**
     * @brief Shorthand for Vector2f(0, 0, 0).
     */
    static const Vector3f ZERO;

    /**
     * @brief X component of this vector.
     */
    f32 x;

    /**
     * @brief Y component of this vector.
     */
    f32 y;

    /**
     * @brief Z component of this vector.
     */
    f32 z;
};

Vector3f operator+(const Vector3f& lhs, const Vector3f& rhs);

Vector3f operator-(const Vector3f& lhs, const Vector3f& rhs);

Vector3f operator-(const Vector3f& vector);

Vector3f operator*(const Vector3f& lhs, const Vector3f& rhs);

Vector3f operator*(const Vector3f& lhs, f32 rhs);

Vector3f operator*(f32 lhs, const Vector3f& rhs);

Vector3f operator/(const Vector3f& lhs, const Vector3f& rhs);

Vector3f operator/(const Vector3f& lhs, f32 rhs);
} // namespace chill

/**
 * @struct chill::Vector3f
 */
