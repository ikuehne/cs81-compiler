/**
 * @file Token.hh
 *
 * @brief Tokens as output by the lexer.
 *
 * Consists of a series of small classes grouped in the namespace `Tok`, and a
 * variant type `Token` which can be any of those classes.
 */

/* CS 81 Compiler: a compiler for a new systems programming language.
 *
 * Copyright (C) 2017 Ian Kuehne <ikuehne@caltech.edu>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>
#include <string>

#include <boost/variant.hpp>

namespace Compiler {

namespace Tok {

/**
 * @defgroup Tokens Classes for possible types of tokens.
 *
 * Each of these classes contains public data members for the contents of the
 * token and a simple inline constructor which takes one argument per member.
 * For performance, these constructors will `move` potentially
 * expensive-to-copy data like strings.
 *
 * @{
 */

/**
 * @brief Names of types.
 */
struct TypeName {
    std::wstring name;

    TypeName(std::wstring name): name(std::move(name)) {}
};

/**
 * @brief Non-type identifiers.
 */
struct Identifier {
    std::wstring name;

    Identifier(std::wstring name): name(std::move(name)) {}
};

/**
 * @brief Signed integer literals.
 */
struct IntLiteral {
    int64_t value;

    IntLiteral(int64_t value): value(value) {}
};

/**
 * @brief Unsigned integer literals.
 */
struct UIntLiteral {
    uint64_t value;

    UIntLiteral(uint64_t value): value(value) {}
};

/**
 * @brief Floating-point literals.
 */
struct FloatLiteral {
    double value;

    FloatLiteral(double value): value(value) {}
};

/**
 * @brief Operators.
 */
struct Operator {
    std::wstring op;

    Operator(std::wstring op): op(std::move(op)) {}
};

/**
 * @defgroup Empty Tokens with no meaning other than disambiguating syntax.
 */

struct OpenParen {};
struct CloseParen {};
struct OpenBrace {};
struct CloseBrace {};
struct Comma {};
struct Fn {};
struct Struct {};
struct Return {};
struct If {};
struct Else {};
struct While {};

/** @} */

/** The actual `Token` class: a discriminated union of token types. */
typedef boost::variant< TypeName,
                        Identifier,
                        IntLiteral, UIntLiteral, FloatLiteral,
                        Operator,
                        OpenParen, CloseParen,
                        OpenBrace, CloseBrace,
                        Comma,
                        Fn, Struct,
                        Return,
                        If, Else, While > Token;

}

}