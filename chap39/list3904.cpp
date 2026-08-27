/** Listing 39-4. Adding a Class movie */
#include <iostream>
#include <vector>
#include <memory>

class work {
public:
    work() = default;
    work(work const &) = default;
    work(std::string_view id, std::string_view title): id_ { id }, title_ { title } { }
    virtual ~work() { }
    std::string const &id() const { return id_; }
    std::string const &title() const { return title_; }
    virtual void print(std::ostream &) const { }

private:
    std::string id_;
    std::string title_;
};

class book : public work {
public:
    book(): work {}, author_ {}, pubyear_ { 0 } { }
    book(book const &) = default;
    book(std::string_view id, std::string_view title, std::string_view author, int pubyear): work { id, title }, author_ { author }, pubyear_ { pubyear } { }
    std::string const &author() const { return author_; }
    int pubyear() const { return pubyear_; }
    void print(std::ostream &out) const override { out << author() << ", " << title() << ", " << pubyear() << "."; }

private:
    std::string author_;
    int pubyear_; ///< year of publication
};

class periodical : public work {
public:
    periodical(): work {}, volume_ { 0 }, number_ { 0 }, date_ {} { }
    periodical(periodical const &) = default;
    periodical(std::string_view id, std::string_view title, int volume, int number, std::string_view date): work { id, title }, volume_ { volume }, number_ { number }, date_ { date } { }
    int volume() const { return volume_; }
    int number() const { return number_; }
    std::string const &date() const { return date_; }
    void print(std::ostream &out) const override { out << title() << ", " << volume() << '(' << number() << "), " << date() << "."; }

private:
    int volume_; ///< volume number
    int number_; ///< issue number
    std::string date_; ///< publication date
};

class movie : public work {
public:
    movie(): work {}, runtime_ { 0 } { }
    movie(movie const &) = default;
    movie(std::string_view id, std::string_view title, int runtime): work { id, title }, runtime_ { runtime } { }
    int runtime() const { return runtime_; }

private:
    int runtime_; ///< running length in minutes
};

int
main()
{
    std::vector<std::unique_ptr<work>> vec;
    vec.push_back(std::make_unique<book>("11", "book12", "LiXiaqin", 2026));
    vec.push_back(std::make_unique<periodical>("21", "periodical22", 23, 24, "2026-08-28"));
    for (auto const &i : vec) {
        i->print(std::cout);
        std::cout << "n";
    }
    return 0;
}
