#pragma once
#include "Vector.h"
#include "Event.h"
#include <iostream>

class Dialog :
	public Vector
{
public:
	//конструктор без параметров
	Dialog();
public:
	//деструктор
	virtual ~Dialog(); 

	//получить событие
	virtual void GetEvent(TEvent& event); 
	//главный цикл обработки событий
	virtual int Execute(); 
	//очистить событие
	virtual void HandleEvent(TEvent& event); 
	//проверека атрибута EndState
	virtual void ClearEvent(TEvent& event); 

	//обработка события "конец работы"
	int Valid(); 
	void EndExec();

protected:
	int EndState;
};

