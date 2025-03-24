#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int watched;
    
public:
    // Constructeur
    Movie(std::string name, std::string rating, int watched);
    
    // Getters
    std::string get_name() const;
    std::string get_rating() const;
    int get_watched() const;
    
    // Setters
    void set_name(std::string name);
    void set_rating(std::string rating);
    void set_watched(int watched);
    
    // Incrémente le compteur de visionnage
    void increment_watched();
    
    // Affiche les informations du film
    void display() const;
};

#endif // MOVIE_H
