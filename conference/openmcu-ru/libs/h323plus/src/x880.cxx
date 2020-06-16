//
// x880.cxx
//
// Code automatically generated by asnparse.
//

#ifdef P_USE_PRAGMA
#pragma implementation "x880.h"
#endif

#include <ptlib.h>
#include "x880.h"

#define new PNEW


#if ! H323_DISABLE_X880


#ifndef PASN_NOPRINTON
const static PASN_Names Names_X880_ROS[]={
      {"invoke",0}
     ,{"returnResult",1}
     ,{"returnError",2}
     ,{"reject",3}
};
#endif
//
// ROS
//

X880_ROS::X880_ROS(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Choice(tag, tagClass, 4, FALSE
#ifndef PASN_NOPRINTON
    ,(const PASN_Names *)Names_X880_ROS,4
#endif
)
{
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_ROS::operator X880_Invoke &() const
#else
X880_ROS::operator X880_Invoke &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_Invoke), PInvalidCast);
#endif
  return *(X880_Invoke *)choice;
}


X880_ROS::operator const X880_Invoke &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_Invoke), PInvalidCast);
#endif
  return *(X880_Invoke *)choice;
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_ROS::operator X880_ReturnResult &() const
#else
X880_ROS::operator X880_ReturnResult &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnResult), PInvalidCast);
#endif
  return *(X880_ReturnResult *)choice;
}


X880_ROS::operator const X880_ReturnResult &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnResult), PInvalidCast);
#endif
  return *(X880_ReturnResult *)choice;
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_ROS::operator X880_ReturnError &() const
#else
X880_ROS::operator X880_ReturnError &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnError), PInvalidCast);
#endif
  return *(X880_ReturnError *)choice;
}


X880_ROS::operator const X880_ReturnError &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnError), PInvalidCast);
#endif
  return *(X880_ReturnError *)choice;
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_ROS::operator X880_Reject &() const
#else
X880_ROS::operator X880_Reject &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_Reject), PInvalidCast);
#endif
  return *(X880_Reject *)choice;
}


X880_ROS::operator const X880_Reject &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_Reject), PInvalidCast);
#endif
  return *(X880_Reject *)choice;
}


BOOL X880_ROS::CreateObject()
{
  switch (tag) {
    case e_invoke :
      choice = new X880_Invoke(1, ContextSpecificTagClass);
      return TRUE;
    case e_returnResult :
      choice = new X880_ReturnResult(2, ContextSpecificTagClass);
      return TRUE;
    case e_returnError :
      choice = new X880_ReturnError(3, ContextSpecificTagClass);
      return TRUE;
    case e_reject :
      choice = new X880_Reject(4, ContextSpecificTagClass);
      return TRUE;
  }

  choice = NULL;
  return FALSE;
}


PObject * X880_ROS::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_ROS::Class()), PInvalidCast);
#endif
  return new X880_ROS(*this);
}


//
// GeneralProblem
//

X880_GeneralProblem::X880_GeneralProblem(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Integer(tag, tagClass)
{
}


X880_GeneralProblem & X880_GeneralProblem::operator=(int v)
{
  SetValue(v);
  return *this;
}


X880_GeneralProblem & X880_GeneralProblem::operator=(unsigned v)
{
  SetValue(v);
  return *this;
}


PObject * X880_GeneralProblem::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_GeneralProblem::Class()), PInvalidCast);
#endif
  return new X880_GeneralProblem(*this);
}


//
// InvokeProblem
//

X880_InvokeProblem::X880_InvokeProblem(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Integer(tag, tagClass)
{
}


X880_InvokeProblem & X880_InvokeProblem::operator=(int v)
{
  SetValue(v);
  return *this;
}


X880_InvokeProblem & X880_InvokeProblem::operator=(unsigned v)
{
  SetValue(v);
  return *this;
}


PObject * X880_InvokeProblem::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_InvokeProblem::Class()), PInvalidCast);
#endif
  return new X880_InvokeProblem(*this);
}


//
// ReturnResultProblem
//

X880_ReturnResultProblem::X880_ReturnResultProblem(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Integer(tag, tagClass)
{
}


X880_ReturnResultProblem & X880_ReturnResultProblem::operator=(int v)
{
  SetValue(v);
  return *this;
}


X880_ReturnResultProblem & X880_ReturnResultProblem::operator=(unsigned v)
{
  SetValue(v);
  return *this;
}


PObject * X880_ReturnResultProblem::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_ReturnResultProblem::Class()), PInvalidCast);
#endif
  return new X880_ReturnResultProblem(*this);
}


//
// ReturnErrorProblem
//

