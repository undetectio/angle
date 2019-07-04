// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml.
//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// entry_points_gl_1_4_autogen.cpp:
//   Defines the GL 1.4 entry points.

#include "openGL32/entry_points_gl_1_4_autogen.h"

#include "libANGLE/Context.h"
#include "libANGLE/Context.inl.h"
#include "libANGLE/entry_points_utils.h"
#include "libANGLE/validationEGL.h"
#include "libANGLE/validationES.h"
#include "libANGLE/validationES1.h"
#include "libANGLE/validationES2.h"
#include "libANGLE/validationES3.h"
#include "libANGLE/validationES31.h"
#include "libANGLE/validationESEXT.h"
#include "libANGLE/validationGL14_autogen.h"
#include "libGLESv2/global_state.h"

namespace gl
{
void GL_APIENTRY BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    EVENT("(GLfloat red = %f, GLfloat green = %f, GLfloat blue = %f, GLfloat alpha = %f)", red,
          green, blue, alpha);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(BlendColor, context, red, green, blue, alpha);
        if (context->skipValidation() || ValidateBlendColor(context, red, green, blue, alpha))
        {
            context->blendColor(red, green, blue, alpha);
        }
    }
}

void GL_APIENTRY BlendEquation(GLenum mode)
{
    EVENT("(GLenum mode = 0x%X)", mode);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(BlendEquation, context, mode);
        if (context->skipValidation() || ValidateBlendEquation(context, mode))
        {
            context->blendEquation(mode);
        }
    }
}

void GL_APIENTRY BlendFuncSeparate(GLenum sfactorRGB,
                                   GLenum dfactorRGB,
                                   GLenum sfactorAlpha,
                                   GLenum dfactorAlpha)
{
    EVENT(
        "(GLenum sfactorRGB = 0x%X, GLenum dfactorRGB = 0x%X, GLenum sfactorAlpha = 0x%X, GLenum "
        "dfactorAlpha = 0x%X)",
        sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(BlendFuncSeparate, context, sfactorRGB, dfactorRGB, sfactorAlpha,
                      dfactorAlpha);
        if (context->skipValidation() ||
            ValidateBlendFuncSeparate(context, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha))
        {
            context->blendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
        }
    }
}

void GL_APIENTRY FogCoordPointer(GLenum type, GLsizei stride, const void *pointer)
{
    EVENT("(GLenum type = 0x%X, GLsizei stride = %d, const void *pointer = 0x%016" PRIxPTR ")",
          type, stride, (uintptr_t)pointer);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(FogCoordPointer, context, type, stride, pointer);
        if (context->skipValidation() || ValidateFogCoordPointer(context, type, stride, pointer))
        {
            context->fogCoordPointer(type, stride, pointer);
        }
    }
}

void GL_APIENTRY FogCoordd(GLdouble coord)
{
    EVENT("(GLdouble coord = %f)", coord);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(FogCoordd, context, coord);
        if (context->skipValidation() || ValidateFogCoordd(context, coord))
        {
            context->fogCoordd(coord);
        }
    }
}

void GL_APIENTRY FogCoorddv(const GLdouble *coord)
{
    EVENT("(const GLdouble *coord = 0x%016" PRIxPTR ")", (uintptr_t)coord);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(FogCoorddv, context, coord);
        if (context->skipValidation() || ValidateFogCoorddv(context, coord))
        {
            context->fogCoorddv(coord);
        }
    }
}

void GL_APIENTRY FogCoordf(GLfloat coord)
{
    EVENT("(GLfloat coord = %f)", coord);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(FogCoordf, context, coord);
        if (context->skipValidation() || ValidateFogCoordf(context, coord))
        {
            context->fogCoordf(coord);
        }
    }
}

void GL_APIENTRY FogCoordfv(const GLfloat *coord)
{
    EVENT("(const GLfloat *coord = 0x%016" PRIxPTR ")", (uintptr_t)coord);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(FogCoordfv, context, coord);
        if (context->skipValidation() || ValidateFogCoordfv(context, coord))
        {
            context->fogCoordfv(coord);
        }
    }
}

