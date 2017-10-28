#include "LangData.hpp"
using namespace LangData;

int main() {
	genFiles(string(PROJECT_ROOT) + "/code", "TestLang");
    return 0;
}