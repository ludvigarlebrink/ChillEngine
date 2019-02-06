#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with three components.
 */
struct UTILS_API Vector3u
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector3u();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector3u(const Vector3u& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     * @param z Value of the z component.
     */
    Vector3u(uint32 x, uint32 y, uint32 z);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector3u(uint32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y, z)".
     *
     * @param str String to create this vector from, format must be "(x, y, z)".
     */
    Vector3u(const std::string& str);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y, z)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector3u& operator=(const Vector3u& other);

    Vector3u& operator+=(const Vector3u& other);

    Vector3u& operator-=(const Vector3u& other);

    Vector3u& operator*=(const Vector3u& other);

    Vector3u& operator*=(uint32 v);

    Vector3u& operator/=(const Vector3u& other);

    Vector3u& operator/=(uint32 v);

    uint32& operator[](uint32 i);

public:

    /**
     * @brief X component of this vector.
     */
    uint32 x;

    /**
     * @brief Y component of this vector.
     */
    uint32 y;

    /**
     * @brief Z component of this vector.
     */
    uint32 z;
};

Vector3u operator+(const Vector3u& lhs, const Vector3u& rhs);

Vector3u operator-(const Vector3u& lhs, const Vector3u& rhs);

Vector3u operator*(const Vector3u& lhs, const Vector3u& rhs);

Vector3u operator*(const Vector3u& lhs, uint32 rhs);

Vector3u operator*(uint32 lhs, const Vector3u& rhs);

Vector3u operator/(const Vector3u& lhs, const Vector3u& rhs);

Vector3u operator/(const Vector3u& lhs, uint32 rhs);
} // namespace chill

/**
 * @struct chill::Vector3u
 */
