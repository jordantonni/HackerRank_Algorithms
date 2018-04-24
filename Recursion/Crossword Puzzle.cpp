// https://www.hackerrank.com/challenges/crossword-puzzle/problem
// Jordan Tonni

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

enum class direction
{
    DOWN,
    RIGHT
};

struct location
{
    struct pos
    {
        int x;
        int y;
    };

    pos position;
    size_t len;
    direction dir;

    explicit location(const pos& p, const size_t l, const direction d)
        : position{ p }
        , len{ l }
        , dir{ d }
    {}
};

vector<vector<char> > matrix;
vector<location> locations;
vector<string> words;
unordered_set<string> wordsUsed;

void init()
{
    matrix = vector<vector<char> >(10, vector<char>(10));

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> matrix[i][j];
        }
    }
}

vector<string> getWords()
{
    string word;
    while(cin.peek() == '\n')
        cin.ignore();

    while(getline(cin, word, ';')){
        if(word.at(word.length() - 1) == '\n')
            words.push_back(word.substr(0, word.length() - 1));
        else
            words.push_back(word);
    }

    return words;
}

void getLocationType(int x, int y)
{
     // Down word Start Location
        if(x + 1 < 10){
            if((x - 1 < 0 || matrix[x - 1][y] == '+') && matrix[x + 1][y] == '-'){
                int tempX = x;
                size_t len = 0;
                while(tempX < matrix.size() && matrix[tempX][y] == '-'){
                    ++len;
                    ++tempX;
                }

                location loc { location::pos { x,y }, len, direction::DOWN };
                locations.emplace_back(loc);
            }
        }

        // Right word Start Location
        if(y + 1 < 10){
            if((y - 1 < 0 || matrix[x][y - 1] == '+') && matrix[x][y + 1] == '-' && y + 1 << matrix.size()){
                int tempY = y;
                size_t len = 0;
                while(tempY < matrix[x].size() && matrix[x][tempY] == '-'){
                    ++len;
                    ++tempY;
                }
                location loc { location::pos { x,y }, len, direction::RIGHT };
                locations.emplace_back(loc);
            }
        }
}

vector<location> getLocations()
{
    vector<location> locations;

    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] == '+')
                continue;
            if(matrix[i][j] == '-'){
                getLocationType(i, j);
            }
        }
    }
    return locations;
}

bool checkDown(const location& loc, const string& word)
{
    for(int i = loc.position.x,j = 0; i < loc.position.x + loc.len; ++i, ++j){
        if(matrix[i][loc.position.y] != word[j] && matrix[i][loc.position.y] != '-')
            return false;
    }
    return true;
}

bool checkRight(const location& loc, const string& word)
{
    for(int i = loc.position.y,j = 0; i < loc.position.y + loc.len; ++i, ++j){
        if(matrix[loc.position.x][i] != word[j] && matrix[loc.position.x][i] != '-')
            return false;
    }
    return true;
}

bool canPlaceHere(const location& loc, const string& word)
{
    if(wordsUsed.find(word) != end(wordsUsed))
        return false;

    if(word.size() == loc.len){
        if(matrix[loc.position.x][loc.position.y] == '-'){
            if(loc.dir == direction::DOWN)
                return checkDown(loc, word);
            return checkRight(loc, word);
        }
        if(matrix[loc.position.x][loc.position.y] == word.at(0))
            return true;
    }
    return false;
}

void placeWord(const location& loc, const string& word)
{
    if(loc.dir == direction::DOWN){
        const int x = loc.position.x;
        for(int i = x,j = 0; j < word.length(); ++i, ++j){
            matrix[i][loc.position.y] = word.at(j);
        }
    }
    if(loc.dir == direction::RIGHT){
        const int y = loc.position.y;
        for(int i = y,j = 0; j < word.length(); ++i, ++j){
            matrix[loc.position.x][i] = word.at(j);
        }
    }

    wordsUsed.insert(word);
}

void removeWord(const location& loc)
{
    if(loc.dir == direction::DOWN){
        for(int i = loc.position.x; i < loc.position.x + loc.len; ++i){
            matrix[i][loc.position.y] = '-';
        }
    }
    if(loc.dir == direction::RIGHT){
        for(int i = loc.position.y; i < loc.position.y + loc.len; ++i){
            matrix[loc.position.x][i] = '-';
        }
    }
}

bool recur()
{
    // Success, all words placed
    if(wordsUsed.size() >= words.size())
        return true;

    for(int i = 0; i < words.size(); ++i){
        for(int j = 0; j < locations.size(); ++j){
            if(canPlaceHere(locations[j], words[i])){
                placeWord(locations[j], words[i]);
                if(recur() == true)
                    return true;
                else{
                    removeWord(locations[j]);
                    wordsUsed.erase(words[i]);
                }
            }
        }
    }
    return false;
}

void printMatrix()
{
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    init();
    getWords();
    getLocations();

    recur();
    printMatrix();
}
