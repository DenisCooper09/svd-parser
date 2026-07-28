#include <fstream>
#include <iostream>
#include <vector>
#include <rapidxml/rapidxml.hpp>

int main()
{
    std::ifstream svd("../../test/STM32F103.svd");

    std::vector buffer((std::istreambuf_iterator(svd)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    rapidxml::xml_document doc;
    doc.parse<0>(buffer.data());

    auto* root = doc.first_node("device");
    auto* name = root->first_node("name");
    std::cout << name->value() << '\n';

    return 0;
}
