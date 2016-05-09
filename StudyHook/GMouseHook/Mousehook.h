class AFX_EXT_CLASS Cmousehook:public CObject
{
public:
	Cmousehook();
	~Cmousehook();
	BOOL starthook(HWND hWnd);
	BOOL stophook();
}; 