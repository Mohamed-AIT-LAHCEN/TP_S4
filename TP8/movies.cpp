#include "Movies.h"
#include <iostream>

// Constructeur
Movies::Movies() {}

// Ajoute un film à la collection
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // Vérifie si le film existe déjà
    for (const auto &movie : movies) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    
    // Ajoute le nouveau film
    movies.push_back(Movie{name, rating, watched});
    return true;
}

// Incrémente le compteur de visionnage d'un film
bool Movies::increment_watched(std::string name) {
    for (auto &movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

// Affiche tous les films
void Movies::display() const {
    if (movies.empty()) {
        std::cout << "Désolé, aucun film à afficher" << std::endl;
    } else {
        std::cout << "===================================" << std::endl;
        for (const auto &movie : movies) {
            movie.display();
        }
        std::cout << "===================================" << std::endl;
    }
}
