//
// Created by Daniil Slobodeniuk on 2023/08/12.
//

#include "Movie.h"
#include "string"

int Movie::watched = 0;

int Movie::get_watched_times() {
    return watched;
}

std::string Movie::get_movie_name() const {
    return movie_name;
}

std::string Movie::get_movie_rating() const {
    return movie_rating;
}

void Movie::set_movie_name(std::string new_movie_name) {
    movie_name = new_movie_name;
}

void Movie::set_movie_rating(std::string new_movie_rating) {
    movie_rating = new_movie_rating;
}

void Movie::set_watch_count(int new_watch_count) {
    watched += new_watch_count;
}

void Movie::increment_watch_count() {
    watched++;
}

void Movie::display_movie() const {
    std::cout << movie_name << ", " << movie_rating << ", " << watched << std::endl;
}

Movie::Movie()
        : Movie{"Default", "R"} {

}

Movie::Movie(std::string new_movie_name, std::string new_movie_rating)
        : movie_name{new_movie_name}, movie_rating{new_movie_rating} {
    std::cout << "Movie constructor for: " << new_movie_name << " has been called" << std::endl;
}

/**
 * For example using direct allocation instead of Delegating Constructor
 */
Movie::Movie(const Movie &movie_source)
        : movie_rating{"-"}, movie_name{"STUB"} {
    movie_name = movie_source.movie_name;
    movie_rating = movie_source.movie_rating;
    std::cout << "Movie Copy Constructor for: " << movie_source.movie_name << " has been called" << std::endl;
}

Movie::~Movie() {
    std::cout << "Calling destructor for: " << movie_name << std::endl;
}