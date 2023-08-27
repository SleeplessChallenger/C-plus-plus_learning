//
// Created by Daniil Slobodeniuk on 2023/08/12.
//

#include "Movies.h"

#include "iostream"
#include "string"
#include "vector"

std::vector<std::string> Movies::ratings = {"G", "PG", "PG-13", "R"};

Movies::Movies() {
    movies = new std::vector<Movie *>();
}

Movies::Movies(const Movies &movies_source)
        : movies{nullptr} {
    movies = new std::vector<Movie *>;
    movies->insert(movies->end(), movies_source.movies->begin(), movies_source.movies->end());
    std::cout << "Calling Copy Constructor" << std::endl;
}

Movies::Movies(Movies &&movies_source)
        : movies{movies_source.movies} {
    movies_source.movies = nullptr;
    std::cout << "Cleaning pointer in initial movies vector" << std::endl;
}

Movies::~Movies() {
    delete movies;
}

std::vector<Movie *> dereference_movie_vector(std::vector<Movie *> *v) {
    return (*v);
}

bool search_for_movie(const std::string new_movie_name, std::vector<Movie *> movieVector) {
    for (Movie *&movie: movieVector) {
        if ((*movie).get_movie_name() == new_movie_name) {
            std::cout << "Movie with name: " << new_movie_name << " exists" << std::endl;
            return false;
        }
    }
    return true;
}

bool check_rating_exist(std::string new_rating) {
    for (const std::string &rating: Movies::get_ratings()) {
        if (new_rating == rating) {
            return true;
        }
    }
    return false;
}

bool Movies::create_movie(std::string new_movie_name, std::string new_movie_rating, int new_movie_watch_count) {
    std::vector<Movie *> movieVector = dereference_movie_vector(movies);
    if (search_for_movie(new_movie_name, movieVector) && !check_rating_exist(new_movie_rating)) {
        return false;
    }

    Movie *movie = new Movie{new_movie_name, new_movie_rating};
    (*movie).set_watch_count(new_movie_watch_count);
    (*movies).push_back(movie);
    std::cout << "Exiting a method" << std::endl;

    movies->push_back(new Movie);
    return true;
}

void Movies::display_all_movies() const {
    std::vector<Movie *> movieVector = dereference_movie_vector(movies);
    for (Movie *&movie: movieVector) {
        (*movie).increment_watch_count();
        (*movie).display_movie();
    }
}
