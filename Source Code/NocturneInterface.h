// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <guiddef.h>

#define WSTRING const wchar_t*
#define LIBRARY_VERSION  1

typedef struct _IUnknown
{
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) = 0;
	virtual ULONG __stdcall AddRef() = 0;
	virtual ULONG __stdcall Release() = 0;
} IUnknown;

// {4E9102D8-33E7-4A8A-B9C9-C8CE186A7929}
static const GUID CLSID_NOCSTRING =
{ 0x4e9102d8, 0x33e7, 0x4a8a,{ 0xb9, 0xc9, 0xc8, 0xce, 0x18, 0x6a, 0x79, 0x29 } };

// {9B5E4DAA-A93B-4B32-81BB-73A949FF2695}
static const GUID IID_NOCSTRING =
{ 0x9b5e4daa, 0xa93b, 0x4b32,{ 0x81, 0xbb, 0x73, 0xa9, 0x49, 0xff, 0x26, 0x95 } };

struct INocString : public IUnknown
{
	virtual HRESULT __stdcall Set(WSTRING pStrVal) = 0;
	virtual WSTRING __stdcall Get() = 0;
};

// {4463DEF3-C63C-44FF-8556-9796BFF51BFE}
static const GUID CLSID_CONVERSATION =
{ 0x4463def3, 0xc63c, 0x44ff,{ 0x85, 0x56, 0x97, 0x96, 0xbf, 0xf5, 0x1b, 0xfe } };

// {E31C48EE-E372-4021-8058-86EB0232FE26}
static const GUID IID_CONVERSATION =
{ 0xe31c48ee, 0xe372, 0x4021,{ 0x80, 0x58, 0x86, 0xeb, 0x2, 0x32, 0xfe, 0x26 } };


struct IConversation : public IUnknown
{
	virtual HRESULT __stdcall GoToStart() = 0;
	virtual HRESULT __stdcall Save() = 0;
	virtual HRESULT __stdcall FormatCurrentLine(INocString* iStr) = 0;
};

/**
 * 
 */
class NOCTURNE_EDITOR_API NocturneInterface
{
public:
	NocturneInterface();
	~NocturneInterface();
};
