#pragma once

// C++ includes
#include <Windows.h>
#include <vcclr.h>
#include <memory.h>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cmath>
#include <cfloat>
#include <ctime>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <sys/stat.h>


using std::memcpy;
using std::size_t;
using std::min;
using std::max;
using std::ostream;
using std::basic_ostream;
using std::endl;
using std::string;

#if defined(WIN32)
#pragma warning( disable : 4005 )
#pragma warning( disable : 4172 )
#pragma warning( disable : 4189)
#pragma warning( disable : 4244 )
#pragma warning( disable : 4267 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4390 )
#pragma warning( disable : 4456 )
#pragma warning( disable : 4458 )
#pragma warning( disable : 4477 )
#pragma warning( disable : 4701 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4996 )
#endif

#include <Ogre.h>

// .NET namespaces
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

#define ThrowIfNull(var, varName)\
{\
	if (var == nullptr)\
	throw gcnew ArgumentNullException(varName);\
}
#define ThrowIfNullOrDisposed(var, varName)\
{\
	if (var == nullptr)\
	throw gcnew ArgumentNullException(varName);\
	if (var->Disposed)\
	throw gcnew ArgumentException("Argument is disposed", varName);\
}
#define ThrowIfDisposed(var, varName)\
{\
	if (var != nullptr && var->IsDisposed)\
	throw gcnew ArgumentException("Argument is disposed", varName);\
}
#define ThrowIfDescriptionIsNullOrInvalid(var, varName)\
{\
	ThrowIfNull(var, varName);\
	\
	if(!var->IsValid())\
	throw gcnew ArgumentException("Description is invalid", varName);\
}
#define ThrowIfThisDisposed() { if (this->Disposed) throw gcnew InvalidOperationException("The instance has been disposed of, no further operations should be performed."); }

inline void* GCHandleToVoidPtr(GCHandle handle)
{
	return GCHandle::ToIntPtr(handle).ToPointer();
}

inline GCHandle VoidPtrToGCHandle(void* pointer)
{
	return GCHandle::FromIntPtr(System::IntPtr(pointer));
}

#define GetPointerOrNull(obj) (obj == nullptr ? NULL : obj->UnmanagedPointer)
#define GetUnmanagedNullable(value) (value != nullptr ? value->_native : 0)
#define ReturnCachedObject(type, managedObj, unmanagedPtr) { \
	if (managedObj != nullptr && managedObj->_native == unmanagedPtr) \
		return managedObj; \
	managedObj = type::GetManaged(unmanagedPtr); \
	return managedObj; }

#define ReturnCachedObjectGcnew(type, managedObj, unmanagedPtr) { \
	if (managedObj != nullptr && managedObj->_native == unmanagedPtr) \
		return managedObj; \
	managedObj = gcnew type(unmanagedPtr); \
	return managedObj; }

#define ReturnCachedObjectGcnewNullable(type, managedObj, unmanagedPtr) { \
	if (managedObj != nullptr && managedObj->_native == unmanagedPtr) \
		return managedObj; \
	if (unmanagedPtr == 0) \
		return nullptr; \
	managedObj = gcnew type(unmanagedPtr); \
	return managedObj; }

#define MOGRE_HANDLE "MOGRE_HANDLE"

template <class T, class U>
bool IsInstanceOf(U u)
{
	return dynamic_cast<T>(u) != nullptr;
}

template <typename T, unsigned int N>
inline unsigned int ArraySize(T(&)[N])
{
	return N;
}

template <typename T>
void SafeDelete(T*& resource)
{
	delete resource;
	resource = nullptr;
}
template <typename T>
void SafeDeleteArray(T*& resource)
{
	delete[] resource;
	resource = nullptr;
}