X880_ReturnErrorProblem::X880_ReturnErrorProblem(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Integer(tag, tagClass)
{
}


X880_ReturnErrorProblem & X880_ReturnErrorProblem::operator=(int v)
{
  SetValue(v);
  return *this;
}


X880_ReturnErrorProblem & X880_ReturnErrorProblem::operator=(unsigned v)
{
  SetValue(v);
  return *this;
}


PObject * X880_ReturnErrorProblem::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_ReturnErrorProblem::Class()), PInvalidCast);
#endif
  return new X880_ReturnErrorProblem(*this);
}


//
// RejectProblem
//

X880_RejectProblem::X880_RejectProblem(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Integer(tag, tagClass)
{
}


X880_RejectProblem & X880_RejectProblem::operator=(int v)
{
  SetValue(v);
  return *this;
}


X880_RejectProblem & X880_RejectProblem::operator=(unsigned v)
{
  SetValue(v);
  return *this;
}


PObject * X880_RejectProblem::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_RejectProblem::Class()), PInvalidCast);
#endif
  return new X880_RejectProblem(*this);
}


//
// InvokeId
//

X880_InvokeId::X880_InvokeId(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Integer(tag, tagClass)
{
}


X880_InvokeId & X880_InvokeId::operator=(int v)
{
  SetValue(v);
  return *this;
}


X880_InvokeId & X880_InvokeId::operator=(unsigned v)
{
  SetValue(v);
  return *this;
}


PObject * X880_InvokeId::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_InvokeId::Class()), PInvalidCast);
#endif
  return new X880_InvokeId(*this);
}



#ifndef PASN_NOPRINTON
const static PASN_Names Names_X880_Code[]={
      {"local",0}
     ,{"global",1}
};
#endif
//
// Code
//

X880_Code::X880_Code(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Choice(tag, tagClass, 2, FALSE
#ifndef PASN_NOPRINTON
    ,(const PASN_Names *)Names_X880_Code,2
#endif
)
{
}


BOOL X880_Code::CreateObject()
{
  switch (tag) {
    case e_local :
      choice = new PASN_Integer();
      return TRUE;
    case e_global :
      choice = new PASN_ObjectId();
      return TRUE;
  }

  choice = NULL;
  return FALSE;
}


PObject * X880_Code::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_Code::Class()), PInvalidCast);
#endif
  return new X880_Code(*this);
}


//
// ReturnResult_result
//

X880_ReturnResult_result::X880_ReturnResult_result(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 0, TRUE, 0)
{
}


#ifndef PASN_NOPRINTON
void X880_ReturnResult_result::PrintOn(ostream & strm) const
{
  int indent = (int)strm.precision() + 2;
  strm << "{\n";
  strm << setw(indent+9) << "opcode = " << setprecision(indent) << m_opcode << '\n';
  strm << setw(indent+9) << "result = " << setprecision(indent) << m_result << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison X880_ReturnResult_result::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, X880_ReturnResult_result), PInvalidCast);
#endif
  const X880_ReturnResult_result & other = (const X880_ReturnResult_result &)obj;

  Comparison result;

  if ((result = m_opcode.Compare(other.m_opcode)) != EqualTo)
    return result;
  if ((result = m_result.Compare(other.m_result)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX X880_ReturnResult_result::GetDataLength() const
{
  PINDEX length = 0;
  length += m_opcode.GetObjectLength();
  length += m_result.GetObjectLength();
  return length;
}


BOOL X880_ReturnResult_result::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return FALSE;

  if (!m_opcode.Decode(strm))
    return FALSE;
  if (!m_result.Decode(strm))
    return FALSE;

  return UnknownExtensionsDecode(strm);
}


void X880_ReturnResult_result::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  m_opcode.Encode(strm);
  m_result.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * X880_ReturnResult_result::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_ReturnResult_result::Class()), PInvalidCast);
#endif
  return new X880_ReturnResult_result(*this);
}



#ifndef PASN_NOPRINTON
const static PASN_Names Names_X880_Reject_problem[]={
      {"general",0}
     ,{"invoke",1}
     ,{"returnResult",2}
     ,{"returnError",3}
};
#endif
//
// Reject_problem
//

X880_Reject_problem::X880_Reject_problem(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Choice(tag, tagClass, 4, FALSE
#ifndef PASN_NOPRINTON
    ,(const PASN_Names *)Names_X880_Reject_problem,4
#endif
)
{
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_Reject_problem::operator X880_GeneralProblem &() const
#else
X880_Reject_problem::operator X880_GeneralProblem &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_GeneralProblem), PInvalidCast);
#endif
  return *(X880_GeneralProblem *)choice;
}


X880_Reject_problem::operator const X880_GeneralProblem &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_GeneralProblem), PInvalidCast);
#endif
  return *(X880_GeneralProblem *)choice;
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_Reject_problem::operator X880_InvokeProblem &() const
#else
X880_Reject_problem::operator X880_InvokeProblem &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_InvokeProblem), PInvalidCast);
#endif
  return *(X880_InvokeProblem *)choice;
}


