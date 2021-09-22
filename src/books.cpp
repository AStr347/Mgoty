/**
 * V 16
 * «Книга»:
 * название; автор (фамилия; имя); год выхода; издательство; себестоимость; цена; прибыль. 
 * Вывести данные про книги авторов, фамилия которых начинается с буквы “К”
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
/* for output formated string use boost lib */
#include <boost/format.hpp>

using namespace std;

#define BOOK_LINE_MIN_LEN   16
#define BOOK_OUT_FORMAT     "%s|%s|%d|%s|%lf|%lf|%lf"

/* split string by delim */
vector<string> split(const string& s, const char c){
	vector<string> result;
	size_t start = 0U;
    size_t end = s.find(c);
    while (end != string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(c, start);
    }
    result.push_back(s.substr(start));
	return result;
}

class Author {
    string FirstName = "";
    string SecondName = "";

    /* first word - FirstName other words - SecondName*/
    bool fromString(const string&s) {
        bool result = false;
        vector<string> splited = split(s, ' ');
        if(splited.size() > 1){
            FirstName = splited[0];
            for(int i = 1; i < splited.size() - 1; i++){
                SecondName += splited[i] + " ";
            }
            SecondName += splited[splited.size() - 1];
            result = true;
        }
        return result;
    }

public:
    /* get func for dbg */
    string    getFirstName(void) const                { return FirstName; }
    string    getSecondName(void) const               { return SecondName; }
    /* func for get first symbol */
    const char      getFirstCharFromSecondName(void) const  { return SecondName.empty()? '\0' : toupper(SecondName[0]); }

    /* inits */
    Author() {};
    Author(const string s) { fromString(s); }
    Author(const string fn, const string sn) : FirstName(fn), SecondName(sn) {}

    /* create string */
    string toString(void) { return FirstName + " " + SecondName; }
};

class Book {
    string  Name = "";
    Author  author = Author();
    int     YearRelease = 0;
    string  PublisherName = "";
    double  CostPrice = 0.0;
    double  Price = 0.0;
    double  Profit = 0.0;

    /* try parce line to book */
    bool fromString(const string& s){
        bool result = false;
        vector<string> splited = split(s,'|');
        if(splited.size() > 6){
            Name = splited[0];
            author = Author(splited[1]);
            YearRelease = std::atoi(splited[2].c_str());
            PublisherName = splited[3];
            CostPrice = std::atof(splited[4].c_str());
            Price = std::atof(splited[5].c_str());
            Profit = std::atof(splited[6].c_str());
            result = true;
        }
        return result;
    }

public:
    /* get funcs for dbg */
    const string    getName(void)               { return Name; }
    const Author    getAuthor(void)             { return author; }
    const string    getAuthorFirstName(void)    { return author.getFirstName(); }
    const string    getAuthorSecondName(void)   { return author.getSecondName(); }
    const int       getYearRelease(void)        { return YearRelease; }
    const string    getPublisherName(void)      { return PublisherName; }
    const double    getCostPrice(void)          { return CostPrice; }
    const double    getPrice(void)              { return Price; }
    const double    getProfit(void)             { return Profit; }


    /* inits */
    Book() {};
    Book(const string in) { fromString(in); }
    Book(string bn, string fn, string sn, int year_rel, string pb, double cp, double p, double prof) : 
        Name(bn), author(fn, sn), YearRelease(year_rel), 
        PublisherName(pb), CostPrice(cp), Price(p), Profit(prof) 
    {}

    /* create current string for file */
    string toString(void){
        return (boost::format(BOOK_OUT_FORMAT) %
            getName() %
            author.toString() %
            YearRelease %
            getPublisherName() %
            CostPrice %
            Price %
            Profit
        ).str();
    }

    /* try parce file to books list */
    static vector<Book> fromFile(ifstream& inf){
        vector<Book> result;
        string line;
        while(getline(inf, line)){
            result.push_back(Book(line));
        }
        return result;
    }
};

/* main */
void books(void){
    char c = '\0';
    cout << "input symbol for filter Author Second name" << endl;
    cin >> c;
    c = toupper(c);

    string inpath;
    string outpath;
    cout << "input path" << endl;
    cin >> inpath;
    cout << "output path" << endl;
    cin >> outpath;
    
    /* read input file */
    ifstream inf(inpath);
    vector<Book> books = Book::fromFile(inf);
    inf.close();

    /* filter book.author.SecondName and fill output file */
    ofstream outf(outpath);
    for(auto& i : books){
        if(c == i.getAuthor().getFirstCharFromSecondName()){
            outf << i.toString() << endl;
        }
    }
    outf.close();
}


/* func for create currect file */
void create_books(void){
    string outpath;
    cin >> outpath;
    ofstream outf(outpath);
    Book books[] = {
        Book ("Quran", "Muhammad", "Prophet", 0, "Exmo", 0.0, 11000.0, 0.0),
        Book ("Bible", "", "", 0, "Matthew", 0.0, 46000.0, 0.0),
        Book ("Little Red Book", "Mao", "Zedong", 0, "Algorithm", 0.0, 333.0, 0.0),
        Book ("Don Quixote", "Miguel", "de Cervantes Saavedra", 0, "ABC", 0.0, 500.0, 0.0),
        Book ("A Tale of Two Cities", "Charles", "Dickens", 0, "", 0.0, 230.0, 0.0),
        Book ("The Lord of the Rings", "John", "Tolkien", 0, "", 0.0, 1500.0, 0.0),
        Book ("The Little Prince", "Antoine", "de Saint-Exupery", 0, "", 0.0, 2600.0, 0.0),
        Book ("Harry Potter and the Sorcerer's Stone", "Joan", "Rowling", 0, "", 0.0, 500.0, 0.0),
        Book ("The Hobbit, or There and Back", "John", "Tolkien", 0, "", 0.0, 1000.0, 0.0),
        Book ("Ten Little Indians", "Agatha", "Christie", 0, "", 0.0, 700.0, 0.0),
    };
    for (int i = 0; i < 10; i++){
        outf << books[i].toString() << endl;
    }
    outf.close();
}