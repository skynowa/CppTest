/**
 * \file  ToPlain.cpp
 * \brief nlohmann::json
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <nlohmann/json.hpp>
//-------------------------------------------------------------------------------------------------
// Recursive function to convert JSON to plain text without removing HTML tags
std::string
jsonToPlainText(
    const nlohmann::json &a_json,
    const std::string    &a_indent = ""
)
{
    std::string result;

    const std::string nl = "\n";

    // If the current element is an object, iterate over its key-value pairs
    if      (a_json.is_object()) {
        for (auto it = a_json.begin(); it != a_json.end(); ++ it) {
            result += a_indent + it.key() + ":" + nl;
            result += jsonToPlainText(it.value(), a_indent + "  ");
        }
    }
    // If the current element is an array, iterate over its elements
    else if (a_json.is_array()) {
        for (const auto &item : a_json) {
            if (item.is_object() || item.is_array()) {
                result += jsonToPlainText(item, a_indent + "  ");
            }
            else if ( item.is_string() ) {
                result += a_indent + "  - " + item.get<std::string>() + nl;
            }
            else {
                result += a_indent + "  - " + item.dump() + nl;
            }
        }
    }
    // If the current element is a string, number, or boolean, print it directly
    else if (a_json.is_string()) {
        result += a_indent + a_json.get<std::string>() + nl;
    }
    else {
        result += a_indent + a_json.dump() + nl;  // For numbers and booleans
    }

    return result;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // JSON data as a string
    const std::string jsonString = R"({
        "paymentPolicy": {
            "localCurrency": "EUR",
            "propertyFees": [
                "<p>You'll be asked to pay the following charges at the property:<\/p>",
                "<ul><li>A tax is imposed by the city and collected at the property. Exemptions or reductions might apply. For more details, please contact the property using the information on the reservation confirmation received after booking. <\/li><li>An effective city/local tax rate of 5.00 percent will be charged<\/li><li>Deposit is payable by bank transfer and is due within 72 hours of booking the reservation.<\/li><\/ul>",
                "<p>We have included all charges provided to us by the property. <\/p>"
            ],
            "optionalExtras": [
                "<ul> <li>Fee for buffet breakfast: approximately EUR 23 for adults and EUR 11.5 for children<\/li><li>Self parking fee: EUR 22 per day<\/li><li>Nearby parking fee: EUR 13 per day (328 ft away)<\/li><li>Pet fee: EUR 20 per pet, per stay<\/li><li>Service animals are exempt from fees<\/li><\/ul>",
                "<p>The above list may not be comprehensive. Fees and deposits may not include tax and are subject to change. <\/p>"
            ]
        }
    })";

    std::cout << jsonString << "\n" << std::endl;

    // Parse JSON data
    nlohmann::json jsonData = nlohmann::json::parse(jsonString);

    // Convert JSON to plain text and print the result
    std::string plainText = jsonToPlainText(jsonData);
    std::cout << plainText << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

paymentPolicy:
  localCurrency:
    EUR
  optionalExtras:
      - <ul> <li>Fee for buffet breakfast: approximately EUR 23 for adults and EUR 11.5 for children</li><li>Self parking fee: EUR 22 per day</li><li>Nearby parking fee: EUR 13 per day (328 ft away)</li><li>Pet fee: EUR 20 per pet, per stay</li><li>Service animals are exempt from fees</li></ul>
      - <p>The above list may not be comprehensive. Fees and deposits may not include tax and are subject to change. </p>
  propertyFees:
      - <p>Youll be asked to pay the following charges at the property:</p>
      - <ul><li>A tax is imposed by the city and collected at the property. Exemptions or reductions might apply. For more details, please contact the property using the information on the reservation confirmation received after booking. </li><li>An effective city/local tax rate of 5.00 percent will be charged</li><li>Deposit is payable by bank transfer and is due within 72 hours of booking the reservation.</li></ul>
      - <p>We have included all charges provided to us by the property. </p>

#endif
