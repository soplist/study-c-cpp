
VODMediaMgrps.dll: dlldata.obj VODMediaMgr_p.obj VODMediaMgr_i.obj
	link /dll /out:VODMediaMgrps.dll /def:VODMediaMgrps.def /entry:DllMain dlldata.obj VODMediaMgr_p.obj VODMediaMgr_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del VODMediaMgrps.dll
	@del VODMediaMgrps.lib
	@del VODMediaMgrps.exp
	@del dlldata.obj
	@del VODMediaMgr_p.obj
	@del VODMediaMgr_i.obj