void GL_APIENTRY MultiDrawArrays(GLenum mode,
                                 const GLint *first,
                                 const GLsizei *count,
                                 GLsizei drawcount)
{
    EVENT("(GLenum mode = 0x%X, const GLint *first = 0x%016" PRIxPTR
          ", const GLsizei *count = 0x%016" PRIxPTR ", GLsizei drawcount = %d)",
          mode, (uintptr_t)first, (uintptr_t)count, drawcount);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        PrimitiveMode modePacked = FromGLenum<PrimitiveMode>(mode);
        ANGLE_CAPTURE(MultiDrawArrays, context, modePacked, first, count, drawcount);
        if (context->skipValidation() ||
            ValidateMultiDrawArrays(context, modePacked, first, count, drawcount))
        {
            context->multiDrawArrays(modePacked, first, count, drawcount);
        }
    }
}

void GL_APIENTRY MultiDrawElements(GLenum mode,
                                   const GLsizei *count,
                                   GLenum type,
                                   const void *const *indices,
                                   GLsizei drawcount)
{
    EVENT("(GLenum mode = 0x%X, const GLsizei *count = 0x%016" PRIxPTR
          ", GLenum type = 0x%X, const void *const*indices = 0x%016" PRIxPTR
          ", GLsizei drawcount = %d)",
          mode, (uintptr_t)count, type, (uintptr_t)indices, drawcount);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        PrimitiveMode modePacked    = FromGLenum<PrimitiveMode>(mode);
        DrawElementsType typePacked = FromGLenum<DrawElementsType>(type);
        ANGLE_CAPTURE(MultiDrawElements, context, modePacked, count, typePacked, indices,
                      drawcount);
        if (context->skipValidation() ||
            ValidateMultiDrawElements(context, modePacked, count, typePacked, indices, drawcount))
        {
            context->multiDrawElements(modePacked, count, typePacked, indices, drawcount);
        }
    }
}

void GL_APIENTRY PointParameterf(GLenum pname, GLfloat param)
{
    EVENT("(GLenum pname = 0x%X, GLfloat param = %f)", pname, param);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        PointParameter pnamePacked = FromGLenum<PointParameter>(pname);
        ANGLE_CAPTURE(PointParameterf, context, pnamePacked, param);
        if (context->skipValidation() || ValidatePointParameterf(context, pnamePacked, param))
        {
            context->pointParameterf(pnamePacked, param);
        }
    }
}

void GL_APIENTRY PointParameterfv(GLenum pname, const GLfloat *params)
{
    EVENT("(GLenum pname = 0x%X, const GLfloat *params = 0x%016" PRIxPTR ")", pname,
          (uintptr_t)params);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        PointParameter pnamePacked = FromGLenum<PointParameter>(pname);
        ANGLE_CAPTURE(PointParameterfv, context, pnamePacked, params);
        if (context->skipValidation() || ValidatePointParameterfv(context, pnamePacked, params))
        {
            context->pointParameterfv(pnamePacked, params);
        }
    }
}

void GL_APIENTRY PointParameteri(GLenum pname, GLint param)
{
    EVENT("(GLenum pname = 0x%X, GLint param = %d)", pname, param);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(PointParameteri, context, pname, param);
        if (context->skipValidation() || ValidatePointParameteri(context, pname, param))
        {
            context->pointParameteri(pname, param);
        }
    }
}

void GL_APIENTRY PointParameteriv(GLenum pname, const GLint *params)
{
    EVENT("(GLenum pname = 0x%X, const GLint *params = 0x%016" PRIxPTR ")", pname,
          (uintptr_t)params);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(PointParameteriv, context, pname, params);
        if (context->skipValidation() || ValidatePointParameteriv(context, pname, params))
        {
            context->pointParameteriv(pname, params);
        }
    }
}

