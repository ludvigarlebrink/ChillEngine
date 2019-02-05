#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A vector, or a point, with two components.
 */
struct UTILS_API Vector2u
{
public:

    /**
     * @brief Creates a vector and initializes all components to 0.
     */
    Vector2u();

    /**
     * @brief Copies a vector.
     *
     * @param other Vector to copy from.
     */
    Vector2u(const Vector2u& other);

    /**
     * @brief Creates a vector.
     *
     * @param x Value of the x component.
     * @param y Value of the y component.
     */
    Vector2u(uint32 x, uint32 y);

    /**
     * @brief Creates a vector from a string, format must be "(x, y)".
     *
     * @param vec String to create this vector from, format must be "(x, y)".
     */
    Vector2u(const std::string& vec);

    /**
     * @brief Get this vector as a nicely formated string: "(x, y)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    Vector2u& operator=(const Vector2u& other);

    Vector2u& operator+=(const Vector2u& other);

    Vector2u& operator-=(const Vector2u& other);

    Vector2u& operator*=(const Vector2u& other);

    Vector2u& operator/=(const Vector2u& other);

    uint32& operator[](uint32 i);

public:

    /**
     * @brief X component of a vector.
     */
    uint32 x;

    /**
     * @brief Y component of a vector.
     */
    uint32 y;
};

Vector2u operator+(const Vector2u& lhs, const Vector2u& rhs);

Vector2u operator-(const Vector2u& lhs, const Vector2u& rhs);

Vector2u operator*(const Vector2u& lhs, const Vector2u& rhs);

Vector2u operator*(const Vector2u& lhs, uint32 rhs);

Vector2u operator*(uint32 lhs, const Vector2u& rhs);

Vector2u operator/(const Vector2u& lhs, const Vector2u& rhs);

Vector2u operator/(const Vector2u& lhs, uint32 rhs);
} // namespace chill
