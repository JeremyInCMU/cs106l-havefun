/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Lilly Hunter"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::fstream file_stream(filename);
  std::set<std::string> ret;
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      ret.insert(line);
    }
  }
  return ret;
}

bool has_same_initials(std::string name, std::string candidate) {
  if (name[0] != candidate[0]) {
    return false;
  }
  auto pos_name = name.find(' ');
  auto pos_candidate = candidate.find(' ');
  if (name[pos_name + 1] != candidate[pos_candidate + 1]) {
    return false;
  }
  return true;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> ret;
  for (auto iter = students.begin(); iter != students.end(); ++iter) {
    if (has_same_initials(name, *iter)) {
      ret.push(&*iter);
    }
  }

  return ret;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  int cnt = 0;
  std::string true_love;
  while (!matches.empty()) {
    true_love = *matches.front();
    matches.pop();
    cnt++;

    if (cnt % 5 == 0) {
      return true_love;
    }
  }
  return "No MATCHES FOUND.";
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
