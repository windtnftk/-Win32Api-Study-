#include "pch.h"
#include "CTimeMgr.h"
#include "Ccore.h"

CTimeMgr::CTimeMgr()
	:m_llCurCount{}
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDt(0.)
	, m_dAcc(0.)
	, m_iCallCount(0)
{

}
CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);
	// 초당 카운트
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);
	//이전 프레임의 카운팅과, 현재 프레임 카운팅의 값의 차이를 구한다.
	m_dDt = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	// 이전 카운트 값을 현재값으로 갱신(다음번의 계산을 위해서)
	m_llPrevCount = m_llCurCount;

	++m_iCallCount;

	m_dAcc += m_dDt;

	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT: %f", m_iFPS, m_dDt);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
