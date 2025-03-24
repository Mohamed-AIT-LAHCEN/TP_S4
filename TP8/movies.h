#ifndef MOVIES_H
#define MOVIES_H

#include <vector>
#include "Movie.h"

class Movies {
private:
    std::vector<Movie> movies;
    
public:
    // Constructeur
    Movies();
    
    // Ajoute un film à la collection
    bool add_movie(std::string name, std::string rating, int watched);
    
    // Incrémente le compteur de visionnage d'un film
    bool increment_watched(std::string name);
    
    // Affiche tous les films
    void display() const;
};

#endif // MOVIES_H
