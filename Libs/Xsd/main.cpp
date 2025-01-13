#include <fstream>
#include <iostream>
#include "person.hxx"

int main() {
    try {
        // Parse the XML file to create a person object
        auto p = person::person_("person.xml");

        if (p) {
            // Display the parsed data
            std::cout << "Name: " << p->name() << "\n";
            std::cout << "Age: " << p->age() << "\n";

		#if 0
            // Serialize the person object to a file
            std::ofstream ofs("output.xml");
            if (!ofs) {
                throw std::runtime_error("Failed to open output file.");
            }

            // Serialize the object to the file
            person_(ofs, *p); // Generated function for serialization
            std::cout << "Person object written to output.xml\n";
		#endif
        }
    } catch (const xml_schema::exception& e) {
        std::cerr << "XML schema error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
