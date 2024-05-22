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
	// ���� ī��Ʈ
	QueryPerformanceCounter(&m_llPrevCount);
	// �ʴ� ī��Ʈ
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);
	//���� �������� ī���ð�, ���� ������ ī������ ���� ���̸� ���Ѵ�.
	m_dDt = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	// ���� ī��Ʈ ���� ���簪���� ����(�������� ����� ���ؼ�)
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
