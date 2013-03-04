/**
 * @file    SBaseRef.cpp
 * @brief   Implementation of SBaseRef, the SBase-derived class of the comp package.
 * @author  Lucian Smith
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2011 California Institute of Technology.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *------------------------------------------------------------------------- -->
 */

#include <iostream>

#include <sbml/SBMLVisitor.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLAttributes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLOutputStream.h>

#include <sbml/packages/comp/extension/CompExtension.h>
#include <sbml/packages/comp/sbml/SBaseRef.h>
#include <sbml/packages/comp/extension/CompModelPlugin.h>
#include <sbml/packages/comp/validator/CompSBMLErrorTable.h>
#include <sbml/Model.h>

using namespace std;

LIBSBML_CPP_NAMESPACE_BEGIN

SBaseRef::SBaseRef (unsigned int level, unsigned int version, unsigned int pkgVersion) 
  : CompBase (level,version, pkgVersion)
  , mMetaIdRef("")
  , mPortRef("")
  , mIdRef("")
  , mUnitRef("")
  , mSBaseRef(NULL)
  , mReferencedElement(NULL)
{
}


SBaseRef::SBaseRef(CompPkgNamespaces* compns)
  : CompBase(compns)
  , mMetaIdRef("")
  , mPortRef("")
  , mIdRef("")
  , mUnitRef("")
  , mSBaseRef(NULL)
  , mReferencedElement(NULL)
{
  loadPlugins(compns);
}


SBaseRef::SBaseRef(const SBaseRef& source) 
  : CompBase (source)
{
  mMetaIdRef=source.mMetaIdRef;
  mPortRef=source.mPortRef;
  mIdRef=source.mIdRef;
  mUnitRef=source.mUnitRef;
  if (source.mSBaseRef!= NULL) {
    mSBaseRef=source.mSBaseRef->clone();
  }
  else {
    mSBaseRef=NULL;
  }
  mReferencedElement = NULL;
}

SBaseRef& SBaseRef::operator=(const SBaseRef& source)
{
  if(&source!=this)
  {
    CompBase::operator=(source);
    mMetaIdRef=source.mMetaIdRef;
    mPortRef=source.mPortRef;
    mIdRef=source.mIdRef;
    mUnitRef=source.mUnitRef;
    if (source.mSBaseRef!= NULL) {
      mSBaseRef=source.mSBaseRef->clone();
    }
    else {
      mSBaseRef=NULL;
    }
  }
  mReferencedElement = NULL;

  return *this;
}

SBaseRef*
SBaseRef::clone() const
{
  return new SBaseRef(*this);
}

SBaseRef::~SBaseRef ()
{
  if (mSBaseRef != NULL) delete mSBaseRef;
}


SBase* 
SBaseRef::getElementBySId(std::string id)
{
  if (id.empty()) return NULL;
  if (mSBaseRef != NULL) {
    SBase* obj = mSBaseRef->getElementBySId(id);
    if (obj != NULL) return obj;
  }
  return getElementFromPluginsBySId(id);
}


SBase*
SBaseRef::getElementByMetaId(std::string metaid)
{
  if (metaid.empty()) return NULL;
  if (mSBaseRef != NULL) {
    if (mSBaseRef->getMetaId() == metaid) return mSBaseRef;

    SBase* obj = mSBaseRef->getElementByMetaId(metaid);
    if (obj != NULL) return obj;
  }
  return getElementFromPluginsByMetaId(metaid);
}


List*
SBaseRef::getAllElements()
{
  List* ret = new List();
  List* sublist = NULL;
  if (mSBaseRef != NULL) {
    ret->add(mSBaseRef);
    sublist = mSBaseRef->getAllElements();
    ret->transferFrom(sublist);
    delete sublist;
  }

  sublist = getAllElementsFromPlugins();
  ret->transferFrom(sublist);
  delete sublist;
  return ret;
}

