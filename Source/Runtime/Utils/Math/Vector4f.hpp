#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with three components.
 */
struct UTILS_API Vector4f
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector4f();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector4f(const Vector4f& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     * @param z Value of the z component.
     * @param w Value of the w component.
     */
    Vector4f(f32 x, f32 y, f32 z, f32 w);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector4f(uint32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y, z, w)".
     *
     * @param str String to create this vector from, format must be "(x, y, z, w)".
     */
    Vector4f(const std::string& str);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y, z, w)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector4f& operator=(const Vector4f& other);

    Vector4f& operator+=(const Vector4f& other);

    Vector4f& operator-=(const Vector4f& other);

    Vector4f& operator*=(const Vector4f& other);

    Vector4f& operator*=(f32 v);

    Vector4f& operator/=(const Vector4f& other);

    Vector4f& operator/=(f32 v);

    f32& operator[](uint32 i);

public:

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

    /**
     * @brief W component of this vector.
     */
    f32 w;
};

Vector4f operator+(const Vector4f& lhs, const Vector4f& rhs);

Vector4f operator-(const Vector4f& lhs, const Vector4f& rhs);

Vector4f operator-(const Vector4f& vector);

Vector4f operator*(const Vector4f& lhs, const Vector4f& rhs);

Vector4f operator*(const Vector4f& lhs, f32 rhs);

Vector4f operator*(f32 lhs, const Vector4f& rhs);

Vector4f operator/(const Vector4f& lhs, const Vector4f& rhs);

Vector4f operator/(const Vector4f& lhs, f32 rhs);
} // namespace chill

/**
 * @struct chill::Vector4f
 */
