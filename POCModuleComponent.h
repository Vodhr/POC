#pragma once

class BasicPOCModule;

using namespace std;

class POCModuleComponent {
protected:
	BasicPOCModule* itsPOCModule;

private:
public:
	POCModuleComponent(BasicPOCModule* itsPOCModule);
};