X880_Reject_problem::operator const X880_InvokeProblem &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_InvokeProblem), PInvalidCast);
#endif
  return *(X880_InvokeProblem *)choice;
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_Reject_problem::operator X880_ReturnResultProblem &() const
#else
X880_Reject_problem::operator X880_ReturnResultProblem &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnResultProblem), PInvalidCast);
#endif
  return *(X880_ReturnResultProblem *)choice;
}


X880_Reject_problem::operator const X880_ReturnResultProblem &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnResultProblem), PInvalidCast);
#endif
  return *(X880_ReturnResultProblem *)choice;
}


#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
X880_Reject_problem::operator X880_ReturnErrorProblem &() const
#else
X880_Reject_problem::operator X880_ReturnErrorProblem &()
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnErrorProblem), PInvalidCast);
#endif
  return *(X880_ReturnErrorProblem *)choice;
}


X880_Reject_problem::operator const X880_ReturnErrorProblem &() const
#endif
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(PAssertNULL(choice), X880_ReturnErrorProblem), PInvalidCast);
#endif
  return *(X880_ReturnErrorProblem *)choice;
}


BOOL X880_Reject_problem::CreateObject()
{
  switch (tag) {
    case e_general :
      choice = new X880_GeneralProblem();
      return TRUE;
    case e_invoke :
      choice = new X880_InvokeProblem();
      return TRUE;
    case e_returnResult :
      choice = new X880_ReturnResultProblem();
      return TRUE;
    case e_returnError :
      choice = new X880_ReturnErrorProblem();
      return TRUE;
  }

  choice = NULL;
  return FALSE;
}


PObject * X880_Reject_problem::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_Reject_problem::Class()), PInvalidCast);
#endif
  return new X880_Reject_problem(*this);
}


//
// Invoke
//

X880_Invoke::X880_Invoke(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 2, FALSE, 0)
{
  m_invokeId.SetConstraints(PASN_Object::FixedConstraint, 0, 65535);
}


#ifndef PASN_NOPRINTON
void X880_Invoke::PrintOn(ostream & strm) const
{
  int indent = (int)strm.precision() + 2;
  strm << "{\n";
  strm << setw(indent+11) << "invokeId = " << setprecision(indent) << m_invokeId << '\n';
  if (HasOptionalField(e_linkedId))
    strm << setw(indent+11) << "linkedId = " << setprecision(indent) << m_linkedId << '\n';
  strm << setw(indent+9) << "opcode = " << setprecision(indent) << m_opcode << '\n';
  if (HasOptionalField(e_argument))
    strm << setw(indent+11) << "argument = " << setprecision(indent) << m_argument << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison X880_Invoke::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, X880_Invoke), PInvalidCast);
#endif
  const X880_Invoke & other = (const X880_Invoke &)obj;

  Comparison result;

  if ((result = m_invokeId.Compare(other.m_invokeId)) != EqualTo)
    return result;
  if ((result = m_linkedId.Compare(other.m_linkedId)) != EqualTo)
    return result;
  if ((result = m_opcode.Compare(other.m_opcode)) != EqualTo)
    return result;
  if ((result = m_argument.Compare(other.m_argument)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX X880_Invoke::GetDataLength() const
{
  PINDEX length = 0;
  length += m_invokeId.GetObjectLength();
  if (HasOptionalField(e_linkedId))
    length += m_linkedId.GetObjectLength();
  length += m_opcode.GetObjectLength();
  if (HasOptionalField(e_argument))
    length += m_argument.GetObjectLength();
  return length;
}


BOOL X880_Invoke::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return FALSE;

  if (!m_invokeId.Decode(strm))
    return FALSE;
  if (HasOptionalField(e_linkedId) && !m_linkedId.Decode(strm))
    return FALSE;
  if (!m_opcode.Decode(strm))
    return FALSE;
  if (HasOptionalField(e_argument) && !m_argument.Decode(strm))
    return FALSE;

  return UnknownExtensionsDecode(strm);
}


void X880_Invoke::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  m_invokeId.Encode(strm);
  if (HasOptionalField(e_linkedId))
    m_linkedId.Encode(strm);
  m_opcode.Encode(strm);
  if (HasOptionalField(e_argument))
    m_argument.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * X880_Invoke::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_Invoke::Class()), PInvalidCast);
#endif
  return new X880_Invoke(*this);
}


//
// ReturnResult
//

X880_ReturnResult::X880_ReturnResult(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 1, FALSE, 0)
{
}


