; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRVTestView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RVTest.h"
LastPage=0

ClassCount=6
Class1=CRVTestApp
Class2=CRVTestDoc
Class3=CRVTestView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource7=IDD_RVTEST_FORM
Class5=CRVTestSet

[CLS:CRVTestApp]
Type=0
HeaderFile=RVTest.h
ImplementationFile=RVTest.cpp
Filter=N

[CLS:CRVTestDoc]
Type=0
HeaderFile=RVTestDoc.h
ImplementationFile=RVTestDoc.cpp
Filter=N

[CLS:CRVTestView]
Type=0
HeaderFile=RVTestView.h
ImplementationFile=RVTestView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=CRVTestView


[CLS:CRVTestSet]
Type=0
HeaderFile=RVTestSet.h
ImplementationFile=RVTestSet.cpp
Filter=N

[DB:CRVTestSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[MSG_ID], 12, 100
Column2=[MSG_SENDER], 12, 100
Column3=[MSG_RECEIVER], 12, 100
Column4=[MSG_DATE], 12, 100
Column5=[MSG_CONTENT], 12, 100


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=RVTest.cpp
ImplementationFile=RVTest.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_RECORD_FIRST
Command15=ID_RECORD_PREV
Command16=ID_RECORD_NEXT
Command17=ID_RECORD_LAST
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_RVTEST_FORM]
Type=1
Class=CRVTestView
ControlCount=10
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_EDIT3,edit,1350631552
Control4=IDC_EDIT4,edit,1350631552
Control5=IDC_EDIT5,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_RECORD_FIRST
Command9=ID_RECORD_PREV
Command10=ID_RECORD_NEXT
Command11=ID_RECORD_LAST
Command12=ID_APP_ABOUT
CommandCount=12

