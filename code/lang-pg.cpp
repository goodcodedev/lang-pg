#include "TestLang.hpp"
#include <string>

using std::string;

int main() {
	string testFile = string(PROJECT_ROOT) + "/code/lang.test";
	auto result = Loader::parseFile(testFile);
	return 0;
}