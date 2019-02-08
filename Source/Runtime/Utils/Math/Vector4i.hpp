#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with four components.
 */
struct UTILS_API Vector4i
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector4i();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector4i(const Vector4i& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     * @param z Value of the z component.
     * @param w Value of the w component.
     */
    Vector4i(int32 x, int32 y, int32 z, int32 w);

    /**
     * @brief Creates a vector where both components have the same value.
     *
     * @param uniform Value of both components.
     */
    Vector4i(int32 uniform);

    /**
     * @brief Creates a vector from a string, format must be "(x, y, z, w)".
     *
     * @param str String to create this vector from, format must be "(x, y, z, w)".
     */
    Vector4i(const std::string& str);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y, z, w)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector4i& operator=(const Vector4i& other);

    Vector4i& operator+=(const Vector4i& other);

    Vector4i& operator-=(const Vector4i& other);

    Vector4i& operator*=(const Vector4i& other);

    Vector4i& operator*=(int32 v);

    Vector4i& operator/=(const Vector4i& other);

    Vector4i& operator/=(int32 v);

    int32& operator[](uint32 i);

public:

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

    /**
     * @brief W component of this vector.
     */
    int32 w;
};

Vector4i operator+(const Vector4i& lhs, const Vector4i& rhs);

Vector4i operator-(const Vector4i& lhs, const Vector4i& rhs);

Vector4i operator-(const Vector4i& vector);

Vector4i operator*(const Vector4i& lhs, const Vector4i& rhs);

Vector4i operator*(const Vector4i& lhs, int32 rhs);

Vector4i operator*(int32 lhs, const Vector4i& rhs);

Vector4i operator/(const Vector4i& lhs, const Vector4i& rhs);

Vector4i operator/(const Vector4i& lhs, int32 rhs);
} // namespace chill

/**
 * @struct chill::Vector4i
 * @ingroup Math
 */
