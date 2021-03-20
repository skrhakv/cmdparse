#include <string>
#include <map>

namespace cmdparse {
    class ArgumentBase {
    };

    template <typename T>
    class Argument : public ArgumentBase {
    private:
        std::string long_name;
        std::string short_name;
        std::string help;
        bool required;
        T value;
    public:
        ~Argument();
        Argument(std::string long_name s, std::string short_name, T value, std::string help = "", bool required = true);
        Argument(const Argument& a) = delete;
        Argument& operator=(const MyArray& a) = delete;
        Argument(Argument&& a) = delete;
        Argument& operator=(Argument&& a) = delete;
        bool is_required() const;
        string get_help() const;
        string get_short_name() const;
        string get_long_name() const;
    };

    class cmdparser {
    private:
        std::map<std::string, ArgumentBase*> options;
    public:
        template <typename T> 
        Argument<T> get_argument(std::string/*&*/ s) const;
        template <typename T>
        void add_argument(std::string a1, Argument<T>/*&*/ a);
        void parse_arguments(int argc, char * argv[]);         
    };
}
