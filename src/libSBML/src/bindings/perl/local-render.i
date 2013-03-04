/**
 * Filename    : local-render.i
 * Description : SBML Render include file for bindings to downcast elements
 *
 * Contributor(s):
 */

#ifdef USE_RENDER

SBMLCONSTRUCTOR_EXCEPTION(ColorDefinition)
SBMLCONSTRUCTOR_EXCEPTION(Ellipse)
SBMLCONSTRUCTOR_EXCEPTION(GlobalRenderInformation)
SBMLCONSTRUCTOR_EXCEPTION(GlobalStyle)
SBMLCONSTRUCTOR_EXCEPTION(Group)
SBMLCONSTRUCTOR_EXCEPTION(RenderGroup)
SBMLCONSTRUCTOR_EXCEPTION(GradientDefinition)
SBMLCONSTRUCTOR_EXCEPTION(GradientStop)
SBMLCONSTRUCTOR_EXCEPTION(Image)
SBMLCONSTRUCTOR_EXCEPTION(LineEnding)
SBMLCONSTRUCTOR_EXCEPTION(LinearGradient)
SBMLCONSTRUCTOR_EXCEPTION(LocalRenderInformation)
SBMLCONSTRUCTOR_EXCEPTION(LocalStyle)
SBMLCONSTRUCTOR_EXCEPTION(Polygon)
SBMLCONSTRUCTOR_EXCEPTION(RadialGradient)
SBMLCONSTRUCTOR_EXCEPTION(Rectangle)
SBMLCONSTRUCTOR_EXCEPTION(RenderCubicBezier)
SBMLCONSTRUCTOR_EXCEPTION(RenderCurve)
SBMLCONSTRUCTOR_EXCEPTION(RenderPoint)
SBMLCONSTRUCTOR_EXCEPTION(Text)
SBMLCONSTRUCTOR_EXCEPTION(RenderPkgNamespaces)

SBMLCONSTRUCTOR_EXCEPTION(ListOfGlobalRenderInformation)
SBMLCONSTRUCTOR_EXCEPTION(ListOfLocalStyles)
SBMLCONSTRUCTOR_EXCEPTION(ListOfGlobalStyles)
SBMLCONSTRUCTOR_EXCEPTION(ListOfGradientDefinitions)
SBMLCONSTRUCTOR_EXCEPTION(ListOfColorDefinitions)
SBMLCONSTRUCTOR_EXCEPTION(ListOfLineEndings)
SBMLCONSTRUCTOR_EXCEPTION(ListOfCurveElements)
SBMLCONSTRUCTOR_EXCEPTION(ListOfLocalRenderInformation)
SBMLCONSTRUCTOR_EXCEPTION(ListOfDrawables)
SBMLCONSTRUCTOR_EXCEPTION(ListOfGradientStops)
SBMLCONSTRUCTOR_EXCEPTION(Polygon)
SBMLCONSTRUCTOR_EXCEPTION(RadialGradient)


/**
 * Convert GradientBase objects into the most specific type possible.
 */
%typemap(out) GradientBase*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigTypeForPackage($1, "render"), $owner | %newpointer_flags);
}

/**
 * Convert GraphicalPrimitive1D objects into the most specific type possible.
 */
%typemap(out) GraphicalPrimitive1D*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigTypeForPackage($1, "render"), $owner | %newpointer_flags);
}

/**
 * Convert GraphicalPrimitive2D objects into the most specific type possible.
 */
%typemap(out) GraphicalPrimitive2D*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigTypeForPackage($1, "render"), $owner | %newpointer_flags);
}


/**
 * Convert RenderInformationBase objects into the most specific type possible.
 */
%typemap(out) RenderInformationBase*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigTypeForPackage($1, "render"), $owner | %newpointer_flags);
}


/**
 * Convert Style objects into the most specific type possible.
 */
%typemap(out) Style*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigTypeForPackage($1, "render"), $owner | %newpointer_flags);
}


/**
 * Convert RenderPoint objects into the most specific type possible.
 */
%typemap(out) RenderPoint*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigTypeForPackage($1, "render"), $owner | %newpointer_flags);
}


#endif

