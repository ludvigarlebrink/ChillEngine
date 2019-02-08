#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with four components.
 */
struct UTILS_API Vector4u
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector4u();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector4u(const Vector4u& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     * @param z Value of the z component.
     * @param w Value of the w component.
     */
    Vector4u(uint32 x, uint32 y, uint32 z, uint32 w);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector4u(uint32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y, z, w)".
     *
     * @param vec String to create this vector from, format must be "(x, y, z, w)".
     */
    Vector4u(const std::string& vec);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y, z, w)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector4u& operator=(const Vector4u& other);

    Vector4u& operator+=(const Vector4u& other);

    Vector4u& operator-=(const Vector4u& other);

    Vector4u& operator*=(const Vector4u& other);

    Vector4u& operator*=(uint32 v);

    Vector4u& operator/=(const Vector4u& other);

    Vector4u& operator/=(uint32 v);

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

    /**
     * @brief W component of this vector.
     */
    uint32 w;
};

Vector4u operator+(const Vector4u& lhs, const Vector4u& rhs);

Vector4u operator-(const Vector4u& lhs, const Vector4u& rhs);

Vector4u operator*(const Vector4u& lhs, const Vector4u& rhs);

Vector4u operator*(const Vector4u& lhs, uint32 rhs);

Vector4u operator*(uint32 lhs, const Vector4u& rhs);

Vector4u operator/(const Vector4u& lhs, const Vector4u& rhs);

Vector4u operator/(const Vector4u& lhs, uint32 rhs);
} // namespace chill

/**
 * @struct chill::Vector4u
 * @ingroup Math
 */
