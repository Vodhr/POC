#pragma once
#include <list>

class BasicPOCModule;

using namespace std;

class POCModuleComponent {
protected:
	BasicPOCModule* itsPOCModule;

private:
public:
	POCModuleComponent(BasicPOCModule* itsPOCModule, list<POCModuleComponent*>& componentList);
	virtual ~POCModuleComponent();
};
