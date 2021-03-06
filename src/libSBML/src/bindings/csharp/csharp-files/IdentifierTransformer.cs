using System;
using System.Runtime.InteropServices;
 
//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.12
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace libsbmlcs {

 using System;
 using System.Runtime.InteropServices;

/** 
 * @sbmlpackage{core}
 *
@htmlinclude pkg-marker-core.html Base class for identifier transformers.
 * @internal
 */

public class IdentifierTransformer : global::System.IDisposable {
	private HandleRef swigCPtr;
	protected bool swigCMemOwn;
	
	internal IdentifierTransformer(IntPtr cPtr, bool cMemoryOwn)
	{
		swigCMemOwn = cMemoryOwn;
		swigCPtr    = new HandleRef(this, cPtr);
	}
	
	internal static HandleRef getCPtr(IdentifierTransformer obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}
	
	internal static HandleRef getCPtrAndDisown (IdentifierTransformer obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);
		
		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}
		
		return ptr;
	}

  ~IdentifierTransformer() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_IdentifierTransformer(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public IdentifierTransformer() : this(libsbmlPINVOKE.new_IdentifierTransformer(), true) {
    SwigDirectorConnect();
  }

  public virtual int transform(SBase element) {
    int ret = (SwigDerivedClassHasMethod("transform", swigMethodTypes0) ? libsbmlPINVOKE.IdentifierTransformer_transformSwigExplicitIdentifierTransformer(swigCPtr, SBase.getCPtr(element)) : libsbmlPINVOKE.IdentifierTransformer_transform(swigCPtr, SBase.getCPtr(element)));
    return ret;
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("transform", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateIdentifierTransformer_0(SwigDirectortransform);
    libsbmlPINVOKE.IdentifierTransformer_director_connect(swigCPtr, swigDelegate0);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(IdentifierTransformer));
    return hasDerivedMethod;
  }

  private int SwigDirectortransform(global::System.IntPtr element) {
    return transform((element == global::System.IntPtr.Zero) ? null : new SBase(element, false));
  }

  public delegate int SwigDelegateIdentifierTransformer_0(global::System.IntPtr element);

  private SwigDelegateIdentifierTransformer_0 swigDelegate0;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] { typeof(SBase) };
}

}
