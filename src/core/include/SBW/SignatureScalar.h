/**
 * @file SignatureScalar.h
 * @brief represents a scalar type inside a signature
 *
 * This file is part of SBW.  Please visit http://sbw.sf.org for more
 * information about SBW, and the latest version of libSBW.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the New BSD license.
 *
 * Copyright (c) 2010-2014, Frank T. Bergmann and
 *                          University of Washington
 * Copyright (c) 2008-2010, University of Washington and
 *                          Keck Graduate Institute.
 * Copyright (c) 2005-2008, Keck Graduate Institute.
 * Copyright (c) 2001-2004, California Institute of Technology and
 *               Japan Science and Technology Corporation.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above
 *    copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The original code contained here was initially developed by:
 *
 *     Andrew Finney, Herbert Sauro, Michael Hucka, Hamid Bolouri
 *     The Systems Biology Workbench Development Group
 *     ERATO Kitano Systems Biology Project
 *     Control and Dynamical Systems, MC 107-81
 *     California Institute of Technology
 *     Pasadena, CA, 91125, USA
 *
 *
 * Contributor(s):
 *
 */


/// MSVC generated include loop block
#if !defined(AFX_SIGNATURESCALAR_H__8CAF0AA5_6731_4165_9C40_2CA464B2C339__INCLUDED_)
#define AFX_SIGNATURESCALAR_H__8CAF0AA5_6731_4165_9C40_2CA464B2C339__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <SBW/SignatureType.h>

#include <stdarg.h>


namespace SystemsBiologyWorkbench
{

/**
 * represents a scalar type inside a signature
 * @param T the C API type corresponding to the type
 * @param X the DataBlockType corresponding to the type
 */
template<class T, DataBlockType X> class SBW_API sbwSignatureScalar : public sbwSignatureType
{
public:
    sbwSignatureScalar() {}

    /**
     * returns the DataBlockType corresponding this type.
     * @return the DataBlockType corresponding this type.
     */
    DataBlockType getType() { return X; }

    /**
     * For C API : store a scalar value from a variable argument list in a given data block.
     * @param writer data block in which the scalar value will be stored.
     * @param ap variable argument list - the next item is assumed to be a scalar value.
     */
    void write(DataBlockWriter writer, va_list &ap)
    {
        T x = va_arg(ap, T);

        writer << x ;
    }

    /**
     * For C API : read a scalar value from a given data block.
     * @param reader data block in which the scalar value is stored.
     * @param ap variable argument list - the next item is assumed to be an scalar pointer,
     *           the extracted value is stored in the referenced location.
     */
    void read(DataBlockReader reader, va_list &ap)
    {
        T *x = va_arg(ap, T *);

        reader.getForC(*x) ;
    }

    /**
     * For C API : store array of scalar values in data block.
     * @param writer data block in which scalar array to be stored
     * @param size number of scalar values in the array
     * @param ap variable argument list - the next item is assumed to be a pointer to a scalar array.
     */
    void write1DArray(DataBlockWriter writer, Integer size, va_list &ap)
    {
        T *x = va_arg(ap, T *);

        writer.add(size, x);
    }

    /**
     * For C API : read an array of scalar values from a data block.
     * @param reader data block in which scalar array is stored
     * @param size number of scalar values in the array
     * @param ap variable argument list - the next item is assumed to be a pointer to a pointer to a scalar array.
     *           This pointer is changed to point to a scalar array allocated on the C Heap.
     *           Use SBWFree to deallocate this array.
     */
    void read1DArray(DataBlockReader reader, Integer &size, va_list &ap)
    {
        T **x = va_arg(ap, T **);

        reader.getForC(size, *x);
    }

    /**
     * For C API : store 2D array of scalar values in data block.
     * @param writer data block in which scalar array to be stored
     * @param xSize number of scalar values in the first dimension in the array
     * @param ySize number of scalar values in the 2nd dimension in the array
     * @param ap variable argument list - the next item is assumed to be a pointer to a
     *           scalar * array where each element points to an scalar array.
     */
    void write2DArray(DataBlockWriter writer, Integer xsize, Integer ysize, va_list &ap)
    {
        T **x = va_arg(ap, T **);

        writer.add(xsize, ysize, x);
    }

    /**
     * For C API : read a 2D array of scalar values from a data block.
     * @param reader data block in which scalar array is stored
     * @param xSize set to the number of scalar values on the first dimension of the array
     * @param ySize set to the number of scalar values on the first dimension of the array
     * @param ap variable argument list - the next item is assumed to be a pointer to a pointer to a scalar * array.
     *           This pointer is changed to point to a scalar * array allocated on the C Heap.
     *           Use SBWFree2DArray to deallocate this array.
     */
    void read2DArray(DataBlockReader reader, Integer &xsize, Integer &ysize, va_list &ap)
    {
        T ***x = va_arg(ap, T ***);

        reader.getForC(xsize, ysize, *x);
    }
};

} // SystemsBiologyWorkbench

#endif // !defined(AFX_SIGNATURESCALAR_H__8CAF0AA5_6731_4165_9C40_2CA464B2C339__INCLUDED_)
