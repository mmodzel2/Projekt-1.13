#ifndef _PLAYER_H
#define _PLAYER_H

class player {
private:
    char* name_;
    char* surname_;
    unsigned char day_of_birth_; //player birth date
    unsigned char month_of_birth_;
    unsigned short year_of_birth_;

    unsigned long int cost_; //cost of the player
    char* country_;

    unsigned char wage_;
    unsigned char growth_;

    unsigned int goals_; //goals count
    unsigned int assists_; //assists count
    unsigned int matches_; //matches_count
    unsigned int red_cards_; //red_cards count
    unsigned int yellow_cards_; //yellow_cards count
public:
    player(const char* name, const char* surname, const char* date_of_birth, const char* country);
    player(const char* name, const char* surname, const char* date_of_birth, const char* country, unsigned long int cost);
    player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth);
    player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, unsigned long int cost);
    player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists);
    player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists, const unsigned int red_cards, const unsigned int yellow_cards);
    player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists, unsigned long int cost);
    player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists, const unsigned int red_cards, const unsigned int yellow_cards, unsigned long int cost);
    ~player();

    void set_cost(unsigned long int cost);
    void set_wage(unsigned char wage);
    void set_assists(unsigned int assists);
    void set_goals(unsigned int goals);
    void set_matches(unsigned int matches);
    void set_red_cards(unsigned int red_cards);
    void set_yellow_cards(unsigned int yellow_cards);

    char* get_name() const;
    char* get_surname() const;
    char* get_country() const;

    unsigned char get_day_of_birth() const; //get player birth date
    unsigned char get_month_of_birth() const;
    unsigned short get_year_of_birth() const;

    unsigned long int get_cost() const;
    unsigned char get_wage() const;
    unsigned int get_goals() const;
    unsigned int get_assists() const;
    unsigned int get_matches() const;
    unsigned int get_red_cards() const;
    unsigned int get_yellow_cards() const;

    void add_goals(unsigned int goals_to_add);
    void add_assists(unsigned int assists_to_add);
    void add_matches(unsigned int matches_to_add);
    void add_red_cards(unsigned int red_cards_to_add);
    void add_yellow_cards(unsigned int yellow_cards_to_add);
    void add_goals(); //Increment functions
    void add_assists();
    void add_matches();
    void add_red_cards();
    void add_yellow_cards();
};

#endif
