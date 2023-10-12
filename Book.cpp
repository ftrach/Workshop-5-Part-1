#include "Book.h"
#include <sstream>
#include <iomanip>

namespace sdds {

    Book::Book() : m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_description("") {}

    Book::Book(const std::string& strBook) {
        std::istringstream ss(strBook);
        std::string author, title, country, price, year, description;
        std::getline(ss, author, ',');
        std::getline(ss, title, ',');
        std::getline(ss, country, ',');
        std::getline(ss, price, ',');
        std::getline(ss, year, ',');
        std::getline(ss, description);

        m_author = author;
        m_title = title;
        m_country = country;
        m_price = std::stod(price);
        m_year = std::stoi(year);
        m_description = description;
    }

    const std::string& Book::title() const {
        return m_title;
    }

    const std::string& Book::country() const {
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        return m_price;
    }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::setw(20) << std::left << book.m_author << " | ";
        os << std::setw(22) << std::left << book.m_title << " | ";
        os << std::setw(5) << std::left << book.m_country << " | ";
        os << std::setw(4) << book.m_year << " | ";
        os << std::fixed << std::setprecision(2) << std::setw(6) << book.m_price << " | ";
        os << book.m_description;
        return os;
    }

} // namespace sdds