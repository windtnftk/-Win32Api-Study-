#include "pch.h"
#include "Ccore.h"
#include "CTimeMgr.h"
#include "CObject.h"
#include "CkeyMgr.h"


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

	// Manager 초기화
	CTimeMgr::GetInst()->init();
	CkeyMgr::GetInst()->init();

	g_obj.SetPos(Vec2 ((float)m_ptResolution.x / 2, (float) m_ptResolution.y / 2 ));
	g_obj.SetScale(Vec2(100,100));

	return S_OK;
}

void CCore::progress()
{
	CTimeMgr::GetInst()->update();

	Update();
	Render();
	// 그리기
	
}

void CCore::Update()
{
	Vec2 vPos = g_obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 200.f * CTimeMgr::GetInst()->GetfDT();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 200.f * CTimeMgr::GetInst()->GetfDT();
	}
	g_obj.SetPos(vPos);
}

void CCore::Render()
{
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();
	Rectangle(m_hDC, int(vPos.x - vScale.x / 2.f),
					 int(vPos.y - vScale.y / 2.f),
				 	 int(vPos.x + vScale.x / 2.f),
					 int(vPos.y + vScale.y / 2.f));
}