int
SBaseRef::setMetaIdRef (const std::string& metaIdRef)
{
  //Only set the metaIdRef if we don't refer to anything already, or if we only
  // refer to the metaIdRef.
  if (!(getNumReferents() == 0 || 
        (getNumReferents()==1 && isSetMetaIdRef()))) {
    //LS DEBUG return something else?
    return LIBSBML_OPERATION_FAILED;
  }
  if (!SyntaxChecker::isValidXMLID(metaIdRef)) 
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  mMetaIdRef = metaIdRef;
  return LIBSBML_OPERATION_SUCCESS;
}


const string&
SBaseRef::getMetaIdRef () const
{
  return mMetaIdRef;
}


bool
SBaseRef::isSetMetaIdRef () const
{
  return (mMetaIdRef.empty() == false);
}


int
SBaseRef::unsetMetaIdRef ()
{
  mMetaIdRef.erase();

  if (mMetaIdRef.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}

/*
 * Sets the portRef of this SBML object to a copy of portRef.
 */
int
SBaseRef::setPortRef (const std::string& portRef)
{
  //Only set the portRef if we don't refer to anything already, or if we only
  // refer to the portRef.
  if (!(getNumReferents() == 0 || 
        (getNumReferents()==1 && isSetPortRef()))) {
    //LS DEBUG return something else?
    return LIBSBML_OPERATION_FAILED;
  }
  if (!SyntaxChecker::isValidSBMLSId(portRef)) 
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  mPortRef = portRef;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @return the portRef of this SBML object.
 */
const string&
SBaseRef::getPortRef () const
{
  return mPortRef;
}


/*
 * @return true if the portRef of this SBML object has been set, false
 * otherwise.
 */
bool
SBaseRef::isSetPortRef () const
{
  return (mPortRef.empty() == false);
}


/*
 * Unsets the portRef of this SBML object.
 */
int
SBaseRef::unsetPortRef ()
{
  mPortRef.erase();

  if (mPortRef.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Sets the idRef of this SBML object to a copy of idRef.
 */
int
SBaseRef::setIdRef (const std::string& idRef)
{
  //Only set the idref if we don't refer to anything already, or if we only
  // refer to the idref.
  if (!(getNumReferents() == 0 || 
        (getNumReferents()==1 && isSetIdRef()))) {
    //LS DEBUG return something else?
    return LIBSBML_OPERATION_FAILED;
  }
  if (!SyntaxChecker::isValidSBMLSId(idRef)) 
  {
    //LS DEBUG return something else
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  mIdRef = idRef;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @return the idRef of this SBML object.
 */
const string&
SBaseRef::getIdRef () const
{
  return mIdRef;
}


/*
 * @return true if the idRef of this SBML object has been set, false
 * otherwise.
 */
bool
SBaseRef::isSetIdRef () const
{
  return (mIdRef.empty() == false);
}


/*
 * Unsets the idRef of this SBML object.
 */
int
SBaseRef::unsetIdRef ()
{
  mIdRef.erase();

  if (mIdRef.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}

/*
 * Sets the unitRef of this SBML object to a copy of unitRef.
 */
int
SBaseRef::setUnitRef (const std::string& unitRef)
{
  //Only set the UnitRef if we don't refer to anything already, or if we only
  // refer to the UnitRef.
  if (!(getNumReferents() == 0 || 
        (getNumReferents()==1 && isSetUnitRef()))) {
    //LS DEBUG return something else?
    return LIBSBML_OPERATION_FAILED;
  }
  if (!SyntaxChecker::isValidSBMLSId(unitRef)) 
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  mUnitRef = unitRef;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @return the unitRef of this SBML object.
 */
const string&
SBaseRef::getUnitRef () const
{
  return mUnitRef;
}


/*
 * @return true if the unitRef of this SBML object has been set, false
 * otherwise.
 */
bool
SBaseRef::isSetUnitRef () const
{
  return (mUnitRef.empty() == false);
}


/*
 * Unsets the unitRef of this SBML object.
 */
int
SBaseRef::unsetUnitRef ()
{
  mUnitRef.erase();

  if (mUnitRef.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}

/*
 * @return the child SBaseRef of this SBaseRef.
 */
const SBaseRef*
SBaseRef::getSBaseRef () const
{
  return mSBaseRef;
}


/*
 * @return the child SBaseRef of this SBaseRef.
 */
SBaseRef*
SBaseRef::getSBaseRef ()
{
  return mSBaseRef;
}

/*
 * @return true if the child SBaseRef of this SBaseRef is set, false otherwise.
 */
bool
SBaseRef::isSetSBaseRef () const
{
  return (mSBaseRef != NULL);
}


/*
 * Sets the child SBaseRef of this SBaseRef to a copy of the given SBaseRef.
 */
int
SBaseRef::setSBaseRef (const SBaseRef* sBaseRef)
{
  if (mSBaseRef == sBaseRef) 
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (sBaseRef == NULL)
  {
    if (mSBaseRef != NULL) delete mSBaseRef;
    mSBaseRef = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (getLevel() != sBaseRef->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sBaseRef->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != sBaseRef->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    if (mSBaseRef != NULL) delete mSBaseRef;
    mSBaseRef = sBaseRef->clone();
    if (mSBaseRef == NULL) {
      return LIBSBML_OPERATION_FAILED;
    }
    mSBaseRef->connectToParent(this);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the sBaseRef of this SBaseRef.
 */
int
SBaseRef::unsetSBaseRef ()
{
  delete mSBaseRef;
  mSBaseRef = NULL;

  if (mSBaseRef == NULL) 
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}

int 
SBaseRef::getNumReferents() const
{
  int retval = 0;
  if (isSetPortRef()) retval++;
  if (isSetIdRef()) retval++;
  if (isSetUnitRef()) retval++;
  if (isSetMetaIdRef()) retval++;
  return retval;
}

bool 
SBaseRef::hasRequiredAttributes() const
{
  if (!CompBase::hasRequiredAttributes()) return false;
  return (getNumReferents()==1);
}

void
SBaseRef::renameSIdRefs(std::string oldid, std::string newid)
{
  if (mPortRef==oldid) mPortRef=newid;
  if (mIdRef==oldid) mIdRef=newid;
  if (mUnitRef==oldid) mUnitRef=newid;
  if (mMetaIdRef==oldid) mMetaIdRef=newid;
  SBase::renameSIdRefs(oldid, newid);
}

/*
 * Creates a new SBaseRef, adds it to this SBaseRef
 * and returns it.
 */
SBaseRef*
SBaseRef::createSBaseRef ()
{
  delete mSBaseRef;
  mSBaseRef = NULL;
  
  try
  {
    COMP_CREATE_NS(compns, getSBMLNamespaces());
    mSBaseRef = new SBaseRef(compns);
  }
  catch (...)
  {
    /* here we do not create a default object as the level/version must
     * match the parent object
     *
     * so do nothing
     */
  }

  if (mSBaseRef)
  {
    mSBaseRef->connectToParent(this);
  }

  return mSBaseRef;
}



const std::string&
SBaseRef::getElementName () const
{
  static const std::string name = "sBaseRef";
  return name;
}

/** @cond doxygen-libsbml-internal */
void
SBaseRef::addExpectedAttributes(ExpectedAttributes& attributes)
{
  CompBase::addExpectedAttributes(attributes);
  attributes.add("portRef");
  attributes.add("idRef");
  attributes.add("unitRef");
  attributes.add("metaIdRef");
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void
SBaseRef::readAttributes (const XMLAttributes& attributes,
                          const ExpectedAttributes& expectedAttributes)
{
  CompBase::readAttributes(attributes,expectedAttributes);

  const unsigned int sbmlLevel   = getLevel  ();
  //const unsigned int sbmlVersion = getVersion();
  if ( sbmlLevel > 2 )
  {
    XMLTriple tripleMetaIdRef("metaIdRef", mURI, getPrefix());
    if (attributes.readInto(tripleMetaIdRef, mMetaIdRef, getErrorLog(), false, getLine(), getColumn())) {
      if (!SyntaxChecker::isValidXMLID(mMetaIdRef)) {
        logInvalidId("comp:metaIdRef", mMetaIdRef);
      }
    }
    XMLTriple triplePort("portRef", mURI, getPrefix());
    if (attributes.readInto(triplePort, mPortRef, getErrorLog(), false, getLine(), getColumn())) {
      if (!SyntaxChecker::isValidSBMLSId(mPortRef)) {
        logInvalidId("comp:portRef", mPortRef);
      }
    }
    XMLTriple tripleIdRef("idRef", mURI, getPrefix());
    if (attributes.readInto(tripleIdRef, mIdRef, getErrorLog(), false, getLine(), getColumn())) {
      if (!SyntaxChecker::isValidSBMLSId(mIdRef)) {
        logInvalidId("comp:idRef", mIdRef);
      }
    }
    XMLTriple tripleUnitRef("unitRef", mURI, getPrefix());
    if (attributes.readInto(tripleUnitRef, mUnitRef, getErrorLog(), false, getLine(), getColumn())) {
      if (!SyntaxChecker::isValidSBMLSId(mUnitRef)) {
        logInvalidId("comp:unitRef", mUnitRef);
      }
    }
  }
  if (getNumReferents() == 0) {
    //LS DEBUG Set the error log here
  }
  if (getNumReferents() > 1) {
    //LS DEBUG Set the error log here 
  }
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
SBase* 
SBaseRef::createObject (XMLInputStream& stream)
{
  SBase*        object = NULL;

  const std::string&   name   = stream.peek().getName();
  const XMLNamespaces& xmlns  = stream.peek().getNamespaces();
  const std::string&   prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ? xmlns.getPrefix(mURI) : getPrefix();
  
  if (prefix == targetPrefix)
  {
    SBMLErrorLog* errlog = getErrorLog();
    if (mSBaseRef != NULL && (name =="sBaseRef" || name=="sbaseRef")) {
      if (errlog != NULL) {
          errlog->logPackageError(getPackageName(), CompOneSBaseRefOnly, 
            getPackageVersion(), getLevel(), getVersion());
      }
      object = mSBaseRef;
    }
    else if ( name == "sBaseRef" ) {
      COMP_CREATE_NS(compns, getSBMLNamespaces());
      mSBaseRef = new SBaseRef(compns);
      object = mSBaseRef;
      object->connectToParent(this);
    }
    else if ( name == "sbaseRef" ) {
      if (errlog != NULL) {
          errlog->logPackageError(getPackageName(), CompDeprecatedSBaseRefSpelling, 
            getPackageVersion(), getLevel(), getVersion());
      }
      COMP_CREATE_NS(compns, getSBMLNamespaces());
      mSBaseRef = new SBaseRef(compns);
      object = mSBaseRef;
      object->connectToParent(this);
    }
  }
  return object;
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void
SBaseRef::writeAttributes (XMLOutputStream& stream) const
{
  CompBase::writeAttributes(stream);

  if (isSetMetaIdRef()) {
    stream.writeAttribute("metaIdRef", getPrefix(), mMetaIdRef);
  }
  if (isSetPortRef()) {
    stream.writeAttribute("portRef", getPrefix(), mPortRef);
  }
  if (isSetIdRef()) {
    stream.writeAttribute("idRef", getPrefix(), mIdRef);
  }
  if (isSetUnitRef()) {
    stream.writeAttribute("unitRef", getPrefix(), mUnitRef);
  }
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void
SBaseRef::writeElements (XMLOutputStream& stream) const
{
  CompBase::writeElements(stream);

  if (isSetSBaseRef()) {
    mSBaseRef->write(stream);
  }
  SBaseRef::writeExtensionElements(stream);
}
/** @endcond */


int
SBaseRef::getTypeCode () const
{
  return SBML_COMP_SBASEREF;
}


/*
 * Accepts the given SBMLVisitor.
 */
bool
SBaseRef::accept (SBMLVisitor& v) const
{
  return false;
}


/** @cond doxygen-libsbml-internal */
/*
 * Sets the parent SBMLDocument of this SBML object.
 */
void
SBaseRef::setSBMLDocument (SBMLDocument* d)
{
  CompBase::setSBMLDocument(d);
  if (isSetSBaseRef()) {
    mSBaseRef->setSBMLDocument(d);
  }
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Sets this SBML object to child SBML objects (if any).
 * (Creates a child-parent relationship by the parent)
 */
void
SBaseRef::connectToChild()
{
  CompBase::connectToChild();
  if (isSetSBaseRef()) {
    mSBaseRef->connectToParent(this);
  }
}
/** @endcond */


SBase* 
SBaseRef::getReferencedElementFrom(Model* model)
{
  if (!hasRequiredAttributes()) {
    return NULL;
  }
  SBase* referent = NULL;
  if (isSetPortRef()) {
    CompModelPlugin* mplugin = static_cast<CompModelPlugin*>(model->getPlugin(getPrefix()));
    Port* port = mplugin->getPort(getPortRef());
    if (port==NULL) return NULL;
    referent = port->getReferencedElementFrom(model);
  }
  else if (isSetIdRef()) {
    referent = model->getElementBySId(getIdRef());
  }
  else if (isSetUnitRef()) {
    referent = model->getUnitDefinition(getUnitRef());
  }
  else if (isSetMetaIdRef()) {
    referent = model->getElementByMetaId(getMetaIdRef());
  }
  else {
    //This is actually possible if the subclass overrides getNumReferents() (which some do).  In that case, we just return NULL and let the overriding function find the referent instead.
    return NULL;
  }
  if (referent == NULL) return NULL;
  if (isSetSBaseRef()) {
    //We're drilling into the submodels here, so our referent must be a submodel.
    if (referent->getTypeCode() != SBML_COMP_SUBMODEL) {
      //Set something in the error log?
      return NULL;
    }
    Submodel* subm = static_cast<Submodel*>(referent);
    if (subm==NULL) return NULL;
    Model* inst = subm->getInstantiation();
    if (inst==NULL) return NULL;
    referent = getSBaseRef()->getReferencedElementFrom(inst);
  }
  return referent;
}

int SBaseRef::saveReferencedElement()
{
  //The only thing that knows what Model we should point to is the parent of this object.  Since it will also be of the class SBaseRef, just call this recursively.
  SBase* parent = getParentSBMLObject();
  if (parent==NULL) return LIBSBML_OPERATION_FAILED;
  SBaseRef* parentref = static_cast<SBaseRef*>(parent);
  if (parentref==NULL) return LIBSBML_OPERATION_FAILED;
  if (parentref->saveReferencedElement() != LIBSBML_OPERATION_SUCCESS) {
    return LIBSBML_OPERATION_FAILED;
  }
  mReferencedElement = parentref->getReferencedElement();
  if (mReferencedElement==NULL) return LIBSBML_OPERATION_FAILED;
  return LIBSBML_OPERATION_SUCCESS;
}

SBase* SBaseRef::getReferencedElement()
{
  if (mReferencedElement==NULL) {
    saveReferencedElement();
  }
  return mReferencedElement;
}

void SBaseRef::clearReferencedElement()
{
  mReferencedElement = NULL;
}

int SBaseRef::performDeletion()
{
  SBase* todelete = getReferencedElement();
  if (todelete==NULL) return LIBSBML_INVALID_OBJECT;
  CompSBasePlugin* todplug = static_cast<CompSBasePlugin*>(todelete->getPlugin(getPrefix()));
  if (todplug != NULL) {
    for (unsigned long re=0; re<todplug->getNumReplacedElements(); re++) {
      todplug->getReplacedElement(re)->performDeletion();
    }
    if (todplug->isSetReplacedBy()) {
      todplug->getReplacedBy()->performDeletion();
    }
  }
  return CompBase::removeFromParentAndPorts(todelete);
}

int SBaseRef::removeFromParentAndDelete()
{
  SBase* parent = getParentSBMLObject();
  if (parent==NULL) return LIBSBML_OPERATION_FAILED;
  SBaseRef* parentSBR;
  switch(parent->getTypeCode()) {
  case SBML_LIST_OF:
    //This will be the case if we are a deletion, replaced element, replaced by, or port.
    return SBase::removeFromParentAndDelete();
  case SBML_COMP_DELETION:
  case SBML_COMP_SBASEREF:
  case SBML_COMP_REPLACEDELEMENT:
  case SBML_COMP_REPLACEDBY:
  case SBML_COMP_PORT:
    //This will be the case if we are a 'raw' SBaseRef object.
    parentSBR = static_cast<SBaseRef*>(parent);
    if (parentSBR==NULL) return LIBSBML_OPERATION_FAILED;
    return parentSBR->unsetSBaseRef();
  default:
    assert(false); //Nothing else should ever be a parent of an SBaseRef object.
    return LIBSBML_OPERATION_FAILED;
  }
}


/**
 * 
 */
LIBSBML_EXTERN
SBaseRef_t *
SBaseRef_create(unsigned int level, unsigned int version,
                unsigned int pkgVersion)
{
	return new SBaseRef(level, version, pkgVersion);
}


/**
 * 
 */
LIBSBML_EXTERN
void
SBaseRef_free(SBaseRef_t * sbr)
{
	if (sbr != NULL)
		delete sbr;
}


/**
 * 
 */
LIBSBML_EXTERN
SBaseRef_t *
SBaseRef_clone(SBaseRef_t * sbr)
{
	if (sbr != NULL)
	{
		return static_cast<SBaseRef_t*>(sbr->clone());
	}
	else
	{
		return NULL;
	}
}


/**
 * 
 */
LIBSBML_EXTERN
char *
SBaseRef_getPortRef(SBaseRef_t * sbr)
{
	if (sbr == NULL)
		return NULL;

	return sbr->getPortRef().empty() ? NULL : safe_strdup(sbr->getPortRef().c_str());
}


/**
 * 
 */
LIBSBML_EXTERN
char *
SBaseRef_getIdRef(SBaseRef_t * sbr)
{
	if (sbr == NULL)
		return NULL;

	return sbr->getIdRef().empty() ? NULL : safe_strdup(sbr->getIdRef().c_str());
}


/**
 * 
 */
LIBSBML_EXTERN
char *
SBaseRef_getUnitRef(SBaseRef_t * sbr)
{
	if (sbr == NULL)
		return NULL;

	return sbr->getUnitRef().empty() ? NULL : safe_strdup(sbr->getUnitRef().c_str());
}


/**
 * 
 */
LIBSBML_EXTERN
char *
SBaseRef_getMetaIdRef(SBaseRef_t * sbr)
{
	if (sbr == NULL)
		return NULL;

	return sbr->getMetaIdRef().empty() ? NULL : safe_strdup(sbr->getMetaIdRef().c_str());
}


/**
 * 
 */
LIBSBML_EXTERN
SBaseRef_t*
SBaseRef_getSBaseRef(SBaseRef_t * sbr)
{
	if (sbr == NULL)
		return NULL;

	return sbr->getSBaseRef();
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_isSetPortRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? static_cast<int>(sbr->isSetPortRef()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_isSetIdRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? static_cast<int>(sbr->isSetIdRef()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_isSetUnitRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? static_cast<int>(sbr->isSetUnitRef()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_isSetMetaIdRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? static_cast<int>(sbr->isSetMetaIdRef()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_isSetSBaseRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? static_cast<int>(sbr->isSetSBaseRef()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_setPortRef(SBaseRef_t * sbr, const char * portRef)
{
	return (sbr != NULL) ? sbr->setPortRef(portRef) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_setIdRef(SBaseRef_t * sbr, const char * idRef)
{
	return (sbr != NULL) ? sbr->setIdRef(idRef) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_setUnitRef(SBaseRef_t * sbr, const char * unitRef)
{
	return (sbr != NULL) ? sbr->setUnitRef(unitRef) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_setMetaIdRef(SBaseRef_t * sbr, const char * metaIdRef)
{
	return (sbr != NULL) ? sbr->setMetaIdRef(metaIdRef) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_setSBaseRef(SBaseRef_t * sbr, SBaseRef_t * sBaseRef)
{
	return (sbr != NULL) ? sbr->setSBaseRef(sBaseRef) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_unsetPortRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? sbr->unsetPortRef() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_unsetIdRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? sbr->unsetIdRef() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_unsetUnitRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? sbr->unsetUnitRef() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_unsetMetaIdRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? sbr->unsetMetaIdRef() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_unsetSBaseRef(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? sbr->unsetSBaseRef() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
SBaseRef_hasRequiredAttributes(SBaseRef_t * sbr)
{
	return (sbr != NULL) ? static_cast<int>(sbr->hasRequiredAttributes()) : 0;
}


LIBSBML_CPP_NAMESPACE_END