#ifndef PASN_NOPRINTON
void X880_ReturnResult::PrintOn(ostream & strm) const
{
  int indent = (int)strm.precision() + 2;
  strm << "{\n";
  strm << setw(indent+11) << "invokeId = " << setprecision(indent) << m_invokeId << '\n';
  if (HasOptionalField(e_result))
    strm << setw(indent+9) << "result = " << setprecision(indent) << m_result << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison X880_ReturnResult::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, X880_ReturnResult), PInvalidCast);
#endif
  const X880_ReturnResult & other = (const X880_ReturnResult &)obj;

  Comparison result;

  if ((result = m_invokeId.Compare(other.m_invokeId)) != EqualTo)
    return result;
  if ((result = m_result.Compare(other.m_result)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX X880_ReturnResult::GetDataLength() const
{
  PINDEX length = 0;
  length += m_invokeId.GetObjectLength();
  if (HasOptionalField(e_result))
    length += m_result.GetObjectLength();
  return length;
}


BOOL X880_ReturnResult::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return FALSE;

  if (!m_invokeId.Decode(strm))
    return FALSE;
  if (HasOptionalField(e_result) && !m_result.Decode(strm))
    return FALSE;

  return UnknownExtensionsDecode(strm);
}


void X880_ReturnResult::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  m_invokeId.Encode(strm);
  if (HasOptionalField(e_result))
    m_result.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * X880_ReturnResult::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_ReturnResult::Class()), PInvalidCast);
#endif
  return new X880_ReturnResult(*this);
}


//
// ReturnError
//

X880_ReturnError::X880_ReturnError(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 1, FALSE, 0)
{
}


#ifndef PASN_NOPRINTON
void X880_ReturnError::PrintOn(ostream & strm) const
{
  int indent = (int)strm.precision() + 2;
  strm << "{\n";
  strm << setw(indent+11) << "invokeId = " << setprecision(indent) << m_invokeId << '\n';
  strm << setw(indent+12) << "errorCode = " << setprecision(indent) << m_errorCode << '\n';
  if (HasOptionalField(e_parameter))
    strm << setw(indent+12) << "parameter = " << setprecision(indent) << m_parameter << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison X880_ReturnError::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, X880_ReturnError), PInvalidCast);
#endif
  const X880_ReturnError & other = (const X880_ReturnError &)obj;

  Comparison result;

  if ((result = m_invokeId.Compare(other.m_invokeId)) != EqualTo)
    return result;
  if ((result = m_errorCode.Compare(other.m_errorCode)) != EqualTo)
    return result;
  if ((result = m_parameter.Compare(other.m_parameter)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX X880_ReturnError::GetDataLength() const
{
  PINDEX length = 0;
  length += m_invokeId.GetObjectLength();
  length += m_errorCode.GetObjectLength();
  if (HasOptionalField(e_parameter))
    length += m_parameter.GetObjectLength();
  return length;
}


BOOL X880_ReturnError::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return FALSE;

  if (!m_invokeId.Decode(strm))
    return FALSE;
  if (!m_errorCode.Decode(strm))
    return FALSE;
  if (HasOptionalField(e_parameter) && !m_parameter.Decode(strm))
    return FALSE;

  return UnknownExtensionsDecode(strm);
}


void X880_ReturnError::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  m_invokeId.Encode(strm);
  m_errorCode.Encode(strm);
  if (HasOptionalField(e_parameter))
    m_parameter.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * X880_ReturnError::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_ReturnError::Class()), PInvalidCast);
#endif
  return new X880_ReturnError(*this);
}


//
// Reject
//

X880_Reject::X880_Reject(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 0, FALSE, 0)
{
}


#ifndef PASN_NOPRINTON
void X880_Reject::PrintOn(ostream & strm) const
{
  int indent = (int)strm.precision() + 2;
  strm << "{\n";
  strm << setw(indent+11) << "invokeId = " << setprecision(indent) << m_invokeId << '\n';
  strm << setw(indent+10) << "problem = " << setprecision(indent) << m_problem << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison X880_Reject::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, X880_Reject), PInvalidCast);
#endif
  const X880_Reject & other = (const X880_Reject &)obj;

  Comparison result;

  if ((result = m_invokeId.Compare(other.m_invokeId)) != EqualTo)
    return result;
  if ((result = m_problem.Compare(other.m_problem)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX X880_Reject::GetDataLength() const
{
  PINDEX length = 0;
  length += m_invokeId.GetObjectLength();
  length += m_problem.GetObjectLength();
  return length;
}


BOOL X880_Reject::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return FALSE;

  if (!m_invokeId.Decode(strm))
    return FALSE;
  if (!m_problem.Decode(strm))
    return FALSE;

  return UnknownExtensionsDecode(strm);
}


void X880_Reject::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  m_invokeId.Encode(strm);
  m_problem.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * X880_Reject::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(X880_Reject::Class()), PInvalidCast);
#endif
  return new X880_Reject(*this);
}


#endif // if ! H323_DISABLE_X880


// End of x880.cxx
