#include "Settings.h"

std::shared_ptr<Settings> Settings::instance;

std::shared_ptr<Settings> Settings::get() {
	if (instance) {
		return std::shared_ptr<Settings>(instance);
	}
	else {
		instance = std::shared_ptr<Settings>(new Settings());
		return instance;
	}
}