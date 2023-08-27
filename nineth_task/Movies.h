//
// Created by Daniil Slobodeniuk on 2023/08/12.
//

#ifndef LEARNINGC___MOVIES_H
#define LEARNINGC___MOVIES_H

#include "Movie.h"
#include "iostream"
#include "string"
#include "vector"

class Movies {
private:
    static std::vector<std::string> ratings;
    std::vector<Movie*> *movies;

public:
    static std::vector<std::string> get_ratings() {
        return ratings;
    }

    bool create_movie(std::string new_movie_name, std::string new_movie_rating, int new_movie_watch_count);

    void display_all_movies() const;


    Movies();

    Movies(const Movies &movies_source);

    Movies(Movies &&movies_source);

    ~Movies();

};


#endif //LEARNINGC___MOVIES_H
