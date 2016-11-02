#pragma once
#include <memory>
#include <string>

class Settings {
	/*###############
	Constants that can be loaded from a file.
	Format:
		const [type] [domain][name] = [default value]
	#################*/
public:


	/* ###################
	Singleton Definition
	#####################*/
private:
	static std::shared_ptr<Settings> instance;

public:
	static std::shared_ptr<Settings> get();
};