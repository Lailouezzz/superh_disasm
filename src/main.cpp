#include <iostream>
#include <string>
#include <spiritx3.hpp>
#include "version.hpp"


int main()
{
#ifndef NDEBUG
    std::cout << "debug" << std::endl;
#endif
    std::cout << "version : " << VERSION_STR << std::endl;

    using spirit::_attr;
    using spirit::char_;
    using spirit::int_;

    std::string toParse;

    while(std::getline(std::cin, toParse))
    {
        if(toParse == "q")
            break;

        int n = 0;

        auto add = [&](auto& ctx) { n += _attr(ctx); };
        auto mul = [&](auto& ctx) { n *= _attr(ctx); };

        bool r = parse(toParse.begin(), 
                    toParse.end(), 

                        // BEGIN GRAMMAR

                    int_[add] >> 
                    *((
                        *char_(' ') >>
                        char_('+') >> 
                        *char_(' ') >> 
                        int_[add]
                    )
                    |
                    (
                        *char_(' ') >>
                        char_('*') >> 
                        *char_(' ') >> 
                        int_[mul]
                    )
                    )
                        // END GRAMMAR

                    );
        if(r)
            std::cout << "parsing success result : " << n << std::endl;
        else
            std::cout << "parsing fail" << std::endl;
    }
    return 0;
}