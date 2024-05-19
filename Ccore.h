#pragma once

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능
/*
class Ccore
{
private:
	static Ccore* g_pInst;
public:
	// 정적 맴버함수, 객체없이 호출 가능, this 가 없다(맴버 접근 불가), 정적 맴버는 접근 가능
	static Ccore* GetInstance()
	{
		// 최초 호출된 경우
		if (nullptr == g_pInst)
		{
			g_pInst = new Ccore;
		}
		// 2번 이상 호출된 경우
		return g_pInst;
	}
	static void Release()
	{
		if (nullptr != g_pInst)
		{
			delete g_pInst;
			g_pInst = nullptr;
		}
	}
private:
	Ccore()
	{}
	~Ccore()
	{}
};
*/
class CCore
{

	SINGLE(CCore);
private:
	HWND	m_hwnd;				// 메인 윈도우 핸들
	POINT	m_ptResolution;		// 메인 윈도우 해상도
	HDC		m_hDC;				// 메인 윈도우 Draw 할 DC
public:
	int init(HWND	_hwnd, POINT	_ptResolution);
	void progress();
	void Update();
	void Render();

private:
	CCore();
	~CCore();
};


