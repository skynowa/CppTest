/**
 * \file  RecursiveIterate.cpp
 * \brief nlohmann::json
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <nlohmann/json.hpp>
//--------------------------------------------------------------------------------------------------
using json = nlohmann::json;

template<class UnaryFunction>
void
recursive_iterate(
    const json    &a_json,
    UnaryFunction  a_func
)
{
    for (auto it = a_json.cbegin(); it != a_json.cend(); ++ it) {
        if ( it->is_structured() ) {
            recursive_iterate(*it, a_func);
        } else {
            a_func(it);
        }
    }
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // std::cout
    if (0) {
        json j = R"({
            "Assets": [
                {
                    "Asset": {
                        "File": "assets/music/Music.wav",
                        "Name": "Music",
                        "Type": 3
                    }
                },
                {
                    "Asset": {
                        "File": "assets/images/Image.png",
                        "Name": "Success",
                        "Type": 1
                    }
                }
            ],
            "Layer": {
                "Asset": {
                    "File": "assets/data/sub.json",
                    "Name": "File",
                    "Type": 0
                }
            }
        })"_json;

        auto pred = [](json::const_iterator it) -> void
        {
            std::cout << it.key() << " : " << it.value() << std::endl;
        };

        recursive_iterate(j, pred);
    }

    // str
    {
        json j = R"({
            "checkInStartTime": "3:00 PM",
            "checkOutTime": "10:00 AM",
            "checkInPolicy": [
                "Check-in time starts at 3:00 PM",
                "Minimum check-in age: 25 "
            ],
            "checkOutPolicy": [
                "Check-out before 10:00 AM"
            ],
            "minimumAge": "25",
            "petPolicy": [
                "Pets not allowed"
            ],
            "childrenAndExtraBedPolicy": [
                "<ul><li>Children are welcome.<\/li><\/ul>"
            ],
            "checkInInstructions": [
                "You will receive an email from the host with check-in and check-out instructions"
            ],
            "specialInstructions": [
                "Extra-person charges may apply and vary depending on property policy",
                "Government-issued photo identification and a credit card, debit card, or cash deposit may be required at check-in for incidental charges",
                "Onsite parties or group events are strictly prohibited",
                "Safety features at this property include a fire extinguisher and a smoke detector",
                "Special requests are subject to availability upon check-in and may incur additional charges; special requests cannot be guaranteed",
                "This property is managed through our partner, Vrbo. You will receive an email from Vrbo with a link to a Vrbo account, where you can change or cancel your reservation"
            ],
            "paymentPolicy": {
                "localCurrency": "USD"
            }
        })"_json;

        std::string str;

        auto pred = [&](json::const_iterator it) -> void
        {
            std::stringstream ss;

            const std::string key = it->is_string() ? "[n/a]" : it.key();

            ss << key << " : " << it.value() << std::endl;

            str += ss.str();
        };

        recursive_iterate(j, pred);
        std::cout << str << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

File : "assets/music/Music.wav"
Name : "Music"
Type : 3

File : "assets/images/Image.png"
Name : "Success"
Type : 1

File : "assets/data/sub.json"
Name : "File"
Type : 0

#endif
