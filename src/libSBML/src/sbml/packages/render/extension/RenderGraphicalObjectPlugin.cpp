/**
 * @file    RenderGraphicalObjectPlugin.cpp
 * @brief   Implementation of RenderGraphicalObjectPlugin, the plugin class of
 *          the render package for the GraphicalObject element.
 * @author  Frank T. Bergmann
 *
 * $Id$
 * $HeadURL$
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2009-2013 California Institute of Technology.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *------------------------------------------------------------------------- -->
 */

#include <sbml/packages/render/extension/RenderGraphicalObjectPlugin.h>

#include <iostream>
using namespace std;


#ifdef __cplusplus

LIBSBML_CPP_NAMESPACE_BEGIN

  /*
  * Constructor
  */
  RenderGraphicalObjectPlugin::RenderGraphicalObjectPlugin (const std::string &uri, 
  const std::string &prefix,
  RenderPkgNamespaces *renderns)
  : SBasePlugin(uri,prefix, renderns)
  , mObjectRole("")
  
{
}


/*
* Copy constructor. Creates a copy of this SBase object.
*/
RenderGraphicalObjectPlugin::RenderGraphicalObjectPlugin(const RenderGraphicalObjectPlugin& orig)
  : SBasePlugin(orig)
  , mObjectRole(orig.mObjectRole)
{

}


/*
* Destroy this object.
*/
RenderGraphicalObjectPlugin::~RenderGraphicalObjectPlugin () {}

/*
* Assignment operator for RenderGraphicalObjectPlugin.
*/
RenderGraphicalObjectPlugin& 
  RenderGraphicalObjectPlugin::operator=(const RenderGraphicalObjectPlugin& orig)
{
  if(&orig!=this)
  {
    this->SBasePlugin::operator =(orig);
    this->mObjectRole = orig.mObjectRole;   
  }    
  return *this;
}


/*
* Creates and returns a deep copy of this RenderGraphicalObjectPlugin object.
* 
* @return a (deep) copy of this RenderGraphicalObjectPlugin object
*/
RenderGraphicalObjectPlugin* 
  RenderGraphicalObjectPlugin::clone () const
{
  return new RenderGraphicalObjectPlugin(*this);  
}




/*
*
*  (EXTENSION) Additional public functions
*
*/  

/*
 * Returns the object role string for the object.
 */
const std::string& 
RenderGraphicalObjectPlugin::getObjectRole() const
{
  return mObjectRole;
}

/*
 * Sets the object role string for the object.
 */
void 
RenderGraphicalObjectPlugin::setObjectRole(const std::string& role)
{
  mObjectRole = role;
}

/*
 * Returns whether the object role has been set or not.
 */
bool 
RenderGraphicalObjectPlugin::isSetObjectRole() const
{
  return !mObjectRole.empty();
}

/** @cond doxygen-libsbml-internal */
void
RenderGraphicalObjectPlugin::addExpectedAttributes(ExpectedAttributes& attributes)
{
  //
  // required attribute is not defined for SBML Level 2 or lesser.
  //
	attributes.add("objectRole");
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void 
RenderGraphicalObjectPlugin::readAttributes (const XMLAttributes& attributes,
                                    const ExpectedAttributes& expectedAttributes)
{
  SBasePlugin::readAttributes(attributes, expectedAttributes);
  attributes.readInto("objectRole", mObjectRole, getErrorLog(), false, getLine(), getColumn());
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void 
RenderGraphicalObjectPlugin::writeAttributes (XMLOutputStream& stream) const
{
  if ( !getObjectRole().empty() ) 
  {
    stream.writeAttribute("objectRole", getPrefix(), mObjectRole);
  }
}
/** @endcond */



LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
