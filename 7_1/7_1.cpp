#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
void toLowerCase(char *str)
{
    for (int i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);
}

// Function to check if two words are equal
bool areEqual(const char *word1, const char *word2)
{
    return strcmp(word1, word2) == 0;
}

int main()
{
    const int MAX_PARAGRAPH_LENGTH = 1000;

    // Read the entire paragraph as a single line
    char paragraph[MAX_PARAGRAPH_LENGTH];
    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX_PARAGRAPH_LENGTH);

    // Convert the paragraph to lowercase for case-insensitive comparison
    toLowerCase(paragraph);

    // Dynamic arrays to hold words and their counts
    char **wordList = nullptr;
    int *wordCount = nullptr;
    int wordCapacity = 10; // Initial capacity
    int wordSize = 0;      // Number of unique words

    // Allocate initial memory
    wordList = new char *[wordCapacity];
    wordCount = new int[wordCapacity];

    // Tokenize paragraph into words using delimiters
    const char *delimiters = " ,.;:!?\"'\n\t";
    char *token = strtok(paragraph, delimiters);

    while (token != nullptr)
    {
        bool found = false;

        // Check if the word already exists in wordList
        for (int i = 0; i < wordSize; ++i)
        {
            if (areEqual(wordList[i], token))
            {
                wordCount[i]++;
                found = true;
                break;
            }
        }

        // If not found, add it to the wordList
        if (!found)
        {
            // Expand memory if needed
            if (wordSize >= wordCapacity)
            {
                wordCapacity *= 2;

                // Create new larger arrays
                char **newWordList = new char *[wordCapacity];
                int *newWordCount = new int[wordCapacity];

                // Copy existing data to new arrays
                for (int i = 0; i < wordSize; ++i)
                {
                    newWordList[i] = wordList[i];
                    newWordCount[i] = wordCount[i];
                }

                // Deallocate old arrays
                delete[] wordList;
                delete[] wordCount;

                // Point to new arrays
                wordList = newWordList;
                wordCount = newWordCount;
            }

            // Add new word
            wordList[wordSize] = new char[strlen(token) + 1];
            strcpy(wordList[wordSize], token);
            wordCount[wordSize] = 1;
            wordSize++;
        }

        token = strtok(nullptr, delimiters);
    }

    // Display word frequencies
    cout << "\nWord Frequency Count:\n";
    for (int i = 0; i < wordSize; ++i)
    {
        cout << wordList[i] << " : " << wordCount[i] << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < wordSize; ++i)
    {
        delete[] wordList[i];
    }
    delete[] wordList;
    delete[] wordCount;

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}