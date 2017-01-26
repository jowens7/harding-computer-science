/**
 * Tree project for Coach Ragsdale
 * Jerred Shepherd
 * 12/6/2016
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tree.h"

bool debug = false;

/**
 * This function will take a string and find the individual words it contains
 * Words contain only alphabetical characters; any non-alphabetical characters are stripped
 * @param line A string to look for words in
 * @return A vector of individual words
 */
std::vector<std::string> extractWords(std::string line) {
    std::vector<std::string> lineWords;
    long lastWordEnd = 0;
    // We need to ensure there is a non-character at the end of every line
    if (!line.empty() && line[line.size() - 1] != '\r') {
        line.append("/");
    }
    for (int i = 0; i < line.length(); i++) {
        char c = line.at(i);
        if (isalpha(c)) {
            continue;
        } else {
            std::string word = line.substr(lastWordEnd, i - lastWordEnd);
            lastWordEnd = i + 1;
            if (word.length() == 0) {
                continue;
            } else {
                lineWords.push_back(word);
            }
        }
    }
    return lineWords;
}


/**
 * This function will create a tree of words from an input file
 * @param fileName A text file to load words from
 * @param tree A tree object for the words to be inserted into
 *
 */
void createTree(std::string fileName, Tree *tree) {
    std::ifstream inputFile(fileName);
    std::vector<std::string> allWords;

    if (!inputFile.good()) {
        std::cout << "Invalid input file! Exiting" << std::endl;
        exit(0);
    }

    std::cout << fileName << " exists! Creating tree" << std::endl;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> lineWords = extractWords(line);
        allWords.insert(allWords.end(), lineWords.begin(), lineWords.end());
        lineWords.clear();
    }

    inputFile.close();

    for (std::string s : allWords) {
        for (auto &c : s) {
            c = toupper(c);
        }
        tree->insertNode(s);
        if (debug == true) {
            std::cout << s << std::endl;
        }
    }
}

/**
 * Print out a tree to a file
 * @param fileName The file to print to
 * @param tree The tree to print
 */
void print(std::string fileName, Tree* tree) {
    std::ofstream outputFile(fileName);

    if (!outputFile.good()) {
        std::cout << "Error with output file! Exiting" << std::endl;
        exit(0);
    }

    tree->printTree(outputFile, NULL);

    if (debug) {
        tree->printTreeInOrder(outputFile, NULL, 0);
    }

    outputFile.close();
}

/**
 * Allow a user to input nodes to delete
 * @param tree The tree to delete from
 */
void deleteNodes(Tree* tree) {
    std::string input;

    do {
        std::cout << "Enter a word to delete from the tree, or type _exit to stop: ";
        std::cin >> input;
        if (input == "_exit") {
            continue;
        }

        for (auto &c : input) {
            c = toupper(c);
        }

        Node* node = tree->findNode(input);

        if (node != NULL) {
            tree->deleteNode(node);
            std::cout << "Node deleted" << std::endl;
        } else {
            std::cout << "Node not found" << std::endl;
        }

    } while (input != "_exit");

}

/**
 * The main function
 * Get an input file from the user and create a tree from its contents, allow the user to delete items from the tree
 * and lastly print the tree to an output file
 */
int main() {
    std::string fileName;
    Tree *tree = new Tree();

    std::cout << "Enter a text file to read" << std::endl;
    std::cout << "Do not enter a file extension" << std::endl;
    std::cin >> fileName;

    createTree(fileName + ".txt", tree);

    std::cout << "There are " << tree->getNodeCount() << " nodes in this tree" << std::endl;
    std::cout << "The height of this tree is " << tree->getHeight() << std::endl;

    deleteNodes(tree);

    print(fileName + ".frq", tree);

    delete tree;

    return 0;
}