void GL_APIENTRY SecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue)
{
    EVENT("(GLbyte red = %d, GLbyte green = %d, GLbyte blue = %d)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3b, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3b(context, red, green, blue))
        {
            context->secondaryColor3b(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3bv(const GLbyte *v)
{
    EVENT("(const GLbyte *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3bv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3bv(context, v))
        {
            context->secondaryColor3bv(v);
        }
    }
}

void GL_APIENTRY SecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue)
{
    EVENT("(GLdouble red = %f, GLdouble green = %f, GLdouble blue = %f)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3d, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3d(context, red, green, blue))
        {
            context->secondaryColor3d(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3dv(const GLdouble *v)
{
    EVENT("(const GLdouble *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3dv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3dv(context, v))
        {
            context->secondaryColor3dv(v);
        }
    }
}

void GL_APIENTRY SecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
    EVENT("(GLfloat red = %f, GLfloat green = %f, GLfloat blue = %f)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3f, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3f(context, red, green, blue))
        {
            context->secondaryColor3f(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3fv(const GLfloat *v)
{
    EVENT("(const GLfloat *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3fv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3fv(context, v))
        {
            context->secondaryColor3fv(v);
        }
    }
}

void GL_APIENTRY SecondaryColor3i(GLint red, GLint green, GLint blue)
{
    EVENT("(GLint red = %d, GLint green = %d, GLint blue = %d)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3i, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3i(context, red, green, blue))
        {
            context->secondaryColor3i(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3iv(const GLint *v)
{
    EVENT("(const GLint *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3iv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3iv(context, v))
        {
            context->secondaryColor3iv(v);
        }
    }
}

void GL_APIENTRY SecondaryColor3s(GLshort red, GLshort green, GLshort blue)
{
    EVENT("(GLshort red = %d, GLshort green = %d, GLshort blue = %d)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3s, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3s(context, red, green, blue))
        {
            context->secondaryColor3s(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3sv(const GLshort *v)
{
    EVENT("(const GLshort *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3sv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3sv(context, v))
        {
            context->secondaryColor3sv(v);
        }
    }
}

void GL_APIENTRY SecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
    EVENT("(GLubyte red = %d, GLubyte green = %d, GLubyte blue = %d)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3ub, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3ub(context, red, green, blue))
        {
            context->secondaryColor3ub(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3ubv(const GLubyte *v)
{
    EVENT("(const GLubyte *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3ubv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3ubv(context, v))
        {
            context->secondaryColor3ubv(v);
        }
    }
}

void GL_APIENTRY SecondaryColor3ui(GLuint red, GLuint green, GLuint blue)
{
    EVENT("(GLuint red = %u, GLuint green = %u, GLuint blue = %u)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3ui, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3ui(context, red, green, blue))
        {
            context->secondaryColor3ui(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3uiv(const GLuint *v)
{
    EVENT("(const GLuint *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3uiv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3uiv(context, v))
        {
            context->secondaryColor3uiv(v);
        }
    }
}

void GL_APIENTRY SecondaryColor3us(GLushort red, GLushort green, GLushort blue)
{
    EVENT("(GLushort red = %u, GLushort green = %u, GLushort blue = %u)", red, green, blue);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3us, context, red, green, blue);
        if (context->skipValidation() || ValidateSecondaryColor3us(context, red, green, blue))
        {
            context->secondaryColor3us(red, green, blue);
        }
    }
}

void GL_APIENTRY SecondaryColor3usv(const GLushort *v)
{
    EVENT("(const GLushort *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColor3usv, context, v);
        if (context->skipValidation() || ValidateSecondaryColor3usv(context, v))
        {
            context->secondaryColor3usv(v);
        }
    }
}

void GL_APIENTRY SecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer)
{
    EVENT(
        "(GLint size = %d, GLenum type = 0x%X, GLsizei stride = %d, const void *pointer = "
        "0x%016" PRIxPTR ")",
        size, type, stride, (uintptr_t)pointer);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(SecondaryColorPointer, context, size, type, stride, pointer);
        if (context->skipValidation() ||
            ValidateSecondaryColorPointer(context, size, type, stride, pointer))
        {
            context->secondaryColorPointer(size, type, stride, pointer);
        }
    }
}

void GL_APIENTRY WindowPos2d(GLdouble x, GLdouble y)
{
    EVENT("(GLdouble x = %f, GLdouble y = %f)", x, y);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2d, context, x, y);
        if (context->skipValidation() || ValidateWindowPos2d(context, x, y))
        {
            context->windowPos2d(x, y);
        }
    }
}

void GL_APIENTRY WindowPos2dv(const GLdouble *v)
{
    EVENT("(const GLdouble *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2dv, context, v);
        if (context->skipValidation() || ValidateWindowPos2dv(context, v))
        {
            context->windowPos2dv(v);
        }
    }
}

void GL_APIENTRY WindowPos2f(GLfloat x, GLfloat y)
{
    EVENT("(GLfloat x = %f, GLfloat y = %f)", x, y);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2f, context, x, y);
        if (context->skipValidation() || ValidateWindowPos2f(context, x, y))
        {
            context->windowPos2f(x, y);
        }
    }
}

void GL_APIENTRY WindowPos2fv(const GLfloat *v)
{
    EVENT("(const GLfloat *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2fv, context, v);
        if (context->skipValidation() || ValidateWindowPos2fv(context, v))
        {
            context->windowPos2fv(v);
        }
    }
}

void GL_APIENTRY WindowPos2i(GLint x, GLint y)
{
    EVENT("(GLint x = %d, GLint y = %d)", x, y);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2i, context, x, y);
        if (context->skipValidation() || ValidateWindowPos2i(context, x, y))
        {
            context->windowPos2i(x, y);
        }
    }
}

void GL_APIENTRY WindowPos2iv(const GLint *v)
{
    EVENT("(const GLint *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2iv, context, v);
        if (context->skipValidation() || ValidateWindowPos2iv(context, v))
        {
            context->windowPos2iv(v);
        }
    }
}

void GL_APIENTRY WindowPos2s(GLshort x, GLshort y)
{
    EVENT("(GLshort x = %d, GLshort y = %d)", x, y);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2s, context, x, y);
        if (context->skipValidation() || ValidateWindowPos2s(context, x, y))
        {
            context->windowPos2s(x, y);
        }
    }
}

void GL_APIENTRY WindowPos2sv(const GLshort *v)
{
    EVENT("(const GLshort *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos2sv, context, v);
        if (context->skipValidation() || ValidateWindowPos2sv(context, v))
        {
            context->windowPos2sv(v);
        }
    }
}

void GL_APIENTRY WindowPos3d(GLdouble x, GLdouble y, GLdouble z)
{
    EVENT("(GLdouble x = %f, GLdouble y = %f, GLdouble z = %f)", x, y, z);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3d, context, x, y, z);
        if (context->skipValidation() || ValidateWindowPos3d(context, x, y, z))
        {
            context->windowPos3d(x, y, z);
        }
    }
}

void GL_APIENTRY WindowPos3dv(const GLdouble *v)
{
    EVENT("(const GLdouble *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3dv, context, v);
        if (context->skipValidation() || ValidateWindowPos3dv(context, v))
        {
            context->windowPos3dv(v);
        }
    }
}

void GL_APIENTRY WindowPos3f(GLfloat x, GLfloat y, GLfloat z)
{
    EVENT("(GLfloat x = %f, GLfloat y = %f, GLfloat z = %f)", x, y, z);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3f, context, x, y, z);
        if (context->skipValidation() || ValidateWindowPos3f(context, x, y, z))
        {
            context->windowPos3f(x, y, z);
        }
    }
}

void GL_APIENTRY WindowPos3fv(const GLfloat *v)
{
    EVENT("(const GLfloat *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3fv, context, v);
        if (context->skipValidation() || ValidateWindowPos3fv(context, v))
        {
            context->windowPos3fv(v);
        }
    }
}

void GL_APIENTRY WindowPos3i(GLint x, GLint y, GLint z)
{
    EVENT("(GLint x = %d, GLint y = %d, GLint z = %d)", x, y, z);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3i, context, x, y, z);
        if (context->skipValidation() || ValidateWindowPos3i(context, x, y, z))
        {
            context->windowPos3i(x, y, z);
        }
    }
}

void GL_APIENTRY WindowPos3iv(const GLint *v)
{
    EVENT("(const GLint *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3iv, context, v);
        if (context->skipValidation() || ValidateWindowPos3iv(context, v))
        {
            context->windowPos3iv(v);
        }
    }
}

void GL_APIENTRY WindowPos3s(GLshort x, GLshort y, GLshort z)
{
    EVENT("(GLshort x = %d, GLshort y = %d, GLshort z = %d)", x, y, z);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3s, context, x, y, z);
        if (context->skipValidation() || ValidateWindowPos3s(context, x, y, z))
        {
            context->windowPos3s(x, y, z);
        }
    }
}

void GL_APIENTRY WindowPos3sv(const GLshort *v)
{
    EVENT("(const GLshort *v = 0x%016" PRIxPTR ")", (uintptr_t)v);

    Context *context = GetValidGlobalContext();
    if (context)
    {
        ANGLE_CAPTURE(WindowPos3sv, context, v);
        if (context->skipValidation() || ValidateWindowPos3sv(context, v))
        {
            context->windowPos3sv(v);
        }
    }
}
}  // namespace gl
