
VODUsrMgrps.dll: dlldata.obj VODUsrMgr_p.obj VODUsrMgr_i.obj
	link /dll /out:VODUsrMgrps.dll /def:VODUsrMgrps.def /entry:DllMain dlldata.obj VODUsrMgr_p.obj VODUsrMgr_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del VODUsrMgrps.dll
	@del VODUsrMgrps.lib
	@del VODUsrMgrps.exp
	@del dlldata.obj
	@del VODUsrMgr_p.obj
	@del VODUsrMgr_i.obj
