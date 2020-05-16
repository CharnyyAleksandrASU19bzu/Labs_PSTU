#pragma once
#include "Vector.h"
#include "Event.h"
#include <iostream>

class Dialog :
	public Vector
{
public:
	//����������� ��� ����������
	Dialog();
public:
	//����������
	virtual ~Dialog(); 

	//�������� �������
	virtual void GetEvent(TEvent& event); 
	//������� ���� ��������� �������
	virtual int Execute(); 
	//�������� �������
	virtual void HandleEvent(TEvent& event); 
	//��������� �������� EndState
	virtual void ClearEvent(TEvent& event); 

	//��������� ������� "����� ������"
	int Valid(); 
	void EndExec();

protected:
	int EndState;
};

