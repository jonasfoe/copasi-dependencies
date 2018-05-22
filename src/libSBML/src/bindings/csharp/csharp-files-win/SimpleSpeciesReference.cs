//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.12
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace libsbml {

 using System;
 using System.Runtime.InteropServices;

/** 
 * @sbmlpackage{core}
 *
@htmlinclude pkg-marker-core.html Abstract class for references to species in reactions.
 *
 * As mentioned in the description of Reaction, every species that enters
 * into a given reaction must appear in that reaction's lists of reactants,
 * products and/or modifiers.  In an SBML model, all species that may
 * participate in any reaction are listed in the 'listOfSpecies' element of
 * the top-level Model object.  Lists of products, reactants and modifiers
 * in Reaction objects do not introduce new species, but rather, they refer
 * back to those listed in the model's top-level 'listOfSpecies'.  For
 * reactants and products, the connection is made using SpeciesReference
 * objects; for modifiers, it is made using ModifierSpeciesReference
 * objects.  SimpleSpeciesReference is an abstract type that serves as the
 * parent class of both SpeciesReference and ModifierSpeciesReference.  It
 * is used simply to hold the attributes and elements that are common to
 * the latter two structures.
 *
 * The SimpleSpeciesReference structure has a mandatory attribute,
 * 'species', which must be a text string conforming to the identifer
 * syntax permitted in %SBML.  This attribute is inherited by the
 * SpeciesReference and ModifierSpeciesReference subclasses derived from
 * SimpleSpeciesReference.  The value of the 'species' attribute must be
 * the identifier of a species defined in the enclosing Model.  The species
 * is thereby declared as participating in the reaction being defined.  The
 * precise role of that species as a reactant, product, or modifier in the
 * reaction is determined by the subclass of SimpleSpeciesReference (i.e.,
 * either SpeciesReference or ModifierSpeciesReference) in which the
 * identifier appears.
 * 
 * SimpleSpeciesReference also contains an optional attribute, 'id',
 * allowing instances to be referenced from other structures.  No SBML
 * structures currently do this; however, such structures are anticipated
 * in future SBML Levels.
 *  
 */

public class SimpleSpeciesReference : SBase {
	private HandleRef swigCPtr;
	
	internal SimpleSpeciesReference(IntPtr cPtr, bool cMemoryOwn) : base(libsbmlPINVOKE.SimpleSpeciesReference_SWIGUpcast(cPtr), cMemoryOwn)
	{
		//super(libsbmlPINVOKE.SimpleSpeciesReferenceUpcast(cPtr), cMemoryOwn);
		swigCPtr = new HandleRef(this, cPtr);
	}
	
	internal static HandleRef getCPtr(SimpleSpeciesReference obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}
	
	internal static HandleRef getCPtrAndDisown (SimpleSpeciesReference obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);
		
		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}
		
		return ptr;
	}

  ~SimpleSpeciesReference() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_SimpleSpeciesReference(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  
/**
   * Returns the value of the 'id' attribute of this SimpleSpeciesReference.
   *
   * @note Because of the inconsistent behavior of this function with 
   * respect to assignments and rules, it is now recommended to
   * use the getIdAttribute() function instead.
   *
   *
 * 
 * The identifier given by an object's 'id' attribute value
 * is used to identify the object within the SBML model definition.
 * Other objects can refer to the component using this identifier.  The
 * data type of 'id' is always <code>SId</code> or a type derived
 * from that, such as <code>UnitSId</code>, depending on the object in 
 * question.  All data types are defined as follows:
 * <pre style='margin-left: 2em; border: none; font-weight: bold; color: black'>
 *   letter ::= 'a'..'z','A'..'Z'
 *   digit  ::= '0'..'9'
 *   idChar ::= letter | digit | '_'
 *   SId    ::= ( letter | '_' ) idChar*
 * </pre>
 * The characters <code>(</code> and <code>)</code> are used for grouping, the
 * character <code>*</code> 'zero or more times', and the character
 * <code>|</code> indicates logical 'or'.  The equality of SBML identifiers is
 * determined by an exact character sequence match; i.e., comparisons must be
 * performed in a case-sensitive manner.  This applies to all uses of <code>SId</code>, 
 * <code>SIdRef</code>, and derived types.
 *
 * In SBML Level&nbsp;3 Version&nbsp;2, the 'id' and 'name' attributes were
 * moved to SBase directly, instead of being defined individually for many
 * (but not all) objects.  Libsbml has for a long time provided functions
 * defined on SBase itself to get, set, check, and unset those attributes, which 
 * would fail or otherwise return empty strings if executed on any object 
 * for which those attributes were not defined.  Now that all SBase objects 
 * define those attributes, those functions now succeed for any object with 
 * the appropriate level and version.
 *
 * The exception to this rule is that for InitialAssignment, EventAssignment, 
 * AssignmentRule, and RateRule objects, the getId() function and the isSetId() 
 * functions (though not the setId() or unsetId() functions) would instead 
 * reference the value of the 'variable' attribute (for the rules and event 
 * assignments) or the 'symbol' attribute (for initial assignments).  
 * The AlgebraicRule fell into this category as well, though because it 
 * contained neither a 'variable' nor a 'symbol' attribute, getId() would 
 * always return an empty string, and isSetId() would always return @c false.
 * For this reason, four new functions are now provided 
 * (getIdAttribute(), setIdAttribute(@if java String@endif), 
 * isSetIdAttribute(), and unsetIdAttribute()) that will always
 * act on the actual 'id' attribute, regardless of the object's type.  The
 * new functions should be used instead of the old ones unless the old behavior
 * is somehow necessary.
 * 
 * Regardless of the level and version of the SBML, these functions allow
 * client applications to use more generalized code in some situations 
 * (for instance, when manipulating objects that are all known to have 
 * identifiers).  If the object in question does not posess an 'id' attribute 
 * according to the SBML specification for the Level and Version in use,
 * libSBML will not allow the identifier to be set, nor will it read or 
 * write 'id' attributes for those objects.
 *
 *
   *
   * @return the id of this SimpleSpeciesReference.
   *
   * @see getIdAttribute()
   * @see setIdAttribute(string sid)
   * @see isSetIdAttribute()
   * @see unsetIdAttribute()
   */ public new
 string getId() {
    string ret = libsbmlPINVOKE.SimpleSpeciesReference_getId(swigCPtr);
    return ret;
  }

  
/**
   * Returns the value of the 'name' attribute of this SimpleSpeciesReference object.
   *
   *
 *
 * 
 * In SBML Level&nbsp;3 Version&nbsp;2, the 'id' and 'name' attributes were
 * moved to SBase directly, instead of being defined individually for many
 * (but not all) objects.  Libsbml has for a long time provided functions
 * defined on SBase itself to get, set, and unset those attributes, which 
 * would fail or otherwise return empty strings if executed on any object 
 * for which those attributes were not defined.  Now that all SBase objects 
 * define those attributes, those functions now succeed for any object with 
 * the appropriate level and version.
 *
 * The 'name' attribute is
 * optional and is not intended to be used for cross-referencing purposes
 * within a model.  Its purpose instead is to provide a human-readable
 * label for the component.  The data type of 'name' is the type
 * <code>string</code> defined in XML Schema.  SBML imposes no
 * restrictions as to the content of 'name' attributes beyond those
 * restrictions defined by the <code>string</code> type in XML Schema.
 *
 * The recommended practice for handling 'name' is as follows.  If a
 * software tool has the capability for displaying the content of 'name'
 * attributes, it should display this content to the user as a
 * component's label instead of the component's 'id'.  If the user
 * interface does not have this capability (e.g., because it cannot
 * display or use special characters in symbol names), or if the 'name'
 * attribute is missing on a given component, then the user interface
 * should display the value of the 'id' attribute instead.  (Script
 * language interpreters are especially likely to display 'id' instead of
 * 'name'.)
 * 
 * As a consequence of the above, authors of systems that automatically
 * generate the values of 'id' attributes should be aware some systems
 * may display the 'id''s to the user.  Authors therefore may wish to
 * take some care to have their software create 'id' values that are: (a)
 * reasonably easy for humans to type and read; and (b) likely to be
 * meaningful, for example by making the 'id' attribute be an abbreviated
 * form of the name attribute value.
 * 
 * An additional point worth mentioning is although there are
 * restrictions on the uniqueness of 'id' values, there are no
 * restrictions on the uniqueness of 'name' values in a model.  This
 * allows software applications leeway in assigning component identifiers.
 *
 * Regardless of the level and version of the SBML, these functions allow
 * client applications to use more generalized code in some situations 
 * (for instance, when manipulating objects that are all known to have 
 * names).  If the object in question does not posess a 'name' attribute 
 * according to the SBML specification for the Level and Version in use,
 * libSBML will not allow the name to be set, nor will it read or 
 * write 'name' attributes for those objects.
 *
 *
 *
 * @return the name of this SBML object, or the empty string if not set or unsettable.
 *
 * @see getIdAttribute()
 * @see isSetName()
 * @see setName(string sid)
 * @see unsetName()
 * 
 *
   */ public new
 string getName() {
    string ret = libsbmlPINVOKE.SimpleSpeciesReference_getName(swigCPtr);
    return ret;
  }

  
/**
   * Get the value of the 'species' attribute.
   * 
   * @return the value of the attribute 'species' for this
   * SimpleSpeciesReference.
   */ public
 string getSpecies() {
    string ret = libsbmlPINVOKE.SimpleSpeciesReference_getSpecies(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if this
   * SimpleSpeciesReference's 'id' attribute is set.
   *
   *
 *
 * 
 * The identifier given by an object's 'id' attribute value
 * is used to identify the object within the SBML model definition.
 * Other objects can refer to the component using this identifier.  The
 * data type of 'id' is always <code>SId</code> or a type derived
 * from that, such as <code>UnitSId</code>, depending on the object in 
 * question.  All data types are defined as follows:
 * <pre style='margin-left: 2em; border: none; font-weight: bold; color: black'>
 *   letter ::= 'a'..'z','A'..'Z'
 *   digit  ::= '0'..'9'
 *   idChar ::= letter | digit | '_'
 *   SId    ::= ( letter | '_' ) idChar*
 * </pre>
 * The characters <code>(</code> and <code>)</code> are used for grouping, the
 * character <code>*</code> 'zero or more times', and the character
 * <code>|</code> indicates logical 'or'.  The equality of SBML identifiers is
 * determined by an exact character sequence match; i.e., comparisons must be
 * performed in a case-sensitive manner.  This applies to all uses of <code>SId</code>, 
 * <code>SIdRef</code>, and derived types.
 *
 * In SBML Level&nbsp;3 Version&nbsp;2, the 'id' and 'name' attributes were
 * moved to SBase directly, instead of being defined individually for many
 * (but not all) objects.  Libsbml has for a long time provided functions
 * defined on SBase itself to get, set, check, and unset those attributes, which 
 * would fail or otherwise return empty strings if executed on any object 
 * for which those attributes were not defined.  Now that all SBase objects 
 * define those attributes, those functions now succeed for any object with 
 * the appropriate level and version.
 *
 * The exception to this rule is that for InitialAssignment, EventAssignment, 
 * AssignmentRule, and RateRule objects, the getId() function and the isSetId() 
 * functions (though not the setId() or unsetId() functions) would instead 
 * reference the value of the 'variable' attribute (for the rules and event 
 * assignments) or the 'symbol' attribute (for initial assignments).  
 * The AlgebraicRule fell into this category as well, though because it 
 * contained neither a 'variable' nor a 'symbol' attribute, getId() would 
 * always return an empty string, and isSetId() would always return @c false.
 * For this reason, four new functions are now provided 
 * (getIdAttribute(), setIdAttribute(@if java String@endif), 
 * isSetIdAttribute(), and unsetIdAttribute()) that will always
 * act on the actual 'id' attribute, regardless of the object's type.  The
 * new functions should be used instead of the old ones unless the old behavior
 * is somehow necessary.
 * 
 * Regardless of the level and version of the SBML, these functions allow
 * client applications to use more generalized code in some situations 
 * (for instance, when manipulating objects that are all known to have 
 * identifiers).  If the object in question does not posess an 'id' attribute 
 * according to the SBML specification for the Level and Version in use,
 * libSBML will not allow the identifier to be set, nor will it read or 
 * write 'id' attributes for those objects.
 *
 *
 *
 * @return @c true if the 'id' attribute of this SBML object is
 * set, @c false otherwise.
 *
 * @note Because of the inconsistent behavior of this function with
 * respect to assignments and rules, it is recommended that callers
 * use isSetIdAttribute() instead.
 *
 * @see getIdAttribute()
 * @see setIdAttribute(string sid)
 * @see unsetIdAttribute()
 * @see isSetIdAttribute()
 *
 *
   */ public new
 bool isSetId() {
    bool ret = libsbmlPINVOKE.SimpleSpeciesReference_isSetId(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if this
   * SimpleSpeciesReference's 'name' attribute is set.
   *
   *
 *
 * 
 * In SBML Level&nbsp;3 Version&nbsp;2, the 'id' and 'name' attributes were
 * moved to SBase directly, instead of being defined individually for many
 * (but not all) objects.  Libsbml has for a long time provided functions
 * defined on SBase itself to get, set, and unset those attributes, which 
 * would fail or otherwise return empty strings if executed on any object 
 * for which those attributes were not defined.  Now that all SBase objects 
 * define those attributes, those functions now succeed for any object with 
 * the appropriate level and version.
 *
 * The 'name' attribute is
 * optional and is not intended to be used for cross-referencing purposes
 * within a model.  Its purpose instead is to provide a human-readable
 * label for the component.  The data type of 'name' is the type
 * <code>string</code> defined in XML Schema.  SBML imposes no
 * restrictions as to the content of 'name' attributes beyond those
 * restrictions defined by the <code>string</code> type in XML Schema.
 *
 * The recommended practice for handling 'name' is as follows.  If a
 * software tool has the capability for displaying the content of 'name'
 * attributes, it should display this content to the user as a
 * component's label instead of the component's 'id'.  If the user
 * interface does not have this capability (e.g., because it cannot
 * display or use special characters in symbol names), or if the 'name'
 * attribute is missing on a given component, then the user interface
 * should display the value of the 'id' attribute instead.  (Script
 * language interpreters are especially likely to display 'id' instead of
 * 'name'.)
 * 
 * As a consequence of the above, authors of systems that automatically
 * generate the values of 'id' attributes should be aware some systems
 * may display the 'id''s to the user.  Authors therefore may wish to
 * take some care to have their software create 'id' values that are: (a)
 * reasonably easy for humans to type and read; and (b) likely to be
 * meaningful, for example by making the 'id' attribute be an abbreviated
 * form of the name attribute value.
 * 
 * An additional point worth mentioning is although there are
 * restrictions on the uniqueness of 'id' values, there are no
 * restrictions on the uniqueness of 'name' values in a model.  This
 * allows software applications leeway in assigning component identifiers.
 *
 * Regardless of the level and version of the SBML, these functions allow
 * client applications to use more generalized code in some situations 
 * (for instance, when manipulating objects that are all known to have 
 * names).  If the object in question does not posess a 'name' attribute 
 * according to the SBML specification for the Level and Version in use,
 * libSBML will not allow the name to be set, nor will it read or 
 * write 'name' attributes for those objects.
 *
 *
 * 
 * @return @c true if the 'name' attribute of this SBML object is
 * set, @c false otherwise.
 *
 * @see getName()
 * @see setName(string sid)
 * @see unsetName()
 *
 *
   */ public new
 bool isSetName() {
    bool ret = libsbmlPINVOKE.SimpleSpeciesReference_isSetName(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if this
   * SimpleSpeciesReference's 'species' attribute is set.
   * 
   * @return @c true if the 'species' attribute of this
   * SimpleSpeciesReference is set, @c false otherwise.
   */ public
 bool isSetSpecies() {
    bool ret = libsbmlPINVOKE.SimpleSpeciesReference_isSetSpecies(swigCPtr);
    return ret;
  }

  
/**
   * Sets the 'species' attribute of this SimpleSpeciesReference.
   *
   * The identifier string passed in @p sid is copied.
   *
   * @param sid the identifier of a species defined in the enclosing
   * Model's ListOfSpecies.
   *
   *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbml#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE@endlink
   */ public
 int setSpecies(string sid) {
    int ret = libsbmlPINVOKE.SimpleSpeciesReference_setSpecies(swigCPtr, sid);
    return ret;
  }

  
/**
   * Sets the value of the 'id' attribute of this SimpleSpeciesReference.
   *
   *
 * 
 * The string @p sid is copied.
 *
 *
 * 
 * The identifier given by an object's 'id' attribute value
 * is used to identify the object within the SBML model definition.
 * Other objects can refer to the component using this identifier.  The
 * data type of 'id' is always <code>SId</code> or a type derived
 * from that, such as <code>UnitSId</code>, depending on the object in 
 * question.  All data types are defined as follows:
 * <pre style='margin-left: 2em; border: none; font-weight: bold; color: black'>
 *   letter ::= 'a'..'z','A'..'Z'
 *   digit  ::= '0'..'9'
 *   idChar ::= letter | digit | '_'
 *   SId    ::= ( letter | '_' ) idChar*
 * </pre>
 * The characters <code>(</code> and <code>)</code> are used for grouping, the
 * character <code>*</code> 'zero or more times', and the character
 * <code>|</code> indicates logical 'or'.  The equality of SBML identifiers is
 * determined by an exact character sequence match; i.e., comparisons must be
 * performed in a case-sensitive manner.  This applies to all uses of <code>SId</code>, 
 * <code>SIdRef</code>, and derived types.
 *
 * In SBML Level&nbsp;3 Version&nbsp;2, the 'id' and 'name' attributes were
 * moved to SBase directly, instead of being defined individually for many
 * (but not all) objects.  Libsbml has for a long time provided functions
 * defined on SBase itself to get, set, check, and unset those attributes, which 
 * would fail or otherwise return empty strings if executed on any object 
 * for which those attributes were not defined.  Now that all SBase objects 
 * define those attributes, those functions now succeed for any object with 
 * the appropriate level and version.
 *
 * The exception to this rule is that for InitialAssignment, EventAssignment, 
 * AssignmentRule, and RateRule objects, the getId() function and the isSetId() 
 * functions (though not the setId() or unsetId() functions) would instead 
 * reference the value of the 'variable' attribute (for the rules and event 
 * assignments) or the 'symbol' attribute (for initial assignments).  
 * The AlgebraicRule fell into this category as well, though because it 
 * contained neither a 'variable' nor a 'symbol' attribute, getId() would 
 * always return an empty string, and isSetId() would always return @c false.
 * For this reason, four new functions are now provided 
 * (getIdAttribute(), setIdAttribute(@if java String@endif), 
 * isSetIdAttribute(), and unsetIdAttribute()) that will always
 * act on the actual 'id' attribute, regardless of the object's type.  The
 * new functions should be used instead of the old ones unless the old behavior
 * is somehow necessary.
 * 
 * Regardless of the level and version of the SBML, these functions allow
 * client applications to use more generalized code in some situations 
 * (for instance, when manipulating objects that are all known to have 
 * identifiers).  If the object in question does not posess an 'id' attribute 
 * according to the SBML specification for the Level and Version in use,
 * libSBML will not allow the identifier to be set, nor will it read or 
 * write 'id' attributes for those objects.
 *
 *
 * 
 * @param sid the string to use as the identifier of this object.
 *
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
 * @li @link libsbml#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE@endlink
 * @li @link libsbml#LIBSBML_UNEXPECTED_ATTRIBUTE LIBSBML_UNEXPECTED_ATTRIBUTE@endlink
 *
 * @see getIdAttribute()
 * @see setIdAttribute(string sid)
 * @see isSetIdAttribute()
 * @see unsetIdAttribute()
 * 
 *
   */ public new
 int setId(string sid) {
    int ret = libsbmlPINVOKE.SimpleSpeciesReference_setId(swigCPtr, sid);
    return ret;
  }

  
/**
   * Sets the value of the 'name' attribute of this SimpleSpeciesReference.
   *
   *
 * 
 *
 * The string in @p name is copied.
 *
 * @param name the new name for the SBML object.
 *
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
 * @li @link libsbml#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE@endlink
 *
 *
   */ public new
 int setName(string name) {
    int ret = libsbmlPINVOKE.SimpleSpeciesReference_setName(swigCPtr, name);
    return ret;
  }

  
/**
   * Unsets the value of the 'id' attribute of this SimpleSpeciesReference.
   *
   *
 *
 * 
 * The identifier given by an object's 'id' attribute value
 * is used to identify the object within the SBML model definition.
 * Other objects can refer to the component using this identifier.  The
 * data type of 'id' is always <code>SId</code> or a type derived
 * from that, such as <code>UnitSId</code>, depending on the object in 
 * question.  All data types are defined as follows:
 * <pre style='margin-left: 2em; border: none; font-weight: bold; color: black'>
 *   letter ::= 'a'..'z','A'..'Z'
 *   digit  ::= '0'..'9'
 *   idChar ::= letter | digit | '_'
 *   SId    ::= ( letter | '_' ) idChar*
 * </pre>
 * The characters <code>(</code> and <code>)</code> are used for grouping, the
 * character <code>*</code> 'zero or more times', and the character
 * <code>|</code> indicates logical 'or'.  The equality of SBML identifiers is
 * determined by an exact character sequence match; i.e., comparisons must be
 * performed in a case-sensitive manner.  This applies to all uses of <code>SId</code>, 
 * <code>SIdRef</code>, and derived types.
 *
 * In SBML Level&nbsp;3 Version&nbsp;2, the 'id' and 'name' attributes were
 * moved to SBase directly, instead of being defined individually for many
 * (but not all) objects.  Libsbml has for a long time provided functions
 * defined on SBase itself to get, set, check, and unset those attributes, which 
 * would fail or otherwise return empty strings if executed on any object 
 * for which those attributes were not defined.  Now that all SBase objects 
 * define those attributes, those functions now succeed for any object with 
 * the appropriate level and version.
 *
 * The exception to this rule is that for InitialAssignment, EventAssignment, 
 * AssignmentRule, and RateRule objects, the getId() function and the isSetId() 
 * functions (though not the setId() or unsetId() functions) would instead 
 * reference the value of the 'variable' attribute (for the rules and event 
 * assignments) or the 'symbol' attribute (for initial assignments).  
 * The AlgebraicRule fell into this category as well, though because it 
 * contained neither a 'variable' nor a 'symbol' attribute, getId() would 
 * always return an empty string, and isSetId() would always return @c false.
 * For this reason, four new functions are now provided 
 * (getIdAttribute(), setIdAttribute(@if java String@endif), 
 * isSetIdAttribute(), and unsetIdAttribute()) that will always
 * act on the actual 'id' attribute, regardless of the object's type.  The
 * new functions should be used instead of the old ones unless the old behavior
 * is somehow necessary.
 * 
 * Regardless of the level and version of the SBML, these functions allow
 * client applications to use more generalized code in some situations 
 * (for instance, when manipulating objects that are all known to have 
 * identifiers).  If the object in question does not posess an 'id' attribute 
 * according to the SBML specification for the Level and Version in use,
 * libSBML will not allow the identifier to be set, nor will it read or 
 * write 'id' attributes for those objects.
 *
 *
 * 
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
 * @li @link libsbml#LIBSBML_OPERATION_FAILED LIBSBML_OPERATION_FAILED@endlink
 *
 * @see getIdAttribute()
 * @see setIdAttribute(string sid)
 * @see isSetIdAttribute()
 * @see unsetIdAttribute()
 *
 *
   */ public new
 int unsetId() {
    int ret = libsbmlPINVOKE.SimpleSpeciesReference_unsetId(swigCPtr);
    return ret;
  }

  
/**
   * Unsets the value of the 'name' attribute of this SimpleSpeciesReference.
   *
   *
 *
 * 
 * In SBML Level&nbsp;3 Version&nbsp;2, the 'id' and 'name' attributes were
 * moved to SBase directly, instead of being defined individually for many
 * (but not all) objects.  Libsbml has for a long time provided functions
 * defined on SBase itself to get, set, and unset those attributes, which 
 * would fail or otherwise return empty strings if executed on any object 
 * for which those attributes were not defined.  Now that all SBase objects 
 * define those attributes, those functions now succeed for any object with 
 * the appropriate level and version.
 *
 * The 'name' attribute is
 * optional and is not intended to be used for cross-referencing purposes
 * within a model.  Its purpose instead is to provide a human-readable
 * label for the component.  The data type of 'name' is the type
 * <code>string</code> defined in XML Schema.  SBML imposes no
 * restrictions as to the content of 'name' attributes beyond those
 * restrictions defined by the <code>string</code> type in XML Schema.
 *
 * The recommended practice for handling 'name' is as follows.  If a
 * software tool has the capability for displaying the content of 'name'
 * attributes, it should display this content to the user as a
 * component's label instead of the component's 'id'.  If the user
 * interface does not have this capability (e.g., because it cannot
 * display or use special characters in symbol names), or if the 'name'
 * attribute is missing on a given component, then the user interface
 * should display the value of the 'id' attribute instead.  (Script
 * language interpreters are especially likely to display 'id' instead of
 * 'name'.)
 * 
 * As a consequence of the above, authors of systems that automatically
 * generate the values of 'id' attributes should be aware some systems
 * may display the 'id''s to the user.  Authors therefore may wish to
 * take some care to have their software create 'id' values that are: (a)
 * reasonably easy for humans to type and read; and (b) likely to be
 * meaningful, for example by making the 'id' attribute be an abbreviated
 * form of the name attribute value.
 * 
 * An additional point worth mentioning is although there are
 * restrictions on the uniqueness of 'id' values, there are no
 * restrictions on the uniqueness of 'name' values in a model.  This
 * allows software applications leeway in assigning component identifiers.
 *
 * Regardless of the level and version of the SBML, these functions allow
 * client applications to use more generalized code in some situations 
 * (for instance, when manipulating objects that are all known to have 
 * names).  If the object in question does not posess a 'name' attribute 
 * according to the SBML specification for the Level and Version in use,
 * libSBML will not allow the name to be set, nor will it read or 
 * write 'name' attributes for those objects.
 *
 *
 * 
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
 * @li @link libsbml#LIBSBML_OPERATION_FAILED LIBSBML_OPERATION_FAILED@endlink
 *
 * @see getName()
 * @see setName(string sid)
 * @see isSetName()
 *
 *
   */ public new
 int unsetName() {
    int ret = libsbmlPINVOKE.SimpleSpeciesReference_unsetName(swigCPtr);
    return ret;
  }

  
/**
   * Unsets the value of the 'species' attribute of this SimpleSpeciesReference.
   *
   *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbml#LIBSBML_OPERATION_FAILED LIBSBML_OPERATION_FAILED@endlink
   */ public new
 int unsetSpecies() {
    int ret = libsbmlPINVOKE.SimpleSpeciesReference_unsetSpecies(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if this
   * is a ModifierSpeciesReference.
   * 
   * @return @c true if this SimpleSpeciesReference's subclass is
   * ModiferSpeciesReference, @c false if it is a plain SpeciesReference.
   */ public
 bool isModifier() {
    bool ret = libsbmlPINVOKE.SimpleSpeciesReference_isModifier(swigCPtr);
    return ret;
  }

  
/**
   *
 * Replaces all uses of a given @c SIdRef type attribute value with another
 * value.
 *
 *
 * 

 * In SBML, object identifiers are of a data type called <code>SId</code>.
 * In SBML Level&nbsp;3, an explicit data type called <code>SIdRef</code> was
 * introduced for attribute values that refer to <code>SId</code> values; in
 * previous Levels of SBML, this data type did not exist and attributes were
 * simply described to as 'referring to an identifier', but the effective
 * data type was the same as <code>SIdRef</code> in Level&nbsp;3.  These and
 * other methods of libSBML refer to the type <code>SIdRef</code> for all
 * Levels of SBML, even if the corresponding SBML specification did not
 * explicitly name the data type.
 *
 *
 *
 * This method works by looking at all attributes and (if appropriate)
 * mathematical formulas in MathML content, comparing the referenced
 * identifiers to the value of @p oldid.  If any matches are found, the
 * matching values are replaced with @p newid.  The method does @em not
 * descend into child elements.
 *
 * @param oldid the old identifier.
 * @param newid the new identifier.
 *
 *
   */ public new
 void renameSIdRefs(string oldid, string newid) {
    libsbmlPINVOKE.SimpleSpeciesReference_renameSIdRefs(swigCPtr, oldid, newid);
  }

}

}
