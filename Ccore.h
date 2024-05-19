#pragma once

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����
/*
class Ccore
{
private:
	static Ccore* g_pInst;
public:
	// ���� �ɹ��Լ�, ��ü���� ȣ�� ����, this �� ����(�ɹ� ���� �Ұ�), ���� �ɹ��� ���� ����
	static Ccore* GetInstance()
	{
		// ���� ȣ��� ���
		if (nullptr == g_pInst)
		{
			g_pInst = new Ccore;
		}
		// 2�� �̻� ȣ��� ���
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
	HWND	m_hwnd;				// ���� ������ �ڵ�
	POINT	m_ptResolution;		// ���� ������ �ػ�
	HDC		m_hDC;				// ���� ������ Draw �� DC
public:
	int init(HWND	_hwnd, POINT	_ptResolution);
	void progress();
	void Update();
	void Render();

private:
	CCore();
	~CCore();
};


