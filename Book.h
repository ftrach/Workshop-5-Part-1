#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>
#include <fstream> // Add this include for file input

namespace sdds {

    class Book {
        std::string m_author;
        std::string m_title;
        std::string m_country;
        size_t m_year;
        double m_price;
        std::string m_description;

    public:
        Book();
        Book(const std::string& strBook);
        Book(std::ifstream& file); // Declaration of the new constructor

        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();

        friend std::ostream& operator<<(std::ostream& os, const Book& book);

    private:
        void trim(std::string& str);
    };

} // namespace sdds

#endif // SDDS_BOOK_H