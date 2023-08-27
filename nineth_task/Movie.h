//
// Created by Daniil Slobodeniuk on 2023/08/12.
//

#ifndef LEARNINGC___MOVIE_H
#define LEARNINGC___MOVIE_H

#include "iostream"
#include "string"

class Movie {
private:
    static int watched;
    std::string movie_name;
    std::string movie_rating;

public:
    static int get_watched_times();

    std::string get_movie_name() const;

    std::string get_movie_rating() const;

    void set_watch_count(int new_watch_count);

    void set_movie_name(std::string new_movie_name);

    void set_movie_rating(std::string new_movie_rating);

    void increment_watch_count();

    void display_movie() const;

    Movie();

    Movie(std::string new_movie_name, std::string new_movie_rating);

    Movie(const Movie &movie_source);

    ~Movie();
};


#endif //LEARNINGC___MOVIE_H
