; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMsgSet
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCODBC.h"

ClassCount=4
Class1=CMFCODBCApp
Class2=CMFCODBCDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_MFCODBC_DIALOG
Resource2=IDR_MAINFRAME
Class4=CMsgSet
Resource3=IDD_ABOUTBOX

[CLS:CMFCODBCApp]
Type=0
HeaderFile=MFCODBC.h
ImplementationFile=MFCODBC.cpp
Filter=N

[CLS:CMFCODBCDlg]
Type=0
HeaderFile=MFCODBCDlg.h
ImplementationFile=MFCODBCDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCODBCDlg.h
ImplementationFile=MFCODBCDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFCODBC_DIALOG]
Type=1
Class=CMFCODBCDlg
ControlCount=3
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_SHOW,button,1342242816
Control3=IDC_BIND,button,1342242816

[CLS:CMsgSet]
Type=0
HeaderFile=MsgSet.h
ImplementationFile=MsgSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CMsgSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[MSG_ID], 12, 100
Column2=[MSG_SENDER], 12, 100
Column3=[MSG_RECEIVER], 12, 100
Column4=[MSG_DATE], 12, 100
Column5=[MSG_CONTENT], 12, 100

