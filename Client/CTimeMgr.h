#pragma once

class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;

	
	double		m_dDt;			// 프레임 간의 시간값
	double		m_dAcc;			// 1초 체크를 위한 누적 시간
	UINT		m_iCallCount;	// 초당 호출 횟수 체크
	UINT		m_iFPS;			// 초당 호출 횟수
public:
	void init();
	void update();

public:
	double GetDT() { return m_dDt; }
	float GetfDT() { return (float)m_dDt; }

	
};

