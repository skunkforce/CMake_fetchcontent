#include <iostream>
#include <CLI/CLI.hpp>

int main(int argc, char** argv){
	CLI::App app{"The Fetchcontent Example"};

	bool shoutout_flag{false};

	app.add_flag("-s, --shoutout", shoutout_flag, "Shouts out,... what else?");

	try
	{
		app.parse(argc, argv);
	} catch(const CLI::ParseError& e){
		return app.exit(e);
	}

	if(shoutout_flag){
		std::cout << "Shoutout!" << std::endl;
	}
	else{
		std::cout << "No shoutout :(" << std::endl;
	}
}
