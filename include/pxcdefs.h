/*
Copyright (c) 2011-2014, Intel Corporation

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Intel Corporation nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/** @file pxcdefs.h
    Defines various primitive types used throughout the SDK as well as some
    common structures.  All primitive types start with the prefix ``pxc''.
    Integral primitive types follow that with either an `I' or `U' to indicate
    signed or unsigned and then an integer indicating the number of bits used
    by that type.  For instance, pxcI32 aliases a 32-bit integral type.

    Finally, this class also defines some helper macros to construct some of
    these types as well as other general tasks.
 */
#pragma once

typedef wchar_t pxcCHAR;

/** A signed 16-bit integer */
typedef short               pxcI16;
/** This type is used as a unique identifier */
typedef int                 pxcUID;
/** A signed 32-bit integer */
typedef int                 pxcI32;
/** An signed 64-bit integer */
typedef long long           pxcI64;
/** An unsigned 16-bit integer */
typedef unsigned short int  pxcU16;
/** A byte (an unsigned 8-bit integer) */
typedef unsigned char       pxcBYTE;
/** A common type for enumeration values */
typedef int                 pxcEnum;
/** A boolean value, zero indicates false */
typedef int                 pxcBool;
/** A single-precision (32-bit) floating point type */
typedef float               pxcF32;
/** A double-precision (64-bit) floating point type */
typedef double              pxcF64;

/** A rectangle type defined with pxcI32 values */
struct PXCRectI32 {
    pxcI32 x, y, w, h;
};

/** A rectangle type defined with pxcF32 values */
struct PXCRectF32 {
    pxcF32 x, y, w, h;
};

/** A type representing an two dimensional extent defined with pxcI32 values */
struct PXCSizeI32 {
    pxcI32 width, height;
};

/** A type representing an three dimensional extent defined with pxcF32 values */
struct PXCSize3DF32 {
    pxcF32 width, height, depth;
};

/** A type representing a two dimensional point defined with pxcF32 values */
struct PXCPointF32 {
    pxcF32 x, y;
};

/** A type representing a two dimensional point defined with pxcI32 values */
struct PXCPointI32 {
    pxcI32 x, y;
};

/** A type representing a range defined with pxcF32 values */
struct PXCRangeF32 {
    pxcF32 min, max;
};

/** A type representing a three-dimensional point defined with pxcF32 values */
struct PXCPoint3DF32 {
    pxcF32 x, y, z;
};

/** A type representing a four-dimensional point or vector, for instance quaternion */
struct PXCPoint4DF32 {
    pxcF32 x, y, z, w;
};

/** A type representing a 3d box with pxcF32 values */
struct PXCBox3DF32 {
	PXCPoint3DF32 centerOffset, dimension;
};

/** This macro constructs a pxcUID given four byte values.  The arguments will
    be evaluated exactly once, cast to unsigned int and shifted into one of the
    byte positions.  Hence, arguments must not hold values larger than a byte.
    The result is a pxcUID. */
#define PXC_UID(X1,X2,X3,X4) ((pxcUID)(((unsigned int)(X4)<<24)+((unsigned int)(X3)<<16)+((unsigned int)(X2)<<8)+(unsigned int)(X1)))

/** This macro defines a constant symbol of an integral type within the scope
    of a class or struct.  The type of the constant is that of a symbol in an
    anonymous enumeration (with unspecified width), hence an unspecified
    integral compile-time constant. */
#define PXC_DEFINE_CONST(Y,X) enum {Y=X}

/** This macro defines a UID in the context of a class deriving from PXCBase. */
#define PXC_DEFINE_UID(Y,X1,X2,X3,X4) enum {Y=PXC_UID(X1,X2,X3,X4)}

#if defined(_WIN32) || defined(_WIN64)
#define PXC_DEPRECATED(_MSG) __declspec(deprecated(_MSG))
#else
#define PXC_DEPRECATED(_MSG)
#endif
