#include "pch.h"
#include "Ccore.h"

#include "CObject.h"



CObject g_obj;

//Ccore* Ccore::g_pInst = nullptr;
CCore::CCore()
	:m_hwnd(0)
	,m_ptResolution{}
	,m_hDC(0)
{
	
}

CCore::~CCore()
{
	ReleaseDC(m_hwnd, m_hDC);
}
int CCore::init(HWND _hwnd, POINT _ptResolution)
{
	m_hwnd = _hwnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = {0,0,m_ptResolution.x,m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hwnd, nullptr, 100,100,rt.right-rt.left,rt.bottom-rt.top,0);

	m_hDC = GetDC(m_hwnd);

	g_obj.m_ptPos = POINT{ m_ptResolution.x/2,m_ptResolution.y/2 };
	g_obj.m_ptScale = POINT{ 100,100 };

	return S_OK;
}

void CCore::progress()
{
	static int callcount = 0;
	++callcount;
	static int iPrevCount = GetTickCount();
	int iCurCount = GetTickCount();
	if (iCurCount - iPrevCount > 1000)
	{
		iPrevCount = iCurCount;
		callcount = 0;
	}


	Update();
	Render();
	// 그리기
	
}

void CCore::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		g_obj.m_ptPos.x -= 1;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_obj.m_ptPos.x += 1;
	}
	
}

void CCore::Render()
{
	Rectangle(m_hDC, g_obj.m_ptPos.x - g_obj.m_ptScale.x / 2,
					 g_obj.m_ptPos.y - g_obj.m_ptScale.y / 2,
					 g_obj.m_ptPos.x + g_obj.m_ptScale.x / 2,
					 g_obj.m_ptPos.y + g_obj.m_ptScale.y / 2);
}
