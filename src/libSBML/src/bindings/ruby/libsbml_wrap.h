/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_LibSBML_WRAP_H_
#define SWIG_LibSBML_WRAP_H_

namespace Swig {
  class Director;
}


class SwigDirector_IdentifierTransformer : public IdentifierTransformer, public Swig::Director {

public:
    SwigDirector_IdentifierTransformer(VALUE self);
    virtual ~SwigDirector_IdentifierTransformer();
    virtual int transform(SBase *element);
};


class SwigDirector_ElementFilter : public ElementFilter, public Swig::Director {

public:
    SwigDirector_ElementFilter(VALUE self);
    virtual ~SwigDirector_ElementFilter();
    virtual bool filter(SBase const *element);
};


class SwigDirector_SBMLConverter : public SBMLConverter, public Swig::Director {

public:
    SwigDirector_SBMLConverter(VALUE self);
    SwigDirector_SBMLConverter(VALUE self, std::string const &name);
    SwigDirector_SBMLConverter(VALUE self, SBMLConverter const &orig);
    virtual ~SwigDirector_SBMLConverter();
    virtual SBMLConverter *clone() const;
    virtual SBMLDocument *getDocument();
    virtual SBMLDocument const *getDocument() const;
    virtual ConversionProperties getDefaultProperties() const;
    virtual SBMLNamespaces *getTargetNamespaces();
    virtual bool matchesProperties(ConversionProperties const &props) const;
    virtual int setDocument(SBMLDocument const *doc);
    virtual int setDocument(SBMLDocument *doc);
    virtual int setProperties(ConversionProperties const *props);
    virtual ConversionProperties *getProperties() const;
    virtual int convert();
};


class SwigDirector_SBMLValidator : public SBMLValidator, public Swig::Director {

public:
    SwigDirector_SBMLValidator(VALUE self);
    SwigDirector_SBMLValidator(VALUE self, SBMLValidator const &orig);
    virtual ~SwigDirector_SBMLValidator();
    virtual SBMLValidator *clone() const;
    virtual SBMLDocument *getDocument();
    virtual SBMLDocument const *getDocument() const;
    virtual int setDocument(SBMLDocument const *doc);
    virtual unsigned int validate();
    virtual void clearFailures();
};


#endif
