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
HWND glhPrevTarWnd=NULL;//�ϴ������ָ�Ĵ��ھ��
HWND glhDisplayWnd=NULL;//��ʾĿ�괰�ڱ���༭��ľ����
HHOOK glhHook=NULL;//��װ����깳�Ӿ��  
HINSTANCE glhInstance=NULL;//DLLʵ�����  
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
		//��DLL���붯̬MFC�����
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
//���Ӻ�����ʵ�֣�
LRESULT WINAPI MouseProc(int nCode,WPARAM wparam,LPARAM lparam)
{
	LPMOUSEHOOKSTRUCT pMouseHook=(MOUSEHOOKSTRUCT FAR *) lparam;
	   if (nCode>=0)
	   {
		   HWND glhTargetWnd=pMouseHook->hwnd;
		   //ȡĿ�괰�ھ��
		   HWND ParentWnd=glhTargetWnd;
		   while (ParentWnd !=NULL)
		   {
			   glhTargetWnd=ParentWnd;
			   //ȡӦ�ó��������ھ��
			   ParentWnd=GetParent(glhTargetWnd);
			   
		   }
		   if(glhTargetWnd!=glhPrevTarWnd)
		   {
			   char szCaption[100];
			   //ȡĿ�괰�ڱ���
			   GetWindowText(glhTargetWnd,szCaption,100);
			   
			   if(IsWindow(glhDisplayWnd))
				   SendMessage(glhDisplayWnd,WM_SETTEXT,0,(LPARAM)(LPCTSTR)szCaption);
			   //����Ŀ�괰��
			   glhPrevTarWnd=glhTargetWnd;
			   
		   }
	   }
	   
       //����������Ϣ
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
	//������ʾĿ�괰�ڱ���༭��ľ��
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
