/**
 * @file SBWListener.cpp
 * @brief SBWListener implementation
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


#include "stdafx.h"
#include "SBWListener.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


/// does nothing
SBWListener::SBWListener() {}

/// does nothing
SBWListener::~SBWListener() {}

/**
* Called when a given module disconnects from the broker.
* This implementation does nothing.
* @param x ignored; Module instance that has disconnected from the broker.
*/
void SBWListener::onModuleShutdown(Module /*x*/) {}

/**
* Called when a given module connects from the broker.
* This implementation does nothing.
* @param x ignored; Module instance that has connected from the broker.
*/
void SBWListener::onModuleStart(Module) {}

/// called when the broker's module registration data changes.  This implementation does nothing.
void SBWListener::onRegistrationChange() {}

/// called when this module/application is disconnected from the broker. 
void SBWListener::onShutdown() {}

/**
* Called when a given module disconnects from the broker.
* This implementation calls onModuleShutdown(Module x).
* @see onModuleShutdown(Module x)
* @param x ignored; numeric module instance identifier of module instance that has disconnected from the broker.
*/	
void SBWListener::onModuleShutdown(Integer x) { onModuleShutdown(Module(x)); }

/**
* Called when a given module connects from the broker.
* This implementation calls onModuleStart(Module x).
* @see onModuleStart(Module x)
* @param x ignored; numeric module instance identifier of module instance that has connected from the broker.
*/	
void SBWListener::onModuleStart(Integer x) { onModuleStart(Module(x)); }
