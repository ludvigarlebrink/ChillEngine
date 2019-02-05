#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with two components.
 */
struct UTILS_API Vector2i
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector2i();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector2i(const Vector2i& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     */
    Vector2i(int32 x, int32 y);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector2i(int32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y)".
     *
     * @param vec String to create this vector from, format must be "(x, y)".
     */
    Vector2i(const std::string& vec);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector2i& operator=(const Vector2i& other);

    Vector2i& operator+=(const Vector2i& other);

    Vector2i& operator-=(const Vector2i& other);

    Vector2i& operator*=(const Vector2i& other);

    Vector2i& operator*=(int32 v);

    Vector2i& operator/=(const Vector2i& other);

    Vector2i& operator/=(int32 v);

    int32& operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Vector2i(0, -1).
     */
    static const Vector2i DOWN;

    /**
     * @brief Shorthand for Vector2i(-1, 0).
     */
    static const Vector2i LEFT;

    /**
     * @brief Shorthand for Vector2i(1, 1).
     */
    static const Vector2i ONE;

    /**
     * @brief Shorthand for Vector2i(1, 0).
     */
    static const Vector2i RIGHT;

    /**
     * @brief Shorthand for Vector2i(0, 1).
     */
    static const Vector2i UP;

    /**
     * @brief Shorthand for Vector2i(0, 0).
     */
    static const Vector2i ZERO;

    /**
     * @brief X component of a vector.
     */
    int32 x;

    /**
     * @brief Y component of a vector.
     */
    int32 y;
};

Vector2i operator+(const Vector2i& lhs, const Vector2i& rhs);

Vector2i operator-(const Vector2i& lhs, const Vector2i& rhs);

Vector2i operator-(const Vector2i& vector);

Vector2i operator*(const Vector2i& lhs, const Vector2i& rhs);

Vector2i operator*(const Vector2i& lhs, int32 rhs);

Vector2i operator*(int32 lhs, const Vector2i& rhs);

Vector2i operator/(const Vector2i& lhs, const Vector2i& rhs);

Vector2i operator/(const Vector2i& lhs, int32 rhs);
} // namespace chill

/**
 * @struct chill::Vector2i
 */