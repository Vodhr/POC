#pragma once

class BasicPOCModule;

using namespace std;

class POCModuleComponent {
protected:
	BasicPOCModule* itsPOCModule;

private:
public:
	POCModuleComponent(BasicPOCModule* itsPOCModule) : itsPOCModule(itsPOCModule) {
		if(!this->itsPOCModule->getIsActive())
			this->itsPOCModule->activate();


		if (this->itsPOCModule->getIsActive()) {
			this->itsPOCModule->deactivate();
		}
	}
};
