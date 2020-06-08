#include "POCModuleComponent.h"
#include "BasicPOCModule.h"

POCModuleComponent::POCModuleComponent(BasicPOCModule* itsPOCModule, list<POCModuleComponent*>& componentList) : itsPOCModule(itsPOCModule) {
	componentList.push_back(this);
}

POCModuleComponent::~POCModuleComponent() {

}