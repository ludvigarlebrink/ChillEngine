#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with three components.
 */
struct UTILS_API Vector3i
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector3i();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector3i(const Vector3i& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     * @param z Value of the z component.
     */
    Vector3i(int32 x, int32 y, int32 z);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector3i(int32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y, z)".
     *
     * @param vec String to create this vector from, format must be "(x, y, z)".
     */
    Vector3i(const std::string& vec);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector3i& operator=(const Vector3i& other);

    Vector3i& operator+=(const Vector3i& other);

    Vector3i& operator-=(const Vector3i& other);

    Vector3i& operator*=(const Vector3i& other);

    Vector3i& operator*=(int32 v);

    Vector3i& operator/=(const Vector3i& other);

    Vector3i& operator/=(int32 v);

    int32& operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Vector2f(0, 0, -1).
     */
    static const Vector3i BACK;

    /**
     * @brief Shorthand for Vector2f(0, -1, 0).
     */
    static const Vector3i DOWN;

    /**
     * @brief Shorthand for Vector2f(0, 0, 1).
     */
    static const Vector3i FORWARD;

    /**
     * @brief Shorthand for Vector2f(-1, 0, 0).
     */
    static const Vector3i LEFT;

    /**
     * @brief Shorthand for Vector2f(1, 1, 1).
     */
    static const Vector3i ONE;

    /**
     * @brief Shorthand for Vector2f(1, 0, 0).
     */
    static const Vector3i RIGHT;

    /**
     * @brief Shorthand for Vector2f(0, 1, 0).
     */
    static const Vector3i UP;

    /**
     * @brief Shorthand for Vector2f(0, 0, 0).
     */
    static const Vector3i ZERO;

    /**
     * @brief X component of this vector.
     */
    int32 x;

    /**
     * @brief Y component of this vector.
     */
    int32 y;

    /**
     * @brief Z component of this vector.
     */
    int32 z;
};

Vector3i operator+(const Vector3i& lhs, const Vector3i& rhs);

Vector3i operator-(const Vector3i& lhs, const Vector3i& rhs);

Vector3i operator-(const Vector3i& vector);

Vector3i operator*(const Vector3i& lhs, const Vector3i& rhs);

Vector3i operator*(const Vector3i& lhs, int32 rhs);

Vector3i operator*(int32 lhs, const Vector3i& rhs);

Vector3i operator/(const Vector3i& lhs, const Vector3i& rhs);

Vector3i operator/(const Vector3i& lhs, int32 rhs);
} // namespace chill

/**
 * @struct chill::Vector3i
 */
