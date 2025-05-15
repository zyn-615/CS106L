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
#include <sstream>
#include <array>

std::string kYourName = "Z Yn"; // Don't forget to change this!

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
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream inFile(filename);
  std::string name;
  std::unordered_set<std::string> nameSet;

  while (std::getline(inFile, name)) {
    nameSet.insert(name);
  }

  return nameSet;
}

std::array <std::string, 2> parseName(std::string name) {
  std::istringstream nameStream(name);
  std::array <std::string, 2> res;
  
  nameStream >> res[0] >> res[1];
  return res;
}

bool checkNameInitial(std::string name1, std::string name2) {
  return name1.at(0) == name2.at(0);
}

bool checkFullName(std::string nameOne, std::string nameTwo) {
  auto [oneFirstName, oneLastName] = parseName(nameOne);
  auto [twoFirstName, twoLastName] = parseName(nameTwo);
  return checkNameInitial(oneFirstName, twoFirstName) && checkNameInitial(oneLastName, twoLastName);
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue <const std::string*> find_matches(std::string name, std::unordered_set <std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue <const std::string*> matchedName;
  for (const auto& nameInSet : students) {
    if (checkFullName(nameInSet, name)) {
      matchedName.emplace(&nameInSet);
    }
  }

  return matchedName;
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
std::string get_match(std::queue <const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }

  const std::string* match = matches.front();
  matches.pop();
  return *match;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
