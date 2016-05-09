// GMouseHook.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>
#include"Mousehook.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#pragma data_seg("mydata")
HWND glhPrevTarWnd=NULL;//上次鼠标所指的窗口句柄
HWND glhDisplayWnd=NULL;//显示目标窗口标题编辑框的句柄　
HHOOK glhHook=NULL;//安装的鼠标钩子句柄  
HINSTANCE glhInstance=NULL;//DLL实例句柄  
#pragma data_seg() 

static AFX_EXTENSION_MODULE GMouseHookDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("GMOUSEHOOK.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(GMouseHookDLL, hInstance))
		   return 0;
		new CDynLinkLibrary(GMouseHookDLL);
		//把DLL加入动态MFC类库中
        glhInstance=hInstance; 
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("GMOUSEHOOK.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(GMouseHookDLL);
	}
	return 1;   // ok
}
//钩子函数的实现：
LRESULT WINAPI MouseProc(int nCode,WPARAM wparam,LPARAM lparam)
{
	LPMOUSEHOOKSTRUCT pMouseHook=(MOUSEHOOKSTRUCT FAR *) lparam;
	   if (nCode>=0)
	   {
		   HWND glhTargetWnd=pMouseHook->hwnd;
		   //取目标窗口句柄
		   HWND ParentWnd=glhTargetWnd;
		   while (ParentWnd !=NULL)
		   {
			   glhTargetWnd=ParentWnd;
			   //取应用程序主窗口句柄
			   ParentWnd=GetParent(glhTargetWnd);
			   
		   }
		   if(glhTargetWnd!=glhPrevTarWnd)
		   {
			   char szCaption[100];
			   //取目标窗口标题
			   GetWindowText(glhTargetWnd,szCaption,100);
			   
			   if(IsWindow(glhDisplayWnd))
				   SendMessage(glhDisplayWnd,WM_SETTEXT,0,(LPARAM)(LPCTSTR)szCaption);
			   //保存目标窗口
			   glhPrevTarWnd=glhTargetWnd;
			   
		   }
	   }
	   
       //继续传递消息
	   return CallNextHookEx(glhHook,nCode,wparam,lparam);
	   
} 
Cmousehook::Cmousehook()
{
}
Cmousehook::~Cmousehook()
{
	stophook();
}
BOOL Cmousehook::starthook(HWND hWnd)
{
	BOOL bResult=FALSE;
	glhHook=SetWindowsHookEx(WH_MOUSE,MouseProc,glhInstance,0);
	if(glhHook!=NULL)
		bResult=TRUE;
	//设置显示目标窗口标题编辑框的句柄
	glhDisplayWnd=hWnd;
   return bResult;
}
BOOL Cmousehook::stophook()
{
	BOOL bResult=FALSE;
	if(glhHook)
		  {
		bResult= UnhookWindowsHookEx(glhHook);
		if(bResult)
		{
			glhPrevTarWnd=NULL;
			glhDisplayWnd=NULL;
			glhHook=NULL;
		}
		  }
	return bResult;
}
